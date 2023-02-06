//
// Created by pawel on 03.02.2023.
//

#ifndef ATTDESIGNER_TABLESTORAGE_H
#define ATTDESIGNER_TABLESTORAGE_H

#include <vector>
#include <string>
#include "UITable.h"

class TableStorage {
    friend UITable;
private:
    unsigned long long columns_count = 0;
    unsigned long long row_count = 0;

    /*
     * Stores content of table, left vector contains rows, right vector contain columns
     * item = content[row][column]
     */
    std::vector<std::vector<std::string>> content;

    bool auto_fill = true;
    bool auto_escape = true;

public:
    /**
     * Define behavior when row or column have too few items
     *
     * @param state When set to true empty spots will be filed with spaces
     */
    void set_auto_fill(bool state) {
        this->auto_fill = state;
    };

    /**
     * Define behavior when row or column have too much items
     *
     * @param state When set to true surplus elements will be omitted
     */
    void set_auto_escape(bool state) {
        this->auto_escape = state;
    };

    /** Add row at bottom of table
     *
     * @param row Data to be put in row
     * @return false in case of fail, true if successful
     */
    bool add_row(std::vector<std::string> row);

    /**
     * Add row at specified place in table
     *
     * @param row Data to be put in row
     * @param pos Row position (id)
     * @return false in case of fail, true if successful
     */
    bool add_row(std::vector<std::string> row, int pos);

    /**
     * Add column on the right of table
     *
     * @param column Data to be put in column
     * @return false in case of fail, true if successful
     */
    bool add_column(std::vector<std::string> column);

    /**
     * Add column at specified place in table
     *
     * @param column Data to be put in column
     * @param pos Row position (id)
     * @return false in case of fail, true if successful
     */
    bool add_column(std::vector<std::string> column, int pos);

    /**
     * Delete specified row
     *
     * @param pos Row position (id)
     * @return false in case of fail, true if successful
     */
    bool rem_row(int pos);

    /**
     * Delete specified column
     *
     * @param pos Column position (id)
     * @return false in case of fail, true if successful
     */
    bool rem_column(int pos);

    /**
     * Change value of specified item
     *
     * @param row Row position (id)
     * @param column Column position (id)
     * @param new_value Value to set at specified position
     * @return false in case of fail, true if successful
     */
    bool change_item(int row, int column, std::string new_value);

    /**
     * Remove all values in table
     *
     * @return false in case of fail, true if successful
     */
    void clear_table();
};


#endif //ATTDESIGNER_TABLESTORAGE_H
