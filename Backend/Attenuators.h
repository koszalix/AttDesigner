//
// Created by pawel on 24.02.2023.
//

#ifndef ATTDESIGNER_ATTENUATORS_H
#define ATTDESIGNER_ATTENUATORS_H

#include <vector>

namespace Backend{
class Attenuators {
protected:
    /**
     * Precision for comparison of input/output impedance
     */
    static constexpr double comp_precision = 1e-4;
public:
    virtual double Zin(std::vector<double> Z) { return -1; }
    virtual double Zout(std::vector<double> Z) { return -1; }
    virtual double Att(std::vector<double> Z) { return -1; }
    virtual std::vector<double> Z(double Zin, double Zout, double Att) { return -1; }
};
}



#endif //ATTDESIGNER_ATTENUATORS_H
