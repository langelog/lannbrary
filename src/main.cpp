#include <iostream>
#include <fstream>

#include "NeuralNetwork.h"

using namespace std;

int main(int argc, char *argv[]) {
    ifstream ifs;

    std::cout << "running" << std::endl;
    ifs.open("examples/data/model_or.lann", std::ifstream::in);

    char c = ifs.get();

    while (ifs.good()) {
        std::cout << c;
        c = ifs.get();
    }

    ifs.close();

    return 0;
}
