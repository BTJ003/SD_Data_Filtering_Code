#include <stdio.h>
#include <stdlib.h>

#include "transformation.h"

char *nmea = "$GPGGA,172814.0,3723.46587704,N,12202.26957864,W,2,6,1.2,18.893,M,-25.669,M,2.0,0031*4F"
float INCREMENT = 5.0;
float LAT_VALID = -80.0;
float LNG_VALID = 35;
bool ValidRun = true;
gps_init();

int main(){
	ValidRun = gps_parse(nmea);
	printf("Test Latitude is %d /n", DriverData.lat);
	printf("Test Longitude is %d /n", DriverData.lng);
	printf("/n");

	/*
	for(float i = 15; i <= 60; i+=INCREMENT){ //For Longitude
		DriverData input;
		input.lng = i;
		input.lat = DriverData.lat;
		AIData test = transformDataToAI(input);
		if(test.valid){
			printf("The input Longitude was %f and the transformed value is: %f\n", i, test.lng);
		} else{
			printf("The input Longitude was %f and is not valid\n", i);
		}
	}
	for(float i = -135; i <= -55; i+=INCREMENT){ //For Latitude
		DriverData input;
		input.lat = i;
		input.lng = DriverData.lng;
		AIData test = transformDataToAI(input);
		if(test.valid){
			printf("The input Latitude was %f and the transformed value is: %f\n", i, test.lat);
		} else{
			printf("The input Latitude was %f and is not valid\n", i);
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
	*/
}
