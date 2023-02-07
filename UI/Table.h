//
// Created by pawel on 24.01.2023.
//

#include <vector>
#include <string>
#include "../Storage/Table.h"
#include "TableFormatting.h"

#ifndef ATTDESIGNER_UITABLE_H
#define ATTDESIGNER_UITABLE_H

/**
 * Stores all formatting related variables
 *
 * @var column_align: align for every column separately, 0 - left align, 1 - center align, 2 - right align
 * @var column_margin_left: left margin of column
 * @var column_margin_right: right margin of column
 * @var frame_around: set true to generate frame around table
 */


namespace UI {
    class Table {
    private:
        Storage::Table &storage;

        const std::vector<int> &vertical_lines_id;
        const std::vector<int> &horizontal_lines_id;

        const UI::TableFormatting &formatting;

        std::vector<unsigned long long> column_sizes;
        std::string horizontal_line;

        /**
         * Check parameters of provided objects
         *
         * Throws errors when
         * - rows have different number of columns
         * - columns separator vector have too many items or any value of this vector exceeded number of columns
         * - rows separator vector have too many items or any value of this vector exceeded number of rows
         * - rows and columns separators are greater than zero
         */
        void sanity();

        /**
         * Find the longest string in every column, and save this value to this->column_sizes
         */
        void find_column_sizes();

        /**
         * Generate horizontal line (separator), and save it to this->horizontal_line
         */
        void generate_horizontal_separator();

        /**
         * Print line of chars on terminal, be careful this method print any end-line characters
         * @param length number of characters to print
         * @param sign character to print
         */
        static void draw_line(unsigned long long length, char sign);

        /**
         * Check (and print if needed) column separator
         * @param column column to check for separator
         */
        void draw_vertical_separator(int column);

        /**
         * Check (and print if needed) row separator
         * @param row row to check for separator
         */
        void draw_horizontal_separator(int row);

        /**
         * Print specified cell with line alignment
         * @param column column id
         * @param row row id
         */
        void draw_cell(int column, int row);


    public:
        /**
         * Display table content
         */
        void draw();

        Table(Storage::Table &data, std::vector<int> &columns_separator, std::vector<int> &row_separators,
              UI::TableFormatting &formatting) :
                storage(data),
                vertical_lines_id(columns_separator),
                horizontal_lines_id(row_separators),
                formatting(formatting) {}

    };
}

#endif //ATTDESIGNER_UITABLE_H
