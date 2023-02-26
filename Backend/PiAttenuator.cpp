//
// Created by pawel on 24.02.2023.
//

#include "PiAttenuator.h"
#include <cmath>

double Backend::PiAttenuator::Zin(std::vector<double> Z) {
    if(Z.size() >= 2) return (Z[1] * Z[0])/(Z[1] + Z[0]);
    else return -1;
}

double Backend::PiAttenuator::Zout(std::vector<double> Z) {
    if(Z.size() >= 3) return (Z[1] * Z[2]) / (Z[1] + Z[2]);
    else return -1;
}

double Backend::PiAttenuator::Att(std::vector<double> Z) {
    if(Z.size() >= 3) return (Z[1] + Z[2])/Z[2];
    else return -1;
}

std::vector<double> Backend::PiAttenuator::Z(double Zin, double Zout, double Att, bool impedance_equal, double R2) {
    if(impedance_equal){
       double R1;
       R1 = Zin * ((Att-1)/(Att+1));
       R2 = 2 * Zin * (Att/(Att-1));
       return {R1, R2, R1};
    }
    else{
        double R1, R3;
        R1 = 1/(1/Zin - 1/R2);
        R3 = 1/(1/Zout - 1/R2);
        return {R1, R2, R3};
    }

}
