#ifndef __PLA_H
#define __PLA_H

#include "data.h"
#include "data.cpp"

class PLAEngine{
public:

	PLAEngine(int dim) {
		_dimension = dim;
		init();
	}

	~PLAEngine() {

	}

	void start(Data<float>*, int);

	bool next(Data<float>);
	void print();

private:
	void init();

	float* _w;
	int _dimension;

	int _timer;
	int _updateNum;
};

#endif