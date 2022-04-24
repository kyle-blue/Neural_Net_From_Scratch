#include "DenseLayer.hpp"
#include "viennacl/linalg/prod.hpp"
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include <ctime>
#include <iomanip>

DenseLayer::DenseLayer(int numNeurons, Layer &prevLayer, Activation activation):
Layer(numNeurons), prevLayer(prevLayer), activation(activation), biasVector(numNeurons), weightsMatrix(numNeurons, prevLayer.numNeurons)
{
    initBiasVector();
    initWeightsMatrix();
}

void DenseLayer::initBiasVector() {
    // In general practice biases are initialized with 0 and weights are initialized with random numbers
    std::vector<float> biases(numNeurons, 0.0);
    vcl::copy(biases, biasVector);
}

/**
 * @brief Initialises the weights matrix with random values from a norm dist with a mean of 0 and 
 * a variance of numInputs.
 */
void DenseLayer::initWeightsMatrix() {
    std::srand((unsigned int) std::time(nullptr));
    const float UPPER_BOUND = sqrt(1 / prevLayer.numNeurons);
    const float LOWER_BOUND = -sqrt(1 / prevLayer.numNeurons);
    const float RANGE = UPPER_BOUND - LOWER_BOUND;


    for (int i = 0; i < numNeurons; i++) {
        for (int j = 0; j < prevLayer.numNeurons; j++) {
            weightsMatrix(i, j) = (rand() / RAND_MAX * RANGE) + LOWER_BOUND;
        }
    }
}

void DenseLayer::printWeights() {
    std::cout << std::fixed;
    std::cout << std::setprecision(2);

    for (int i = 0; i < numNeurons; i++) {
        for (int j = 0; j < prevLayer.numNeurons; j++) {
            std::string ws = "";
            if (weightsMatrix(i, j) >= 0)
                ws = " ";
            std::cout << ws << weightsMatrix(i, j) << ", ";
        }
        std::cout << std::endl;
    }
}


// Does Forward Prop
vcl::vector<float> DenseLayer::getLayerOutput(vcl::vector<float> layerInputs) {
    vcl::vector<float> product = vcl::linalg::prod(weightsMatrix, layerInputs);
    vcl::vector<float> outputsNoActivation = product + biasVector;
    std::vector<float> outputs(outputsNoActivation.size(), 0.0f);

    for (int i = 0; i < outputs.size(); i++)
        outputs[i] = activation.getOutput(outputsNoActivation(i));

    vcl::vector<float> ret(outputs.size());
    vcl::copy(outputs.begin(), outputs.end(), ret.begin());
    return ret;
}
