//
// Created by pawel on 24.01.2023.
//

#include <iostream>
#include "Table.h"

namespace UI {
    void Table::sanity() {
        for (auto element: this->storage.content) {
            if (element.size() != this->storage.columns_count) {
                throw std::invalid_argument("Rows sizes mismatch");
            }
        }
        if (this->vertical_lines_id.size() > this->storage.columns_count) {
            throw std::out_of_range("Columns separator have too many elements");
        }
        if (this->horizontal_lines_id.size() > this->storage.row_count) {
            throw std::out_of_range("Rows separator have too many elements");
        }
        for (auto line_id: this->vertical_lines_id) {
            if (line_id >= this->storage.columns_count)
                throw std::out_of_range("Id of column separator exceeded number of columns");
            if (line_id < 0) throw std::out_of_range("Column separator must be greater than zero");
        }
        for (auto line_id: this->vertical_lines_id) {
            if (line_id >= this->storage.row_count)
                throw std::out_of_range("Id of row separator exceeded number of row");
            if (line_id < 0) throw std::out_of_range("Row separator must be greater than zero");
        }
    }

    void Table::draw() {
        this->sanity();
        this->find_column_sizes();
        this->generate_horizontal_separator();

        for (int row_id = 0; row_id < this->storage.row_count; row_id++) {
            if (row_id != this->storage.row_count - 1) this->draw_horizontal_separator(row_id);

            for (int column_id = 0; column_id < this->storage.columns_count; column_id++) {
                this->draw_cell(column_id, row_id);
            }
            std::cout << std::endl;

            if (row_id == this->storage.row_count - 1) this->draw_horizontal_separator(row_id);
        }
    }

    void Table::find_column_sizes() {
        this->column_sizes.clear();
        this->column_sizes.insert(this->column_sizes.begin(), (this->storage.columns_count), 0);

        for (const auto &row_id: this->storage.content) {
            for (int column_id = 0; column_id < row_id.size(); column_id++) {
                if (row_id[column_id].length() > this->column_sizes[column_id]) {
                    this->column_sizes[column_id] = row_id[column_id].length();
                }
            }
        }
    }

    void Table::generate_horizontal_separator() {
        this->horizontal_line = "";

        if (this->formatting.frame_around) {
            this->horizontal_line += "+";
        }

        for (auto length: this->column_sizes) {
            this->horizontal_line += std::string(length, '-');
        }
        this->horizontal_line += std::string(
                (this->formatting.column_margin_left + this->formatting.column_margin_right) *
                this->column_sizes.size(), '-');
        this->horizontal_line += std::string(this->vertical_lines_id.size(), '-');

        for (int sep_id = 0; sep_id < this->vertical_lines_id.size(); sep_id++) {
            auto separator_id = this->vertical_lines_id[sep_id];
            unsigned long long line_idx = 0;
            for (int column_id = 0; column_id <= separator_id; column_id++) {
                line_idx += this->column_sizes[column_id];
            }

            // separator_id + 1 caused by first index at zero
            line_idx +=
                    (this->formatting.column_margin_right + this->formatting.column_margin_left) * (separator_id + 1);
            // shift right due to previous separators, adding value of frame_around shifts right when frame char is present
            line_idx += (sep_id + this->formatting.frame_around);
            this->horizontal_line[line_idx] = '+';
        }
        if (this->formatting.frame_around) {
            this->horizontal_line += "+";
        }

    }


    void Table::draw_line(unsigned long long length, char sign) {

        if (length > 0) {
            for (int pos = 0; pos < length; pos++) {
                std::cout << sign;
            }
        }
    }

    void Table::draw_vertical_separator(int column) {
        for (int id: this->vertical_lines_id) {
            if (id == column) {
                std::cout << "|";
                return;
            }
        }
    }

    void Table::draw_horizontal_separator(int row) {
        if (this->formatting.frame_around) {
            if (row == 0 or row == (this->storage.row_count - 1)) {
                std::cout << horizontal_line << std::endl;
                return;
            }
        }
        for (int id: this->horizontal_lines_id) {
            if (id == row) {
                std::cout << horizontal_line << std::endl;
                return;
            }
        }
    }

    void Table::draw_cell(int column, int row) {
        unsigned long long cell_length = this->column_sizes[column];
        unsigned long long text_length = this->storage.content[row][column].length();
        unsigned long long delta_length = cell_length - text_length;
        unsigned long long space = delta_length / 2;
        unsigned long long extra_space_char = delta_length - (2 * space);

        if (column == 0 and this->formatting.frame_around) std::cout << "|";

        this->draw_line(this->formatting.column_margin_left, ' ');
        switch (this->formatting.column_align[column]) {
            default:
            case 0: // left align
                std::cout << this->storage.content[row][column];
                this->draw_line(delta_length, ' ');
                break;
            case 1: // center align
                this->draw_line(space + extra_space_char, ' ');
                std::cout << this->storage.content[row][column];
                this->draw_line(space, ' ');
                break;
            case 2: // right align
                this->draw_line(delta_length, ' ');
                std::cout << this->storage.content[row][column];
                break;
        }
        this->draw_line(this->formatting.column_margin_right, ' ');

        this->draw_vertical_separator(column);
        if (column == (this->storage.columns_count - 1) and this->formatting.frame_around) std::cout << "|";
    }
}