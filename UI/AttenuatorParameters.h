//
// Created by pawel on 08.02.2023.
//

#ifndef ATTDESIGNER_ATTENUATORPARAMETERS_H
#define ATTDESIGNER_ATTENUATORPARAMETERS_H

#include "../Storage/AttenuatorParameters.h"
#include "_Utils.h"

namespace UI {
class AttenuatorParameters : private UI::_Utils{
    private:
        static constexpr char attenuators_names[4][8] = {"Pi","Tee","Sym-Pi","Sym-Tee",};

        const Storage::AttenuatorParameters &storage;
        int parameter_max_length = 0;

        /**
         * Stores all parameters in string type, it easier for finding length an so on
         *
         *  [0] zin, [1] zout, [2] att, [3] linear att
         */
        std::string parameters[Storage::AttenuatorParameters::no_parameters];

        void set_strings();
        void find_parameter_max_length();

    public:
        void draw();

        AttenuatorParameters(Storage::AttenuatorParameters &data):
        storage(data){

        }
    };

}

#endif //ATTDESIGNER_ATTENUATORPARAMETERS_H
