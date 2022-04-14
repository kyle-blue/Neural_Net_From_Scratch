#pragma once

#include "Neuron.hpp"
#include "viennacl/matrix.hpp"
#include "viennacl/vector.hpp"

namespace vcl = viennacl;

// Abstract Class
class Layer
{
private:
    
public:
    int numNeurons;

    Layer(int numNeurons): numNeurons(numNeurons) {}
    virtual Neuron getNeuron(int neuronNumber) {}
    virtual ~Layer() {}
};
