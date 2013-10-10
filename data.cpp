#ifndef __DATA_CPP
#define __DATA_CPP

#include "data.h"

template<class T>
T Data<T>::operator[](int n) const {
	return _data[n];
}

template<class T>
T& Data<T>::operator[](int n) {
	return _data[n];
}

template<class T>
const int Data<T>::output() const {
	return _output;
}

template<class T>
const void Data<T>::print() const {
	for (int i = 0 ; i < _dimension ; ++i) {
		cout << _data[i] << "   ";
	}
	cout << '\t' << _output << endl;
}

template<class T>
void Data<T>::setInput(T* in) {
	for (int i = 0 ; i < _dimension ; ++i) {
		_data[i] = in[i];
	}
}

template<class T>
void Data<T>::setOutput(int out) {
	_output = out;
}

template<class T>
void Data<T>::setDimension(int dim) {
	_data = new T[dim];
	_dimension = dim;
}

#endif