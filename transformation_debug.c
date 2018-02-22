#include <stdio.h>
#include <stdlib.h>

#include "transformation.h"

float INCREMENT = 31.4159;

int main(){
	for(float i = -110.0; i <= 110.0; i+=INCREMENT){
		AIRudder input;
		input.rudderDegree = i;
		DriverRudder test = transformRudderToDriver(input);
		if(test.valid){
			printf("The input was %f and the transformed value is: %i\n", i, test.rudderDegree);
		} else{
			printf("The input was %f and is not valid\n", i);
		}
	}
}