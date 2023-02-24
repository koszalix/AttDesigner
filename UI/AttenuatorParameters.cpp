//
// Created by pawel on 08.02.2023.
//

#include "AttenuatorParameters.h"

namespace UI{

    void AttenuatorParameters::set_strings() {
        this->parameters[0] = std::to_string(this->storage.input_impedance);
        this->parameters[1] = std::to_string(this->storage.output_impedance);
        this->parameters[2] = std::to_string(this->storage.attenuation);
        this->parameters[3] = std::to_string(this->storage.attenuation_linear);
    }

    void AttenuatorParameters::find_parameter_max_length() {
        for(auto parameter : this->parameters){
            if(parameter.length() > this->parameter_max_length){
                this->parameter_max_length = parameter.length();
            }

        }
    }

    void AttenuatorParameters::draw() {
        this->set_strings();
        this->find_parameter_max_length();

        std::cout << "Selected Type (F6): " << this->attenuators_names[this->storage.type] <<std::endl;
        std::cout << "Zin(F2)  " << this->parameters[0];
        draw_line(this->parameter_max_length - this->parameters[0].length());
        std::cout << std::endl;
        std::cout << "Zout(F3) " << this->parameters[1];
        draw_line(this->parameter_max_length - this->parameters[1].length());
        std::cout << std::endl;
        std::cout << "Ku(F4)   " << this->parameters[2];
        draw_line(this->parameter_max_length - this->parameters[2].length());
        std::cout << std::endl;
        std::cout << "Ku(F4)   " << this->parameters[3];
        draw_line(this->parameter_max_length - this->parameters[3].length());
        std::cout << std::endl;

    }
}