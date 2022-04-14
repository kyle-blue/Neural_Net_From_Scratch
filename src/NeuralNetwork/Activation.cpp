#include "Activation.hpp"
#include <algorithm>

float Activation::getOutput(float activationInput) {
    switch (value)
    {
        case RELU:
            return std::max(0.0f, activationInput); 
        case SIGMOID: {
            // float slowSigmoid = 1 / (1 + exp(-activationInput));
            // Not the actual sigmoid function, but a fast approximation of it
            float fastSigmoid =  activationInput / (1 + abs(activationInput));
            return fastSigmoid;
        }
        default:
            return -1.0f;
    }
}