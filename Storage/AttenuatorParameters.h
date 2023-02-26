//
// Created by pawel on 07.02.2023.
//

#ifndef ATTDESIGNER_STORAGEATTENUATORPARAMETERS_H
#define ATTDESIGNER_STORAGEATTENUATORPARAMETERS_H


#include <iostream>
#include <cmath>

namespace UI{
    class AttenuatorParameters;
}

namespace Storage {
    class AttenuatorParameters {
        friend UI::AttenuatorParameters;

    public:
        static constexpr int no_parameters = 4;

    private:
        // Total number of parameters
        double input_impedance;
        double output_impedance;
        double attenuation;
        double attenuation_linear;

        // this variable is value of resistor used for calculating algorithm when Zin != Zout,
        // for more specific information see user manual
        double default_value = 100;

        bool io_impedance_equal;

    private:
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

        static double att_to_linear(double att_db){
            return pow(10, (att_db / 20));
        }

    public:
        /**
         * Set modulus of input characteristic impedance
         * @param zi Impedance modulus in ohms
         */
        void set_input_impedance(double zi) {
            if (zi < 0) {
                throw std::invalid_argument("Input impedance must be greater than zero");
            } else {
                this->input_impedance = zi;
            }
        }

        /**
         * Set modulus of output characteristic impedance
         * @param zi Impedance modulus in ohms
         */
        void set_output_impedance(double zo) {
            if (zo < 0) {
                throw std::invalid_argument("Output impedance must be greater than zero");
            } else {
                this->output_impedance = zo;
            }
        }

        /**
         * Set attenuation in decibels
         * @param att Attenuation in dB
         */
        void set_attenuation(double att) {
            if (att < 0) {
                att *= -1;
                this->attenuation = att;
            } else {
                this->attenuation = att;
            }
            this->attenuation_linear = this->att_to_linear(att);
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
        void set_type(int att_type) {

            if (att_type > no_of_types or att_type < 0) {
                throw std::invalid_argument("Invalid attenuator type");
            } else {
                this->type = att_type;
            }
        }

        /**
         * Set default resistor value, set only when Zin != Zout
         * @param value value to set
         */
        void set_default_value(double value){
            if (value <= 0 ){
                throw std::invalid_argument("Default value must be greater than zero");
            }
            else{
                this->default_value = value;
            }
        }

        /**
         * Set to true when input an output impedance is equal
         * @param state
         */
        void set_impedance_equal(bool state = true){
            this->io_impedance_equal = state;
        }

        /**
         * Get modulus of input characteristic impedance
         * @return
         */
        double get_input_impedance() const {
            return this->input_impedance;
        }

        /**
         * Get modulus of output characteristic impedance
         * @return
         */
        double get_output_impedance() const {
            return this->output_impedance;
        }

        /**
         * Get attenuation of attenuator
         * @return Attenuation in dB
         */
        double get_attenuation() const{
            return this->attenuation;
        }

        /**
         * Get attenuation of attenuator
         * @param linear Set to true to get attenuation in V/V instead of dB
         * @return attenuation in V/V or dB
         */
        double get_attenuation(bool linear) const{
            if (linear) {
                return this->attenuation_linear;
            } else {
                return this->attenuation;
            }
        }

        /**
         * Get type of attenuator
         * @return
         */
        int get_type() const{
            return this->type;
        }

        /**
         * Get name of attenuator type
         * @return
         */
        std::string get_name() {
            switch(this->type){
                case 0:
                    return "Pi";
                    break;
                case 1:
                    return "Tee";
                    break;
                case 2:
                    return "B. Pi";
                    break;
                case 3:
                    return "B. Tee";
                    break;
            }
        }

        /**
         * Get default resistor value, used only when Zin != Zout
         * @return
         */
        double get_default_value(){
            return this->default_value;
        }

        /**
         * Check if input impedance is equal to output impedance
         * @return
         */
        bool zin_equal_zout(){
            return this->io_impedance_equal;
        }
    };
}

#endif //ATTDESIGNER_STORAGEATTENUATORPARAMETERS_H
