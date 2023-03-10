//
// Created by pawel on 08.02.2023.
//

#include "_Utils.h"
#include <iostream>
#include <string>

namespace UI{
    void _Utils::draw_line(unsigned long long length) {

        if (length > 0) {
            for (int pos = 0; pos < length; pos++) {
                std::cout << ' ';
            }
        }
    }
    void _Utils::draw_line(unsigned long long length, char sign) {

        if (length > 0) {
            for (int pos = 0; pos < length; pos++) {
                std::cout << sign;
            }
        }
    }

    double _Utils::get_input_double(bool *empty) {
        std::string tmp;
        std::getline(std::cin, tmp);
        if(tmp.empty()) *empty = true;
        return std::stod(tmp);
    }

    int _Utils::get_input_int(bool *empty) {
        std::string tmp;
        std::getline(std::cin, tmp);
        if(tmp.empty()) *empty = true;
        return std::stoi(tmp);
    }
}