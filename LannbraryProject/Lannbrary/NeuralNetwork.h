#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <QDebug>

#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>

#include "Neuron.h"

class NeuralNetwork {
public:
    NeuralNetwork(QString modelPath);

    QJsonObject modelTopology;

private:
    bool readJsonModel(QString modelPath, QJsonObject& outputModel);
};

#endif // NEURALNETWORK_H
