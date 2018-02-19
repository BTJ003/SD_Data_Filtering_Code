#include <stdio.h>
#include <HEADERTRANSFORM.h>

float Data_to_AI_Transform(float DriverData.Lng,float DriverData.Lat,float DriverData.Heading,float AIData.Lng,float AIData.Lat,float AIData.Heading) 
{
    if(25 > DriverData.Lng)
        return 0; /* unsure how to make request for new data */
    if(DriverData.Lng > 50)
        return 0; /* unsure how to make request for new data */ 
    if(-125 > DriverData.Lat)
        return 0; /* unsure how to make request for new data */
    if(DriverData.Lat > -65)
        return 0; /* unsure how to make request for new data */ 
    
    
    /*When I know both forms I can create equations to properly convert these*/
    AIData.Lng = DriverData.Lng;
    AIData.Lat = DriverData.Lat;
    AIData.Heading = DriverData.Heading;
    
    /*Need to determine how the rudder works and determine proper transformation for this data*/
    DriverRudder.RudderDegree = AIRudder.RudderDegree;
    
    return 0;
 }
  
