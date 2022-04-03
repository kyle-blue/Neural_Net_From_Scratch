#pragma once

#include <vector>
#include "Layer.hpp"

class NeuralNetwork
{
private:
    std::vector<Layer> layers;
public:
    NeuralNetwork(/* args */);
    ~NeuralNetwork();
};