//
// Created by pawel on 03.02.2023.
//

#include "Table.h"

#include <utility>

namespace Storage {
    bool Table::add_row(std::vector<std::string> row) {
        if ((this->row_count == 0) or (row.size() == this->columns_count)) {
            this->content.push_back(row);
            this->row_count++;
            this->columns_count = row.size();
            return true;
        } else if ((row.size() < this->columns_count) and this->auto_fill) {
            unsigned long long size_diff = this->columns_count - row.size();
            for (unsigned long long i = 0; i < size_diff; i++) {
                row.emplace_back("");
            }
            this->content.push_back(row);
            this->row_count++;
            return true;
        } else if ((row.size() > this->columns_count) and this->auto_escape) {
            unsigned long long size_diff = row.size() - this->columns_count;
            for (unsigned long long i = 0; i < size_diff; i++) {
                row.pop_back();
            }
            this->content.push_back(row);
            this->row_count++;
            return true;
        }

        return false;
    }

    bool Table::add_row(std::vector<std::string> row, int pos) {
        if (pos < 0) {
            return false;
        }

        if (this->row_count == 0 or pos >= this->row_count) {
            return this->add_row(row);
        } else {
            if (row.size() == this->columns_count) {
                this->content.insert(this->content.begin() + pos, row);
                this->row_count++;
                return true;
            } else if ((row.size() < this->columns_count) and this->auto_fill) {
                unsigned long long size_diff = this->columns_count - row.size();
                for (unsigned long long i = 0; i < size_diff; i++) {
                    row.emplace_back("");
                }
                this->content.insert(this->content.begin() + pos, row);
                this->row_count++;
                return true;
            } else if ((row.size() > this->columns_count) and this->auto_escape) {
                unsigned long long size_diff = row.size() - this->columns_count;
                for (unsigned long long i = 0; i < size_diff; i++) {
                    row.pop_back();
                }
                this->content.insert(this->content.begin() + pos, row);
                this->row_count++;
                return true;
            }

        }
        return false;
    }

    bool Table::add_column(std::vector<std::string> column) {
        if (this->columns_count == 0) {
            for (const std::string &column_data: column) {
                this->content.push_back({column_data});
            }
            this->columns_count++;

        } else if (column.size() == this->row_count or (column.size() > this->row_count and this->auto_fill)) {
            for (unsigned long long row_id = 0; row_id < this->content.size(); row_id++) {
                this->content[row_id].push_back(column[row_id]);
            }
            this->columns_count++;

            return true;
        } else if (column.size() < this->row_count and this->auto_fill) {
            for (unsigned long long row_id = 0; row_id < this->content.size(); row_id++) {
                if (row_id < column.size()) {
                    this->content[row_id].push_back(column[row_id]);
                } else {
                    this->content[row_id].emplace_back("");
                }

            }
            this->columns_count++;
            return true;
        }
        return false;
    }

    bool Table::add_column(std::vector<std::string> column, int pos) {
        if (pos < 0) {
            return false;
        }

        if (this->columns_count == 0 or pos >= this->columns_count) {
            this->add_column(column);
        } else if (column.size() == this->row_count or (column.size() > this->row_count and this->auto_fill)) {
            for (unsigned long long row_id = 0; row_id < this->content.size(); row_id++) {
                auto row = this->content[row_id];
                row.insert(row.begin() + pos, column[row_id]);
            }
            this->columns_count++;
            return true;
        } else if (column.size() < this->row_count and this->auto_fill) {
            for (unsigned long long row_id = 0; row_id < this->content.size(); row_id++) {
                if (row_id < column.size()) {
                    auto row = this->content[row_id];
                    row.insert(row.begin() + pos, column[row_id]);
                } else {
                    auto row = this->content[row_id];
                    row.insert(row.begin() + pos, "");

                }
            }
            this->columns_count++;
            return true;

        }
        return false;
    }

    bool Table::rem_row(int pos) {
        if (pos > 0 or pos < this->row_count) {
            this->content.erase(this->content.begin() + pos);
            this->row_count--;
            return true;
        }
        return false;
    }

    bool Table::rem_column(int pos) {
        if (pos > 0 or pos < this->columns_count) {
            // TODO: check if reference is needed
            for (std::vector<std::string> &row: this->content) {
                row.erase(row.begin() + pos);
            }
            this->columns_count--;
            return true;
        }
        return false;
    }

    bool Table::change_item(int row, int column, std::string new_value) {
        if (row < this->row_count and row >= 0 and column < this->columns_count and column >= 0) {
            this->content[row][column] = std::move(new_value);
            return true;
        }
        return false;
    }

    void Table::clear_table() {
        this->content.clear();
        this->columns_count = 0;
        this->row_count = 0;
    }
}
