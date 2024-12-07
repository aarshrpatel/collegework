#include <iostream>
#include <fstream>
#include <random>

using namespace std;

void generateInputFiles(int size, int count) {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(-100.0, 100.0);

    for (int i = 0; i < count; i++) {
        string filename = "input_" + to_string(size) + "_" + to_string(i) + ".txt";
        ofstream outFile(filename);
        for (int j = 0; j < size; j++) {
            outFile << dist(gen) << " ";
        }
        outFile.close();
    }
}

int main() {
    generateInputFiles(10, 25);
    generateInputFiles(100, 25);
    generateInputFiles(1000, 25);

    cout << "Input file generated.\n";
    return 0;
}