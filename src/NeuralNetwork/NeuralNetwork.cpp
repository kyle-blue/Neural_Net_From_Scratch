#include "NeuralNetwork.hpp"
#include "InputLayer.hpp"
#include "DenseLayer.hpp"
#include <iostream>

NeuralNetwork::NeuralNetwork(std::vector<int> layerNumbers) {
    for (int i = 0; i < layerNumbers.size(); i++) {
        int numNeurons = layerNumbers[i];
        Activation activation = (i != layerNumbers.size() - 1 ? Activation::RELU : Activation::SIGMOID);
        if (i == 0) {
            layers.push_back(std::make_shared<InputLayer>(numNeurons));
        } else {
            LayerPointer prevLayer = layers[i - 1];
            layers.push_back(std::make_shared<DenseLayer>(numNeurons, *prevLayer, activation));
        }
    }
}

void NeuralNetwork::printWeights() {
    for(LayerPointer layer: layers) {
        auto denseLayer = dynamic_cast<DenseLayer*>(layer.get());
        if (denseLayer != nullptr) {
            denseLayer->printWeights();
        }
        std::cout << std::endl;
    }
}