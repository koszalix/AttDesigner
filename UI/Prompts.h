//
// Created by pawel on 24.02.2023.
//

#ifndef ATTDESIGNER_PROMPTS_H
#define ATTDESIGNER_PROMPTS_H

#include "_Utils.h"
#include "../Storage/AttenuatorParameters.h"

namespace UI {
    class Prompts {
        static constexpr int prompt_length = 15;
        static constexpr int prompt_height = 3;

        Storage::AttenuatorParameters &storage;

    public:
        void input_impedance();
        void output_impedance();
        void attenuation();
        void attenuator_type();
        void init_prompt();
        void resistor_value();
    Prompts(Storage::AttenuatorParameters &storage) : storage(storage){

    }

    };
}


#endif //ATTDESIGNER_PROMPTS_H
