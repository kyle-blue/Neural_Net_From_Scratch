#pragma once

#include "Neuron.hpp"


class Layer
{
private:
    
public:
    int numNeurons;
    Matrix weightsMatrix;
    Vector biasVector;

    Layer(/* args */);
    ~Layer();

    Neuron getNeuron(int neuronNumber);
};
