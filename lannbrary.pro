TEMPLATE = app

INCLUDEPATH += ./include ./thirdparty

SOURCES += src/main.cpp \
    src/Neuron.cpp \
    src/NeuralNetwork.cpp

HEADERS  += \
    include/Neuron.h \
    include/NeuralNetwork.h

DISTFILES += \
    CMakeLists.txt


