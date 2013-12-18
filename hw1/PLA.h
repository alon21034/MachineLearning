#include "PLA.h"

struct TrainingData
{
	float *data;
	int size;
};

struct LinearFunction
{
	float* param;
	int size;
};

class PLAEngine {
public:

	PLAEngine();
	~PLAEngine();

	void initialize();
	void reset();
	void nextStep(TrainingData);
	LinearFunction getResult();
	void printResult();

private:

}