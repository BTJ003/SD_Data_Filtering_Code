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
	unsigned short RudderDegree  
} DriverRudder;

#endif STRUCTS_H
