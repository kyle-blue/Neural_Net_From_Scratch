#pragma once

#include <vector>
#include "Layer.hpp"
#include <memory>


class NeuralNetwork
{
private:
public:
    using LayerPointer = std::shared_ptr<Layer>;
    std::vector<LayerPointer> layers;
    NeuralNetwork(std::vector<int> layerNumbers);

    void printWeights();
    vcl::vector<float> forwardProp(vcl::vector<float> inputs);
};