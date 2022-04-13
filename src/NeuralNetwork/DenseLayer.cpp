#include "DenseLayer.hpp"

DenseLayer::DenseLayer(int numNeurons, Layer &prevLayer, Activation activation):
Layer(numNeurons), prevLayer(prevLayer), activation(activation)
{
    
}
