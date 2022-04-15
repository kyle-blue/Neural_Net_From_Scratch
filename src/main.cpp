#include <iostream>
#include <ctime>
#include "NeuralNetwork/NeuralNetwork.hpp"

int main() {
    std::vector<int> layerNumbers = {256, 16, 16, 16, 10, 2};
    NeuralNetwork ann(layerNumbers);
    std::cout << "Hello World - " << ann.layers.size() << std::endl;
    // ann.printWeights();

    std::srand((unsigned int)std::time(nullptr));
    std::vector<float> inputs(layerNumbers[0], 0.0f);
    for (int i = 0; i < inputs.size(); i++)
        inputs[i] = (std::rand() / static_cast<float>(RAND_MAX)) - 0.5f;


    vcl::vector<float> inputVec(inputs.size());
    vcl::copy(inputs.begin(), inputs.end(), inputVec.begin());

    auto outputs = ann.forwardProp(inputVec);
    return 0;
}