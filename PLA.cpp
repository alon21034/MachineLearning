#include "PLA.h"

void PLAEngine::init() {
	_w = new float[_dimension];
	// _w[0] = -3;
	// _w[1] = 2.37629;
	// _w[2] = -1.24535;
	// _w[3] = 2.78819;
	// _w[4] = 3.78952;

	// _w[0] = -3;
	// _w[1] = 3.0841436;
	// _w[2] = -1.583081;
	// _w[3] = 2.3913505;
	// _w[4] = 4.5287635;

	for (int i = 0 ; i < _dimension ; ++i) {
		_w[i] = 0;
	}

	_timer = 0;
	_updateNum = 0;
}

void PLAEngine::start(Data* dataList, int num) {
	cout << "dimension = " << _dimension << endl;
	
	for (int n = 0 ; n < 60 ; n++) {
		cout << "n = " << n << endl;
		int b = 0;
		for (int i = 0 ; i < num ; i++ ){
			//cout << "i = " << i << endl;
			b += next(dataList[i]);
		}
		if(b == 400) {
			cout << "finished: " << _updateNum << endl;
			break;
		} else {
			cout << "continue" << endl;
		}
	}

	cout << _updateNum << endl;
}

int PLAEngine::next(const Data data) {

	_timer++;

	//data.print();
	float accumulate = 0.0f;
	//cout << accumulate;
	for (int i = 0 ; i < _dimension ; ++i) {
		accumulate += _w[i] * data[i];
	}

	float sign = (accumulate >= 0.0f)? 1:-1;
	float y_n = data.output();
	cout << accumulate << "   " << y_n << endl;

	if(sign * y_n < 0) {
		for (int i = 0 ; i < _dimension ; i++) {
			_w[i] += y_n * data[i];
		}
		_updateNum++;

		//data.print();
		print();
		return 0;
	} else {
		//print();
		//data.print();
		return 1;
	}
}

void PLAEngine::print() {
	cout << "step: " << _timer << "(" << _updateNum << ")" << endl;
	for (int i = 0 ; i < _dimension ; ++i) {
		cout << _w[i] << '\t';
	}
	cout << endl;
}
