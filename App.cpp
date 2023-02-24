//
// Created by pawel on 24.02.2023.
//

#include "App.h"
#include <sstream>
#include <iostream>
#include <iomanip>

void App::run(){
    this->prompts.init_prompt();
    this->update_att_params_table();
    this->att_params_table.draw();

}

std::string App::fixed_to_string(double val, int prec) {
    std::ostringstream  tmp_stream;
    tmp_stream << std::fixed << std::setprecision(prec);
    tmp_stream << val;
    return tmp_stream.str();
}


void App::update_att_params_table() {


    this->att_params_table_storage.change_item(0,1,this->fixed_to_string(this->att_params.get_input_impedance()));

    this->att_params_table_storage.change_item(1,1,this->fixed_to_string(this->att_params.get_output_impedance()));
    this->att_params_table_storage.change_item(2,1,this->fixed_to_string(this->att_params.get_attenuation()));
    this->att_params_table_storage.change_item(3,1,this->fixed_to_string(this->att_params.get_attenuation(true)));
}

void App::init_att_params_table() {
    this->att_params_table_storage.add_row({"Zin", "0", "Ohm"});
    this->att_params_table_storage.add_row({"Zout", "0", "Ohm"});
    this->att_params_table_storage.add_row({"A", "0", "dB"});
    this->att_params_table_storage.add_row({"A", "0", "V/V"});

}

