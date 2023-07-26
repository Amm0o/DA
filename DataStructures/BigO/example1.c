#include <stdio.h>

void findNemo(char** array) {

	int arrSize = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < arrSize; i++) {
		if (array[i] == "nemo") printf("We found Nemo!");
	}	
	
}


int main(void) {
	char *nemo[] = {"nemo"};
	findNemo(nemo);	
}
