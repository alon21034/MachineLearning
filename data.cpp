#ifndef __DATA_CPP
#define __DATA_CPP

#include "data.h"

float Data::operator[](int n) const {
	return _data[n];
}

float& Data::operator[](int n) {
	return _data[n];
}

const int Data::output() const {
	return _output;
}

const void Data::print() const {
	cout << "data: ";
	for (int i = 0 ; i < _dimension ; ++i) {
		cout << _data[i] << "   ";
	}
	cout << '\t' << _output << endl;
}

void Data::setInput(float* in) {
	for (int i = 0 ; i < _dimension ; ++i) {
		_data[i] = in[i];
	}
}

void Data::setOutput(int out) {
	_output = out;
}

void Data::setDimension(int dim) {
	_data = new float[dim];
	_dimension = dim;
}

#endif