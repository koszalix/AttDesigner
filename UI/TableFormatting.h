//
// Created by pawel on 07.02.2023.
//

#ifndef ATTDESIGNER_TABLEFORMATTING_H
#define ATTDESIGNER_TABLEFORMATTING_H

#include <vector>

namespace UI{
    struct TableFormatting{
        std::vector<int> column_align;
        int column_margin_left = 0;
        int column_margin_right = 0;
        bool frame_around = true;
    };
}
#endif //ATTDESIGNER_TABLEFORMATTING_H
