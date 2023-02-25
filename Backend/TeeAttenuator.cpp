//
// Created by pawel on 24.02.2023.
//

#include "TeeAttenuator.h"

double Backend::TeeAttenuator::Zin(std::vector<double> Z) {
    return Attenuators::Zin(Z);
}

double Backend::TeeAttenuator::Zout(std::vector<double> Z) {
    return Attenuators::Zout(Z);
}

double Backend::TeeAttenuator::Att(std::vector<double> Z) {
    return Attenuators::Att(Z);
}

std::vector<double> Backend::TeeAttenuator::Z(double Zin, double Zout, double Att) {
    return Attenuators::Z(Zin, Zout, Att);
}
