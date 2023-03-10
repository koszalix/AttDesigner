//
// Created by pawel on 08.02.2023.
//

#ifndef ATTDESIGNER__UTILS_H
#define ATTDESIGNER__UTILS_H

namespace UI {
    class _Utils {
    public:
        static void draw_line(unsigned long long length);
        static void draw_line(unsigned long long length, char sign);
        static double get_input_double(bool *empty = nullptr);
        static int get_input_int(bool *empty = nullptr);

    };
}


#endif //ATTDESIGNER__UTILS_H
