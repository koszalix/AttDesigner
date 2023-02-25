//
// Created by pawel on 24.02.2023.
//

#ifndef ATTDESIGNER_BTEEATTENUATOR_H
#define ATTDESIGNER_BTEEATTENUATOR_H

#include "Attenuators.h"
#include <vector>

namespace Backend{
class BTeeAttenuator : public Backend::Attenuators{
public:
    double Zin(std::vector<double> Z);
    double Zout(std::vector<double> Z);
    double Att(std::vector<double> Z);
    std::vector<double> Z(double Zin, double Zout, double Att);

};
}


#endif //ATTDESIGNER_BTEEATTENUATOR_H
