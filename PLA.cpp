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

void PLAEngine::start(Data<float>* dataList, int num) {
	cout << "dimension = " << _dimension << endl;
	
	for (int n = 0 ; n < 60 ; n++) {
		cout << "n = " << n << endl;
		bool b = true;
		for (int i = 0 ; i < num ; i++ ){
			//cout << "i = " << i << endl;
			bool t = next(dataList[i]);

			b = t & b;
		}

		if(b) {
			cout << "finished: " << _updateNum << endl;
			break;
		} else {
			cout << "continue" << endl;
		}
	}

	cout << _updateNum << endl;
}

bool PLAEngine::next(const Data<float> data) {

	_timer++;

	float accumulate = 0.0f;
	for (int i = 0 ; i < _dimension ; ++i) {
		accumulate += _w[i] * data[i];
	}

	float sign = (accumulate >= 0.0f)? 1:-1;
	float y_n = data.output();

	if(sign * y_n < 0) {
		for (int i = 0 ; i < _dimension ; i++) {
			_w[i] += y_n * data[i];
		}
		_updateNum++;

		data.print();
		print();
		return false;
	} else {
		//print();
		return true;
	}
}

void PLAEngine::print() {
	cout << "step: " << _timer << "(" << _updateNum << ")" << endl;
	for (int i = 0 ; i < _dimension ; ++i) {
		cout << _w[i] << '\t';
	}
	cout << endl;
}
