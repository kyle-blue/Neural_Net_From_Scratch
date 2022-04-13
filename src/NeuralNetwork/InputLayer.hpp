#include "Layer.hpp"

class InputLayer: public Layer
{
private:
public:
    InputLayer(int numNeurons): Layer(numNeurons) {}
};