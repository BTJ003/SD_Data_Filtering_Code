#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdbool.h>
#include <stdint.h>

typedef struct DriverData
{
	UINT32 lng;
	UINT32 lat;
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

typedef struct DriverDestination
{
	float gpsTarget;
	bool valid;
} DriverDestination;

typedef struct AIDestination
{
	float gpsTarget;
	bool valid;
} AIDestination;

#endif
