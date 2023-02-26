//
// Created by pawel on 24.02.2023.
//

#include "Prompts.h"
#include <iostream>
#include <cmath>


void UI::Prompts::input_impedance() {
    double zin;
    std::cout << "Enter input impedance: ";
    zin = _Utils::get_input_double();
    while(zin <= 0){
        std::cout << "Input impedance must be greater than zero";
        std::cout << "Enter input impedance: ";
        zin = _Utils::get_input_double();
    }
    this->storage.set_input_impedance(zin);
}

void UI::Prompts::output_impedance() {
    double zout;
    bool empty = false;
    bool *empty_ptr = &empty;

    std::cout << "Enter output impedance: (leave blank for " << this->storage.get_input_impedance() << ")";

    zout = _Utils::get_input_double(empty_ptr);
    if(empty){
        zout = this->storage.get_input_impedance();
        this->storage.set_impedance_equal();
    }

    while(zout <= 0){
        std::cout << "Output impedance must be greater than zero";
        std::cout << "Enter output impedance: ";
        zout = _Utils::get_input_double();
    }
    this->storage.set_output_impedance(zout);
    this->storage.set_impedance_equal(false);
}

void UI::Prompts::attenuation() {
    double att;
    std::cout << "Enter attenuation [dB]: ";
    att = _Utils::get_input_double();
    this->storage.set_attenuation(att);
}


void UI::Prompts::attenuator_type() {
    int type;
    std::cout<<"Select attenuator type"<<std::endl;
    std::cout<<"[0] Pi" << std::endl;
    std::cout<<"[1] Tee" << std::endl;
    std::cout<<"[2] Balanced Pi" << std::endl;
    std::cout<<"[3] Balanced Tee" << std::endl;

    type = _Utils::get_input_int();

    while(type < 0 or type > 3){
        std::cout << "Please select valid attenuator type (1-4)" << std::endl;
        type = _Utils::get_input_int();
    }
    this->storage.set_type(type);
}

void UI::Prompts::resistor_value() {
    double R2;
    std::cout << "Enter value of R2 (this prompt is active only when Zin != Zout) ";
    std::cout << "When Zin != Zout attenuation of the circuit is defined ";

    R2 = _Utils::get_input_double();
    while(R2 <= 0){
        std::cout << "R2 must be greater than zero: ";
        R2 = _Utils::get_input_double();
    }
    this->storage.set_default_value(R2);
}

void UI::Prompts::init_prompt() {
    constexpr double comp_precision = 1e-4;
    this->input_impedance();
    this->output_impedance();
    this->attenuation();
    this->attenuator_type();
    if(this->storage.zin_equal_zout()) this->resistor_value();

}



