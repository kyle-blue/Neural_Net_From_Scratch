#pragma once

#include "Neuron.hpp"
#include "viennacl/matrix.hpp"
#include "viennacl/vector.hpp"

namespace vcl = viennacl;

class Layer
{
private:
    
public:
    int numNeurons;
    vcl::matrix<float> weightsMatrix;
    vcl::vector<float> biasVector;

    Layer(/* args */);
    ~Layer();

    Neuron getNeuron(int neuronNumber);
};
