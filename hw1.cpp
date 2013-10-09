#include <iostream>
#include <fstream>

#include "data.h"
#include "data.cpp"

using namespace std;

int main(int argc, char** argv) {
	// read file

	ifstream *inFile = new ifstream("hw1_15_train.dat");

    float *x = new float[4];
    int y;
	while(*inFile >> x[1] >> x[2] >> x[3] >> x[4] >> y) {
		Data<float> data(4, x, y);

		
	}
}