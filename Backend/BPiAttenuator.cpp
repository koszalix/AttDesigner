//
// Created by pawel on 24.02.2023.
//

#include "BPiAttenuator.h"

double Backend::BPiAttenuator::Zin(std::vector<double> Z) {
    return Attenuators::Zin(Z);
}

double Backend::BPiAttenuator::Zout(std::vector<double> Z) {
    return Attenuators::Zout(Z);
}

double Backend::BPiAttenuator::Att(std::vector<double> Z) {
    return Attenuators::Att(Z);
}

std::vector<double> Backend::BPiAttenuator::Z(double Zin, double Zout, double Att) {
    return Attenuators::Z(Zin, Zout, Att);
}
