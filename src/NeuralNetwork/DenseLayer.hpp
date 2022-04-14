#include "Layer.hpp"
#include "Activation.hpp"

class DenseLayer: public Layer
{

public:
    vcl::vector<float> biasVector;
    Activation activation;
    vcl::matrix<float> weightsMatrix; // weights connected between prevLayer and this layer


    DenseLayer(int numNeurons, Layer &prevLayer, Activation activation = Activation::RELU);
    void printWeights();
    ~DenseLayer(){}
private:
    Layer &prevLayer;
    void initBiasVector();
    void initWeightsMatrix();
};