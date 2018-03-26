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
	// interlat =
	out.lat = in.lat;
	// interlng = 
	out.lng = in.lng;
	// interheading = 
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
	
	float interlude = (in.rudderDegree*15.625)+4687.5;
	out.rudderDegree = truncf(interlude);

	return out;
}

AIDestination transformDestinationtoAI(DriverDestination in){
	AIDestination out;
	out.valid = true;
	
	//Check Validity
	
	//Transformation here
	int latPlaceholder = in.lat;
	out.lat = in.lat;
	int lonPlaceholder = in.lon;
	out.lat = in.lon;
	
	return out;
}
