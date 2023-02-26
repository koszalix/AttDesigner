//
// Created by pawel on 25.02.2023.
//

#include "Calc.h"

namespace Backend {
    std::vector<double> Calc::calculate_ideal_resistors(double Zin, double Zout, double Att) {
        return this->att_pointer[this->attenuator_type]->Z(Zin, Zout, Att);
    }

    double Calc::calculate_attenuation(std::vector<double> resistors) {
        return this->att_pointer[this->attenuator_type]->Att(resistors);
    }

    double Calc::calculate_input_impedance(std::vector<double> resistors) {
        return this->att_pointer[this->attenuator_type]->Zin(resistors);
    }

    double Calc::calculate_output_impedance(std::vector<double> resistors) {
        return this->att_pointer[this->attenuator_type]->Zout(resistors);
    }


    void Calc::setAttenuatorType(int attenuatorType) {
        if (attenuatorType >= 0 and attenuatorType < this->no_attenuators) {
            attenuator_type = attenuatorType;
        }
    }
}
