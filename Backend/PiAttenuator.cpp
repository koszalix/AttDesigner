//
// Created by pawel on 24.02.2023.
//

#include "PiAttenuator.h"

double Backend::PiAttenuator::Zin(std::vector<double> Z) {
    return Attenuators::Zin(Z);
}

double Backend::PiAttenuator::Zout(std::vector<double> Z) {
    return Attenuators::Zout(Z);
}

double Backend::PiAttenuator::Att(std::vector<double> Z) {
    return Attenuators::Att(Z);
}

std::vector<double> Backend::PiAttenuator::Z(double Zin, double Zout, double Att) {
    return Attenuators::Z(Zin, Zout, Att);
}
