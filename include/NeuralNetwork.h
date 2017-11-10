#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "Neuron.h"
#include "json.hpp" // https://github.com/nlohmann/json#integration

#include <iostream>
#include <cassert>

using namespace std;

using json = nlohmann::json;

class NeuralNetwork {
public:
    NeuralNetwork();
};

#endif // NEURALNETWORK_H
