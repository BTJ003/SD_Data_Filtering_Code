#include <stdio.h>
#include <stdlib.h>

#include "transformation.h"

float INCREMENT = 5.0;

int main(){
	for(float i = 15; i <= 60, i+=INCREMENT){ //For Longitude
		DriverData input;
		input.lng = i;
		AIData test = transformDataToAI(input);
		if(test.valid){
			printf("The input Longitude was %f and the transformed value is: %i\n", i, test.rudderDegree);
		} else{
			printf("The input Longitude was %f and is not valid\n", i);
		}
	}
	for(float i = -135; i <= -55, i+=INCREMENT){ //For Latitude
		DriverData input;
		input.lat = i;
		AIData test = transformDataToAI(input);
		if(test.valid){
			printf("The input Latitude was %f and the transformed value is: %i\n", i, test.rudderDegree);
		} else{
			printf("The input Latitude was %f and is not valid\n", i);
		}
	}	
	}
	for(float i = -110.0; i <= 110.0; i+=INCREMENT){ //For Rudder
		AIRudder input;
		input.rudderDegree = i;
		DriverRudder test = transformRudderToDriver(input);
		if(test.valid){
			printf("The input Rudder Ratio was %f and the transformed value is: %i\n", i, test.rudderDegree);
		} else{
			printf("The input Rudder Ratio was %f and is not valid\n", i);
		}
	}
}
