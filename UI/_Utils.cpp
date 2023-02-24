//
// Created by pawel on 08.02.2023.
//

#include "_Utils.h"
#include <iostream>

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
}