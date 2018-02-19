#include "transformation.h"

AIData transformDataToAI(DriverData in){
	AIData out;
	//Check for validity
	if(25 > DriverData.Lng)
        	return 0; // unsure how to make request for new data 
	if(DriverData.Lng > 50)
        	return 0; // unsure how to make request for new data  
	if(-125 > DriverData.Lat)
        	return 0; // unsure how to make request for new data 
	if(DriverData.Lat > -65)
        	return 0; // unsure how to make request for new data

	//Make transformations ex. out.Lng = in.Lng + 1.265;
	return out;
}



DriverRudder transformRudderToDriver(AIRudder in){
	DriverRudder out;
	// Check Validity
	if(AIRudder.RudderDegree > 100)
		return 0; // Send call for new data from AI
	if(AIRudder.RudderDegree < -100)
		return 0; // Send call for new data from AI
	
	//Make transformations
	unsigned short interlude = float truncf(AIRudder.RudderDegree);
	DriverRudder.RudderDegree = (interlude*10)+2000;
	return out;
}

