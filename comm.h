#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct package{
	int32_t mode;
	int32_t gps_isValid;
	int32_t gps_lat;
	int32_t gps_lng;
	int32_t gps_hdop_value;
	int32_t gps_satellites_value;
	int32_t gps_altitude_meters;
	int32_t gps_course_deg;
	int32_t gps_speed_kmph;
	int32_t bpm_temperature;
	int32_t bpm_altitude;
	int32_t bpm_pressure;
	int32_t status_sd;
	int32_t bar_speed;
	int32_t is_open;
	uint8_t end_char;
}package;

int32_t get_mode(package);