#ifndef __DATA_H
#define __DATA_H

#include <iostream>

using namespace std;

template<class T>
class Data {
public:

	Data() {

	}

	Data(int dim) {
		_data = new T[dim];
		_dimension = dim;
	};

	Data(int dim, T* input, int out) {
		_dimension = dim;
		_data = new T[dim];
		for (int i = 0 ; i < dim ; i++) {
			_data[i] = input[i];
		}
		_output = out;
	}

	~Data() {
		//delete _data;
	};

	T operator [](int) const;
    T& operator [](int);

    const int output() const;
    const void print() const;

    void setDimension(int);
    void setInput(T*);
    void setOutput(int);
    

private:
	T* _data;
	int _output;
	int _dimension;
};

#endif