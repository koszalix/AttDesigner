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
        static constexpr int no_attenuators = 4;
        int attenuator_type = 0;

        Backend::BPiAttenuator BPi;
        Backend::BTeeAttenuator BTee;
        Backend::PiAttenuator Pi;
        Backend::TeeAttenuator Tee;
        Backend::Attenuators *att_pointer[no_attenuators] = {&Pi, &Tee, &BPi, &BTee};

    public:
        std::vector<double> calculate_ideal_resistors(double Zin, double Zout, double Att);
        double calculate_attenuation(std::vector<double> resistors);
        double calculate_input_impedance(std::vector<double> resistors);
        double calculate_output_impedance(std::vector<double> resistors);

        void setAttenuatorType(int attenuatorType);

    };

} // Calc

#endif //ATTDESIGNER_CALC_H
