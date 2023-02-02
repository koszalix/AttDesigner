//
// Created by pawel on 24.01.2023.
//

#include <vector>
#include <string>

#ifndef ATTDESIGNER_UITABLE_H
#define ATTDESIGNER_UITABLE_H
/**
 * Stores all formatting related variables
 *
 *
 */
struct UITableFormatting{
    std::vector<int> column_align;
    int column_margin_left = 0;
    int column_margin_right = 0;
    bool frame_around = true;
};

class UITable {
private:
    const std::vector<std::vector<std::string>> &content;

    const std::vector<int> &vertical_lines_id;
    const std::vector<int> &horizontal_lines_id;

    const UITableFormatting &formatting;

    std::vector<unsigned long long> column_sizes;
    std::vector<unsigned long long >::iterator columns_sizes_it;
    std::string horizontal_line;


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
    static void draw_line(unsigned long long  length, char sign);

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
    void draw();
    UITable(const std::vector<std::vector<std::string>> &content,
            std::vector<int> &columns_separators,
            std::vector<int> &row_separators,
            UITableFormatting &formatting):
        content(content),
        vertical_lines_id(columns_separators),
        horizontal_lines_id(row_separators),
        formatting(formatting)
        {
            this->columns_sizes_it = this->column_sizes.begin();
            this->column_sizes.insert(this->columns_sizes_it, (this->content.size()+1), 0);


        }
        //TODO: formatting in struct
        //TODO: check lengths of vectors
        //TODO: check horizontal lines
};


#endif //ATTDESIGNER_UITABLE_H
