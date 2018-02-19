#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct DriverData
{
	float Lng;
	float Lat;
	float Heading;
} DriverData;

typedef struct AIData
{
	float Lng;
	float Lat;
	float Heading;
} AIData;

typedef struct AIRudder
{
	float RudderDegree
} AIRudder;

typedef struct DriverRudder
{
	float RudderDegree  /* unsure if this is the proper form */
} DriverRudder;

#endif STRUCTS_H
