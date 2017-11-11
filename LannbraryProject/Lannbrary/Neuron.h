#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <cmath>
#include <random>

namespace InitializatorType {
    typedef enum{
        Constant,
        Uniform,
        Gauss
    } InitializatorType;
}

namespace Initializators {
    typedef enum{
        Constant,
        Uniform,
        Gauss
    } InitializatorType;

    void   ConstantInitializer(double* weigths, unsigned int n_values, double value);
    void** ConstantParamsGen(double value);

    void   NormalDistributionInitializer(double* weights, unsigned int n_values, std::default_random_engine& randEngine, double mean, double dev);
    void** GaussParamsGen(std::default_random_engine& randEngine, double mean=0.0, double dev=1.0);

}

namespace ActivationFunctions {
    double fast_sigmoid(double x);
    double reverse_fast_sigmoid(double x);
}

class Neuron {
public:
    Neuron(unsigned int      n_inputs,
           double            (*activationFn)(double),
           double            (*reverseFn)(double),
           Initializators::InitializatorType init = Initializators::Constant,
           void              *initializatorFunction = NULL,
           void             **vals = NULL);
    ~Neuron();

    double evaluate(double* inputs);

private:
    unsigned int   n_inputs;
    double        *weights;
    double       (*activationFn)(double);
    double       (*reverseFn)(double);

};

#endif // NEURON_H
