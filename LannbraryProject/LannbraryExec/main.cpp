#include <QCoreApplication>

#include <Lannbrary.h>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    //NeuralNetwork myNN("/Users/langelog/Git/lannbrary/Examples/Data/model_OR.lann");
    double inputs[] = {1.0, 1.0};

    std::default_random_engine randEngine;

    Neuron myNeuron(2,
                    &(ActivationFunctions::fast_sigmoid),
                    &(ActivationFunctions::reverse_fast_sigmoid),
                    Initializators::Constant,
                    (void*)&Initializators::ConstantInitializer,
                    Initializators::ConstantParamsGen(1.0));
    qDebug() << myNeuron.evaluate(inputs);

    Neuron myNeuron2(2,
                    &(ActivationFunctions::fast_sigmoid),
                    &(ActivationFunctions::reverse_fast_sigmoid),
                    Initializators::Constant,
                    (void*)&Initializators::NormalDistributionInitializer,
                    Initializators::GaussParamsGen(randEngine, 0.0, 1.0));

    qDebug() << myNeuron2.evaluate(inputs);

    return a.exec();
}
