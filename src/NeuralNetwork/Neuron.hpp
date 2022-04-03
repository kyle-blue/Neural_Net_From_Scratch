#pragma once

#include <string>
#include "Activation.hpp"

struct Neuron
{
    Vector weights;
    float bias;
    Activation activation;
};

