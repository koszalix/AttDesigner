//
// Created by pawel on 24.02.2023.
//

#ifndef ATTDESIGNER_BPIATTENUATOR_H
#define ATTDESIGNER_BPIATTENUATOR_H

#include <vector>
#include "Attenuators.h"

namespace Backend{
class BPiAttenuator : public Backend::Attenuators{
public:
    double Zin(std::vector<double> Z);
    double Zout(std::vector<double> Z);
    double Att(std::vector<double> Z);
    std::vector<double> Z(double Zin, double Zout, double Att);
};
}


#endif //ATTDESIGNER_BPIATTENUATOR_H
