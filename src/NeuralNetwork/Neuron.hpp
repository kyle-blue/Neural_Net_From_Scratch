#pragma once

#include <string>
#include "Activation.hpp"
#include "viennacl/vector.hpp"

namespace vcl = viennacl;

struct Neuron
{
    vcl::vector<float> weights;
    float bias;
    Activation activation;
};

