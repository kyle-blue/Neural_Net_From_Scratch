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
    vcl::vector<float> getLayerOutput(vcl::vector<float> layerInputs);
    ~DenseLayer(){}
private:
    Layer &prevLayer;
    void initBiasVector();
    void initWeightsMatrix();
};