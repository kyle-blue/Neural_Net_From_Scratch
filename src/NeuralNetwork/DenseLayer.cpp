#include "DenseLayer.hpp"
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
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
    const float MEAN = 0;
    
    unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine randEngine(seed);
    // std dev should be sqrt numNeurons to avoid vanishing or exploding gradient
    // TODO: retrun to this for understanding
    std::normal_distribution<float> norm{0, sqrt(prevLayer.numNeurons)};
    
    for (int i = 0; i < numNeurons; i++) {
        for (int j = 0; j < prevLayer.numNeurons; j++) {
            weightsMatrix(i, j) = norm(randEngine);
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


