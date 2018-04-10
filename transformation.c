#include "transformation.h"

//Set SWITCH_LEFT_RIGHT to a value other than 0 to invert the left-right rudder values
#define SWITCH_LEFT_RIGHT 0

AIData transformDataToAI(DriverData in){
	AIData out;
	out.valid = true;
	
	//Check for validity
	if(36.0 > in.lng){
        	out.valid = false;
			return out;
	}else if(in.lng > 36.2){
        	out.valid = false;
			return out;
	}if(-94.0 > in.lat){
        	out.valid = false;
			return out;
	}else if(in.lat > -94.35){
        	out.valid = false;
			return out;
	}
	// transformations
	float latPlaceholder = in.lat;
	out.lat = latPlaceholder;
	float lngPlaceholder = in.lng;
	out.lng = lngPlaceholder;
	// interheading =              //Want it in float -180 to 180
	out.heading = in.heading;
	return out;
}



DriverRudder transformRudderToDriver(AIRudder in){
	DriverRudder out;
	out.valid = true;
	
	// Check Validity
	if(in.rudderDegree > 100){
		out.valid = false;
		return out;
	}else if(in.rudderDegree < -100){
		out.valid = false;
		return out;
	}
	
	//Make transformations
	
	#if SWITCH_LEFT_RIGHT
	in.rudderDegree *= -1;
	#endif
	
	float interlude = (in.rudderDegree*1000)+3000;
	out.rudderDegree = truncf(interlude);

	return out;
}

//AIDestination transformDestinationtoAI(DriverDestination in){
//	AIDestination out;
//	out.valid = true;
//	
//	//Check Validity
//	
//	//Transformation here
//	float latPlaceholder = in.lat;
//	out.lat = latPlaceholder;
//	float lonPlaceholder = in.lng;
//	out.lng = lngPlaceholder;
//	
//	return out;
}
