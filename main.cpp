#include <iostream>
#include "UI/Table.h"
#include "Storage/Table.h"
#include "UI/AttenuatorParameters.h"
#include "Storage/AttenuatorParameters.h"

int main() {



    Storage::Table storage;

    storage.add_row({"A1", "A2", "A3", "A  4", "A5", "A6"});
    storage.add_row({"B1", "B2", "B3", "B4", "B5", "B6"});
    storage.add_row({"c1", "c2", "c3", "C4", "C5", "C6xx"});
    storage.add_row({"d1", "d2", "d3", "d4", "ed5", "d6"});
    storage.add_row({"e1", "23e2", "e3", "e4", "e5", "e6"});
    storage.add_row({"f1", "f2", "f3", "f4", "f5", "f6"});

    std::vector<int> horizontal_lines = {0,2};
    std::vector<int> vertical_sep = {1,2};

    UI::TableFormatting form;
    form.column_margin_left = 1;
    form.column_margin_right = 1;
    form.column_align = {0,0, 0, 0, 0, 0};
    form.frame_around = true;
    UI::Table table(storage, vertical_sep, horizontal_lines, form);

    std::cout << "Basic table" << std::endl;
    table.draw();

    std::cout << std::endl << "Added row at end" << std::endl;
    storage.add_row({"g1", "g2", "g3", "g4", "g5", "g6"});
    table.draw();

    std::cout << std::endl << "Added uncompleted row at end" << std::endl;
    storage.add_row({"uu2", "uu1"});
    table.draw();

    std::cout << std::endl << "Added row at 1" << std::endl;
    storage.add_row({"i1", "i", "i3", "i4", "i5", "i6"}, 1);
    table.draw();

    std::cout << std::endl << "Added column at right" << std::endl;
    storage.add_column({"K1", "K2", "K3", "K4", "K5", "K6", "K7", "K8", "K9"});
    table.draw();

    std::cout << std::endl << "Added incomplete column" << std::endl;
    storage.add_column({"u1, u2, u3"});
    table.draw();

    std::cout << std::endl << "Removed column 3" << std::endl;
    storage.rem_column(3);
    table.draw();

    std::cout << std::endl << "Removed row 0" << std::endl;
    storage.rem_row(0);
    table.draw();

    std::cout << std::endl << "Changed B6 to dog" << std::endl;
    storage.change_item(1,2, "dog");
    table.draw();

    Storage::AttenuatorParameters att;
    att.set_input_impedance(50);
    att.set_output_impedance(75);
    att.set_attenuation(20);
    att.set_type(1);

    UI::AttenuatorParameters ui_att{att};
    ui_att.draw();

    att.set_output_impedance(30);
    ui_att.draw();

    return 0;
}
