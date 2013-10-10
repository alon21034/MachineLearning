#ifndef __PLA_H
#define __PLA_H

#include "data.h"

class PLAEngine{
public:

	PLAEngine(int dim) {
		_dimension = dim;
		init();
	}

	~PLAEngine() {

	}

	void start(Data*, int);

	int next(Data);
	void print();

private:
	void init();

	float* _w;
	int _dimension;

	int _timer;
	int _updateNum;
};

#endif