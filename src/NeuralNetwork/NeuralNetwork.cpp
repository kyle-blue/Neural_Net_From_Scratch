#include "NeuralNetwork.hpp"
#include "InputLayer.hpp"
#include "DenseLayer.hpp"

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