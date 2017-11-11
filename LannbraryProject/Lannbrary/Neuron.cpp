#include "Neuron.h"

double ActivationFunctions::fast_sigmoid(double x) {
    return x/(1+abs(x));
}
double ActivationFunctions::reverse_fast_sigmoid(double x) {
    return (x>0)? (x/(x+1)) : (x/(1-x));
}

void Initializators::ConstantInitializer(double *weigths, unsigned int n_values, double value) {
    for(unsigned int i=0; i<n_values; i++) {
        weigths[i] = value;
    }
}
void** Initializators::ConstantParamsGen(double value) {
    void **vals;
    double* val = new double;
    *val = value;
    vals = new void*[1];
    vals[0] = (void*)val;
    return vals;
}
void Initializators::NormalDistributionInitializer(double *weights, unsigned int n_values, std::__1::default_random_engine &randEngine, double mean, double dev) {

    std::normal_distribution<double> dist(mean,dev);
    for(unsigned int i=0; i<n_values; i++) {
        double val = dist(randEngine);
        //std::cout << "Value: " << val << std::endl;
        weights[i] = val;
    }
}
void** Initializators::GaussParamsGen(std::__1::default_random_engine &randEngine, double mean, double dev) {
    void **vals;
    double* val_mean = new double;
    double* val_dev  = new double;
    *val_mean = mean;
    *val_dev  = dev;
    vals = new void*[3];
    vals[0] = (void*)&randEngine;
    vals[1] = (void*)val_mean;
    vals[2] = (void*)val_dev;
    return vals;
}

Neuron::Neuron(unsigned int n_inputs,
               double       (*activationFn)(double),
               double       (*reverseFn)(double),
               Initializators::InitializatorType init,
               void          *initializer,
               void         **vals) {


    this->n_inputs     = n_inputs;
    this->activationFn = activationFn;
    this->reverseFn    = reverseFn;

    this->weights = new double[n_inputs];

    switch(init) {
    case InitializatorType::Constant:
        ((void (*)(double*,unsigned int,double))initializer)(weights, n_inputs, *((double*)vals[0]));
        //delete (double*)vals[0];
        //delete[] vals;
        break;
    case InitializatorType::Gauss:
        ((void (*)(double*,unsigned int,std::default_random_engine&,double,double))initializer)(weights, n_inputs, *((std::default_random_engine*)vals[0]), *((double*)vals[1]), *((double*)vals[2]));

        //delete (double*)vals[1]; // free double held for mean value
        //delete (double*)vals[2]; // free double held for deviation value
        //delete[] vals;
        break;
    default:

        break;
    }
}

Neuron::~Neuron() {
    delete[] this->weights;
}

double Neuron::evaluate(double *inputs) {
    double output = 0.0;
    for(unsigned int i=0; i<n_inputs; i++) {
        output += inputs[i]*weights[i];
    }
    return output;
}

