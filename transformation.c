#include "transformation.h"

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
	
	float interlude = (in.rudderDegree*15.625)+4687.5;
	out.rudderDegree = truncf(interlude);

	return out;
}

