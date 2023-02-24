//
// Created by pawel on 24.02.2023.
//

#ifndef ATTDESIGNER_APP_H
#define ATTDESIGNER_APP_H

#include "UI/Table.h"
#include "UI/TableFormatting.h"
#include "Storage/Table.h"
#include "Storage/AttenuatorParameters.h"
#include "UI/Prompts.h"

#include <string>

class App {

private:

    Storage::AttenuatorParameters att_params;
    Storage::Table att_params_table_storage;
    Storage::Table main_table_storage;

    UI::TableFormatting att_params_table_formatting;
    UI::TableFormatting main_table_formatting;

    UI::Table main_table;
    UI::Table att_params_table;

    UI::Prompts prompts;

    void init_att_params_table();
    void update_att_params_table();

    std::string fixed_to_string(double val, int prec=2);

public:
    void run();

    App() :
    main_table(main_table_storage, main_table_formatting),
    att_params_table(att_params_table_storage, att_params_table_formatting),
    prompts(att_params)
    {
        this->init_att_params_table();
        this->att_params_table_formatting.column_align = {0,0,0};
        this->att_params_table_formatting.frame_around = false;
        this->att_params_table_formatting.column_margin_right = 1;
        this->att_params_table_formatting.column_margin_left = 0;

    }

};


#endif //ATTDESIGNER_APP_H
