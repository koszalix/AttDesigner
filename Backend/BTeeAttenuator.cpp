//
// Created by pawel on 24.02.2023.
//

#include "BTeeAttenuator.h"

double Backend::BTeeAttenuator::Zin(std::vector<double> Z) {
    return Attenuators::Zin(Z);
}

double Backend::BTeeAttenuator::Zout(std::vector<double> Z) {
    return Attenuators::Zout(Z);
}

double Backend::BTeeAttenuator::Att(std::vector<double> Z) {
    return Attenuators::Att(Z);
}

std::vector<double> Backend::BTeeAttenuator::Z(double Zin, double Zout, double Att) {
    return Attenuators::Z(Zin, Zout, Att);
}
