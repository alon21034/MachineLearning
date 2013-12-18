#include <stdio.h>
#include <stdlib.h>

#include "PLA.h"

using namespave std;

int main(int argc, char** argv) {
	
	PLAEngine *engine = new PLAEngine();
	DataList *data = new DataList();

	for (int i = 0 ; i < data->length() ; ++i) {
		engine->nextStep(data->getData());
	}

	engine->printResult();

}