#include <iostream>
#include "NeuralNetwork/NeuralNetwork.hpp"

int main() {
    std::vector<int> layerNumbers = {256, 16, 16, 2};
    NeuralNetwork ann(layerNumbers);
    std::cout << "Hello World - " << ann.layers.size() << std::endl;
    ann.printWeights();
    return 0;
}