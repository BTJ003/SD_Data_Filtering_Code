#include "structs.h"
#include "transformation.h"

//gps gps_struct;

const CHAR * PMTK_STANDBY = "s";
const CHAR * PMTK_AWAKE = "a";

volatile CHAR line1[MAXLINELENGTH];
volatile CHAR line2[MAXLINELENGTH];
// our index into filling the current line
volatile UINT8 lineidx=0;
// pointers to the double buffers
volatile CHAR *currentline;
volatile CHAR *lastline;
volatile BOOL recvdflag;
volatile BOOL inStandbyMode;

BOOL paused, locationUpdate, fix;

UINT8 hour, minute, seconds, year, month, day, fixquality, satellites;
CHAR lat, lon, mag;
UINT16 milliseconds;
UINT32 latitude, longitude, latitudeDegrees, longitudeDegrees;

void gps_main() {
	return;
}

void gps_init() {
	recvdflag = false;
	paused = false;
	locationUpdate = false;
	lineidx = 0;
	currentline = line1;   
	lastline = line2;
	
	hour = minute = seconds = year = month = day = fixquality = satellites = 0; //UINT8
	lat = lon = mag = 0; //CHAR
	fix = false; //BOOL
	milliseconds = 0; //UINT16
	latitude = longitude = 0; 
}

