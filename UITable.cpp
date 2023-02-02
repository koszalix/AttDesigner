//
// Created by pawel on 24.01.2023.
//

#include <iostream>
#include "UITable.h"


void UITable::draw() {
    this->find_column_sizes();
    this->generate_horizontal_separator();
    for(int row_id=0; row_id < this->content.size(); row_id++){
        this->draw_horizontal_separator(row_id);
        for(int column_id=0; column_id < this->content[row_id].size(); column_id++) {
           this->draw_cell(column_id, row_id);
        }
        std::cout<<std::endl;
    }
}

void UITable::find_column_sizes() {
    for(const auto & row_id : this->content){
        for(int column_id=0; column_id < row_id.size(); column_id++){
            if(row_id[column_id].length() > this->column_sizes[column_id]){
                this->column_sizes[column_id] = row_id[column_id].length();
            }
        }
    }
}

void UITable::generate_horizontal_separator() {
    for(auto length: this->column_sizes){
        this->horizontal_line += std::string(length, '-');
    }
    this->horizontal_line += std::string((this->column_margin_left+this->column_margin_right)*this->column_sizes.size(), '-');
    this->horizontal_line += std::string(this->vertical_lines_id.size(), '-');

    for(int sep_id = 0; sep_id < this->vertical_lines_id.size(); sep_id++){
        auto separator_id = this->vertical_lines_id[sep_id];
        unsigned long long line_idx = 0;
        for(int column_id=0; column_id <= separator_id; column_id++){
            line_idx += this->column_sizes[column_id];
        }

        line_idx += (this->column_margin_right+this->column_margin_left) * (separator_id+1);
        line_idx += sep_id;
        this->horizontal_line[line_idx] = '+';
    }

}



void UITable::draw_line(unsigned long long length, char sign) {

    if(length > 0) {
        for (int pos = 0; pos < length; pos++) {
            std::cout << sign;
        }
    }
}

void UITable::draw_vertical_separator(int column) {
    for(int id: this->vertical_lines_id){
        if(id == column){
            std::cout<<"|";
            return;
        }
    }
}

void UITable::draw_horizontal_separator(int row) {
    for(int id: this->horizontal_lines_id){
        if(id == row){
           std::cout<<horizontal_line<<std::endl;
        }
    }
}

void UITable::draw_cell(int column, int row) {
    unsigned long long cell_length = this->column_sizes[column];
    unsigned long long text_length = this->content[row][column].length();
    unsigned long long delta_length = cell_length - text_length;
    unsigned long long space = delta_length / 2;
    unsigned long long extra_space_char = delta_length - (2 * space);
    this->draw_line(this->column_margin_left, ' ');
    switch (this->column_align[column]) {
        case 0: // left align
            std::cout<<this->content[row][column];
            this->draw_line(delta_length, ' ');
            break;
        case 1: // center align
            this->draw_line(space+extra_space_char, ' ');
            std::cout<<this->content[row][column];
            this->draw_line(space, ' ');
            break;
        case 2: // center right
            this->draw_line(delta_length, ' ');
            std::cout<<this->content[row][column];
            break;
    }
    this->draw_line(this->column_margin_right, ' ');

    this->draw_vertical_separator(column);
}