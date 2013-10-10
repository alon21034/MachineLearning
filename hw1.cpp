#include <iostream>
#include <fstream>

#include "data.h"
#include "data.cpp"
#include "PLA.h"

using namespace std;

int main(int argc, char** argv) {

	// read file
	ifstream *inFile = new ifstream("hw1_15_train.dat");

    float *x = new float[5];
    int y;
    int num = 0;
    while(*inFile >> x[0] >> x[1] >> x[2] >> x[3] >> y) {
    	num++;
    }
    cout << "total data num: " << num << endl;
    inFile->close();
    inFile->open("hw1_15_train.dat");

    Data<float> *dataList = new Data<float>[num];
    num = 0;
	while(*inFile >> x[1] >> x[2] >> x[3] >> x[4] >> y) {
		x[0] = 1;
		dataList[num].setDimension(5);
		dataList[num].setInput(x);
		dataList[num].setOutput(y);
		num++;
	}

	// start PLA

	PLAEngine pla(5);
	pla.start(&dataList[0], num);


}