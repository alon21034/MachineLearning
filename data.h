#ifndef __DATA_H
#define __DATA_H

#include <iostream>

using namespace std;

class Data {
public:

	Data() {

	}

	Data(int dim) {
		_data = new float[dim];
		_dimension = dim;
	};

	Data(int dim, float* input, int out) {
		_dimension = dim;
		_data = new float[dim];
		for (int i = 0 ; i < dim ; i++) {
			_data[i] = input[i];
		}
		_output = out;
	}

	~Data() {
		//delete _data;
	};

	float operator [](int) const;
    float& operator [](int);

    const int output() const;
    const void print() const;

    void setDimension(int);
    void setInput(float*);
    void setOutput(int);
    

private:
	float* _data;
	int _output;
	int _dimension;
};

#endif