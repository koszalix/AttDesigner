//
// Created by pawel on 07.02.2023.
//

#ifndef ATTDESIGNER_STORAGEATTENUATORPARAMETERS_H
#define ATTDESIGNER_STORAGEATTENUATORPARAMETERS_H


#include <iostream>
#include <cmath>

class StorageAttenuatorParameters {
private:
    double input_impedance;
    double output_impedance;
    double attenuation;

    /**
     * Store type of attenuator
     *
     * 0 - Pi
     * 1 - Tee
     * 2 - Balanced Pi
     * 3 - Balanced Tee
     */
    int type;
    static constexpr int no_of_types = 3;

public:
    /**
     * Set modulus of input characteristic impedance
     * @param zi Impedance modulus in ohms
     */
    void set_input_impedance(double zi){
        if(zi < 0){
            throw std::invalid_argument("Input impedance must be greater than zero");
        }
        else{
            this->input_impedance = zi;
        }
    }

    /**
     * Set modulus of output characteristic impedance
     * @param zi Impedance modulus in ohms
     */
    void set_output_impedance(double zo){
        if(zo < 0){
            throw std::invalid_argument("Output impedance must be greater than zero");
        }
        else{
            this->input_impedance = zo;
        }
    }

    /**
     * Set attenuation in decibels
     * @param att Attenuation in dB
     */
    void set_attenuation(double att){
        if(att < 0){
            att *= -1;
            this->attenuation = att;
        }
        else{
            this->attenuation = att;
        }
    }

    /**
     * Set type of attenuator
     *
     * Available types
     * - 0 -> Pi
     * - 1 -> Tee
     * - 2 -> Balanced Pi
     * - 3 -> Balanced Tee
     * @param att_type Attenuator type
     */
    void set_type(int att_type){
        if(type > no_of_types or type < 0){
            throw std::invalid_argument("Invalid attenuator type");
        }
        else{
            this->type = att_type;
        }
    }

    /**
     * Get modulus of input characteristic impedance
     * @return
     */
    double get_input_impedance(){
        return this->input_impedance;
    }

    /**
     * Get modulus of output characteristic impedance
     * @return
     */
    double get_output_impedance(){
        return this->output_impedance;
    }

    /**
     * Get attenuation of attenuator
     * @return Attenuation in dB
     */
    double get_attenuation(){
        return this->attenuation;
    }

    /**
     * Get attenuation of attenuator
     * @param linear Set to true to get attenuation in V/V instead of dB
     * @return attenuation in V/V or dB
     */
    double get_attenuation(bool linear){
        if(linear){
            return pow(10, (this->attenuation/20));
        }
        else{
            return this->attenuation;
        }
    }

    /**
     * Get type of attenuator
     * @return
     */
    int get_type(){
        return this->type;
    }
};


#endif //ATTDESIGNER_STORAGEATTENUATORPARAMETERS_H
