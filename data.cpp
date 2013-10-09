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
int Data<T>::output() {
	return _output;
}

template<class T>
void Data<T>::print() {
	for (int i = 0 ; i < _dimension ; ++i) {
		cout << _data[i] << "   ";
	}
	cout <<endl;
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
