#include "Layer.hpp"
#include "Activation.hpp"

class DenseLayer: public Layer
{
private:
    Layer &prevLayer;
public:
    vcl::vector<float> biasVector;
    Activation activation;
    vcl::matrix<float> weightsMatrix;


    DenseLayer(int numNeurons, Layer &prevLayer, Activation activation = Activation::RELU);
};