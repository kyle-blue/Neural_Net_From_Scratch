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
    vcl::matrix<float> weightsMatrix;

    Layer(int numNeurons): numNeurons(numNeurons) {}
    Neuron getNeuron(int neuronNumber);
};
