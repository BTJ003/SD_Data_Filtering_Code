#include "structs.h"
#include "transformation.h"

#include <stdio.h>
#include <stlid.h>
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

BOOL gps_parse(char *nmea) {
  // do checksum check

  // first look if we even have one
  if (nmea[str_len(nmea)-4] == '*') {
    UINT16 sum = gps_parseHex(nmea[str_len(nmea)-3]) * 16;
    sum += gps_parseHex(nmea[str_len(nmea)-2]);
    
    UINT8 i;
    // check checksum 
    for (i=2; i < (str_len(nmea)-4); i++) {
      sum ^= nmea[i];
    }
    if (sum != 0) {
      // bad checksum :(
      return false;
    }
  }
  
  UINT32 degree;
  long minutes;
  CHAR degreebuff[10];
  
  // ---------------if the NMEA format is in GPGGA--------------------
  if (str_str(nmea, "$GPGGA")) { 
    // found GGA
    CHAR *p = nmea;
    locationUpdate= true;
    // get time
    p = str_chr(p, ',')+1;
    UINT32 time = atof(p);;
    hour = time / 10000;
    minute = (time % 10000) / 100;
    seconds = (time % 100);

    milliseconds = fmod(time, 1.0) * 1000 + 0.5;

    // parse out latitude
    p = str_chr(p, ',')+1;
    if (',' != *p)
    {
      str_ncpy(degreebuff, p, 2);
      p += 2;
      degreebuff[2] = '\0';
      degree = atol(degreebuff) * 10000000;
      str_ncpy(degreebuff, p, 2); // minutes
      p += 3; // skip decimal point
      str_ncpy(degreebuff + 2, p, 4);
      degreebuff[6] = '\0';
      minutes = 50 * atol(degreebuff) / 3;
      //SJB: PERSONALLY THINK 'latitude' IS THE ONLY ONE WE NEED/CARE ABOUT
      latitude = degree / 100000 + minutes * 0.000006F; 
      latitudeDegrees = (latitude-100*(latitude/100))/60.0;
      latitudeDegrees += (latitude/100);
    }
    
    p = str_chr(p, ',')+1;
    if (',' != *p)
    {
      if (p[0] == 'S') latitudeDegrees *= -1.0;
      if (p[0] == 'N') lat = 'N';
      else if (p[0] == 'S') lat = 'S';
      else if (p[0] == ',') lat = 0;
      else return false;
    }
    
    // parse out longitude
    p = str_chr(p, ',')+1;
    if (',' != *p)
    {
      str_ncpy(degreebuff, p, 3);
      p += 3;
      degreebuff[3] = '\0';
      degree = atol(degreebuff) * 10000000;
      str_ncpy(degreebuff, p, 2); // minutes
      p += 3; // skip decimal point
      str_ncpy(degreebuff + 2, p, 4);
      degreebuff[6] = '\0';
      minutes = 50 * atol(degreebuff) / 3;
      //SJB: PERSONALLY THINK 'longitude' IS THE ONLY ONE WE NEED/CARE ABOUT
      longitude = degree / 100000 + minutes * 0.000006F; 
      longitudeDegrees = (longitude-100*(longitude/100))/60.0;
      longitudeDegrees += (longitude/100);
    }
    
    p = str_chr(p, ',')+1;
    if (',' != *p)
    {
      if (p[0] == 'W') longitudeDegrees *= -1.0;
      if (p[0] == 'W') lon = 'W';
      else if (p[0] == 'E') lon = 'E';
      else if (p[0] == ',') lon = 0;
      else return false;
    }	
    return true;
  } 
  
  DriverData.lng = longitudeDegrees;
  DriverData.lat = latitudeDegrees;
  
/* unsure what this section is for currently
  if (locationUpdate){
      //means that location was updated
      gps_event(latitude, longitude);
      //THIS IS A LITTLE SKETCHY TO ME...LONG AND LAT ARE NEVER DEFINED WITHIN
      //THIS FUNCTION, THEY ARE JUST USED.
  }
  */
  return false;
}//ends parse
