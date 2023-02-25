//
// Created by pawel on 24.02.2023.
//

#ifndef ATTDESIGNER_ATTENUATORS_H
#define ATTDESIGNER_ATTENUATORS_H

#include <vector>

namespace Backend{
class Attenuators {

public:
    virtual double Zin(std::vector<double> Z);
    virtual double Zout(std::vector<double> Z);
    virtual double Att(std::vector<double> Z);
    virtual std::vector<double> Z(double Zin, double Zout, double Att);
};
}



#endif //ATTDESIGNER_ATTENUATORS_H
