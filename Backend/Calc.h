//
// Created by pawel on 25.02.2023.
//

#ifndef ATTDESIGNER_CALC_H
#define ATTDESIGNER_CALC_H
#include "Attenuators.h"
#include "BPiAttenuator.h"
#include "BTeeAttenuator.h"
#include "PiAttenuator.h"
#include "TeeAttenuator.h"

#include <vector>

namespace Backend {

    class Calc {
    private:
        Backend::BPiAttenuator BPi;
        Backend::BTeeAttenuator BTee;
        Backend::PiAttenuator Pi;
        Backend::TeeAttenuator Tee;
        Backend::Attenuators *att_pointer[4] = {&Pi, &Tee, &BPi, &BTee};

    public:
        std::vector<double> calculate_ideal_resistors();
        double calculate_attenuation(std::vector<double> resistors);
        double calculate_input_impedance(std::vector<double> resistors);
        double calculate_output_impedance(std::vector<double> resistors);

    };

} // Calc

#endif //ATTDESIGNER_CALC_H
