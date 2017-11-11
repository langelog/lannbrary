#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(QString modelPath) {
    if(!readJsonModel(modelPath, modelTopology)) {
        qDebug() << "Failed to read model";
    } else {
        qDebug() << QJsonDocument(modelTopology).toJson().toStdString().c_str();
    }
}

bool NeuralNetwork::readJsonModel(QString modelPath, QJsonObject &outputModel) {
    QString jsonText;
    QFile file;
    file.setFileName(modelPath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    jsonText = file.readAll();
    file.close();

    QJsonParseError err;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonText.toUtf8(), &err);
    if(err.error != QJsonParseError::NoError)
        return false;

    outputModel = jsonDoc.object();
    return true;
}


