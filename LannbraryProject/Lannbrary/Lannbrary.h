#ifndef LANNBRARY_H
#define LANNBRARY_H

#include <QObject>

#include "Neuron.h"
#include "NeuralNetwork.h"

class Lannbrary : public QObject {
    Q_OBJECT
public:
    explicit Lannbrary(QObject* parent = NULL);
};

#endif // LANNBRARY_H
