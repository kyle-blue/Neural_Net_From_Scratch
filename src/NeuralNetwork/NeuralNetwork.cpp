#include "NeuralNetwork.hpp"
#include "InputLayer.hpp"
#include "DenseLayer.hpp"

#include <iostream>
#include <iomanip>

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

vcl::vector<float> NeuralNetwork::forwardProp(vcl::vector<float> inputs){
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    
    vcl::vector<float> nextInput = inputs;
    for(int i = 0; i < layers.size(); i++) {
        auto denseLayer = dynamic_cast<DenseLayer*>(layers[i].get());
        if (denseLayer != nullptr) {
            std::cout << "Dense Layer " << i << " outputs: ";
            auto output = denseLayer->getLayerOutput(nextInput);
            for(float out: output)
                std::cout << out << ", ";
            std::cout << std::endl;
            nextInput.clear();
            nextInput.resize(denseLayer->numNeurons);
            nextInput = output;
        }
    }
    return nextInput;
}
