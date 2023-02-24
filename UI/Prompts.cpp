//
// Created by pawel on 24.02.2023.
//

#include "Prompts.h"
#include <iostream>



void UI::Prompts::input_impedance() {
    double zin;
    std::cout << "Enter input impedance: ";
    zin = get_input_double();
    while(zin <= 0){
        std::cout << "Input impedance must be greater than zero";
        std::cout << "Enter input impedance: ";
        zin = get_input_double();
    }
    this->storage.set_input_impedance(zin);
}

void UI::Prompts::output_impedance() {
    double zout;
    std::cout << "Enter output impedance: ";
    zout = get_input_double();
    while(zout <= 0){
        std::cout << "Output impedance must be greater than zero";
        std::cout << "Enter output impedance: ";
        zout = get_input_double();
    }
    this->storage.set_output_impedance(zout);
}

void UI::Prompts::attenuation() {
    double att;
    std::cout << "Enter attenuation [dB]: ";
    att = get_input_double();
    this->storage.set_attenuation(att);
}


void UI::Prompts::attenuator_type() {
    int type;
    std::cout<<"Select attenuator type"<<std::endl;
    std::cout<<"[0] Pi" << std::endl;
    std::cout<<"[1] Tee" << std::endl;
    std::cout<<"[2] Balanced Pi" << std::endl;
    std::cout<<"[3] Balanced Tee" << std::endl;

    type = get_input_int();

    while(type < 0 or type > 3){
        std::cout << "Please select valid attenuator type (1-4)" << std::endl;
        type = get_input_int();
    }
    this->storage.set_type(type);
}

void UI::Prompts::init_prompt() {
    this->input_impedance();
    this->output_impedance();
    this->attenuation();
    this->attenuator_type();
}

