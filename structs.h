#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdbool.h>

typedef struct DriverData
{
	float lng;
	float lat;
	float heading;
	bool valid;
} DriverData;

typedef struct AIData
{
	float lng;
	float lat;
	float heading;
	bool valid;
} AIData;

typedef struct AIRudder
{
	float rudderDegree;
	bool valid;
} AIRudder;

typedef struct DriverRudder
{
	unsigned short rudderDegree; 
	bool valid;
} DriverRudder;

#endif
