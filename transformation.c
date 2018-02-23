#include "transformation.h"

//Set SWITCH_LEFT_RIGHT to a value other than 0 to invert the left-right rudder values
#define SWITCH_LEFT_RIGHT 0

AIData transformDataToAI(DriverData in){
	AIData out;
	out.valid = true;
	
	//Check for validity
	if(25 > in.lng){
        	out.valid = false;
			return out;
	}else if(in.lng > 50){
        	out.valid = false;
			return out;
	}if(-125 > in.lat){
        	out.valid = false;
			return out;
	}else if(in.lat > -65){
        	out.valid = false;
			return out;
	}
	//Make transformations ex. out.Lng = in.Lng + 1.265;
	out.lat = in.lat;
	out.lng = in.lng;
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

