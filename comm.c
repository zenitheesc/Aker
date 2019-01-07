#include "comm.h"

void set_mode(package * pkg, int32_t mode){
	pkg->mode = mode;	
}

void set_gps_isValid(package * pkg, int32_t gps_isValid){
	pkg->gps_isValid = gps_isValid;
}

void set_gps_lat(package * pkg, int32_t gps_lat){
	pkg->gps_lat = gps_lat;
}

void set_gps_lng(package * pkg, int32_t gps_lng){
	pkg->gps_lng = gps_lng;
}

void set_gps_hdop_value(package * pkg, int32_t gps_hdop_value){
	pkg->gps_hdop_value = gps_hdop_value;
}

void set_gps_satellites_value(package * pkg, int32_t gps_satellites_value){
	pkg->gps_satellites_value = gps_satellites_value;
}

void set_gps_altitude_meters(package * pkg, int32_t gps_altitude_meters){
	pkg->gps_altitude_meters = gps_altitude_meters;
}

void set_gps_course_deg(package * pkg, int32_t gps_course_deg){
	pkg->gps_course_deg = gps_course_deg;
}

void set_gps_speed_kmph(package * pkg, int32_t gps_speed_kmph){
	pkg->gps_speed_kmph = gps_speed_kmph;
}

void set_bpm_temperature(package * pkg, int32_t bpm_temperature){
	pkg->bpm_temperature = bpm_temperature;
}

void set_bpm_altitude(package * pkg, int32_t bpm_altitude){
	pkg->bpm_altitude = bpm_altitude;
}

void set_bpm_pressure(package * pkg, int32_t bpm_pressure){
	pkg->bpm_pressure = bpm_pressure;
}

void set_status_sd(package * pkg, int32_t status_sd){
	pkg->status_sd = status_sd;
}

void set_bar_speed(package * pkg, int32_t bar_speed){
	pkg->bar_speed = bar_speed;
}

void set_is_open(package * pkg, int32_t is_open){
	pkg->is_open = is_open;
}

int32_t get_mode(package pkg){
	return pkg.mode;
}

int32_t get_gps_isValid(package pkg){
	return pkg.gps_isValid;
}

int32_t get_gps_lat(package pkg){
	return pkg.gps_lat;
}

int32_t get_gps_lng(package pkg){
	return pkg.gps_lng;
}

int32_t get_gps_hdop_value(package pkg){
	return pkg.gps_hdop_value;
}

int32_t get_gps_satellites_value(package pkg){
	return pkg.gps_satellites_value;
}

int32_t get_gps_altitude_meters(package pkg){
	return pkg.gps_altitude_meters;
}

int32_t get_gps_course_deg(package pkg){
	return pkg.gps_course_deg;
}

int32_t get_gps_speed_kmph(package pkg){
	return pkg.gps_speed_kmph;
}

int32_t get_bpm_temperature(package pkg){
	return pkg.bpm_temperature;
}

int32_t get_bpm_altitude(package pkg){
	return pkg.bpm_altitude;
}

int32_t get_bpm_pressure(package pkg){
	return pkg.bpm_pressure;
}

int32_t get_status_sd(package pkg){
	return pkg.status_sd;
}

int32_t get_bar_speed(package pkg){
	return pkg.bar_speed;
}

int32_t get_is_open(package pkg){
	return pkg.is_open;
}

void print_pkg(package pkg){
	printf("mode: %d\n", get_mode(pkg));
	printf("gps_isValid: %d\n", get_gps_isValid(pkg));
	printf("gps_lat: %d\n", get_gps_lat(pkg));
	printf("gps_lng: %d\n", get_gps_lng(pkg));
	printf("gps_hdop_value: %d\n", get_gps_hdop_value(pkg));
	printf("gps_satellites_value %d\n", get_gps_satellites_value(pkg));
	printf("gps_altitude_meters %d\n", get_gps_altitude_meters(pkg));
	printf("gps_course_deg %d\n", get_gps_course_deg(pkg));
	printf("gps_speed_kmph %d\n", get_gps_speed_kmph(pkg));
	printf("bpm_temperature %d\n", get_bpm_temperature(pkg));
	printf("bpm_altitude %d\n", get_bpm_altitude(pkg));
	printf("bpm_pressure %d\n", get_bpm_pressure(pkg));
	printf("status_sd %d\n", get_status_sd(pkg));
	printf("bar_speed %d\n", get_bar_speed(pkg));
	printf("is_open %d\n", get_is_open(pkg));
}

int main(){

	package pkg;

	//Package initialization
	set_mode(&pkg, 1);
	set_gps_isValid(&pkg, 1);
	set_gps_lat(&pkg, 1);
	set_gps_lng(&pkg, 1);
	set_gps_hdop_value(&pkg, 1);
	set_gps_satellites_value(&pkg, 1);
	set_gps_altitude_meters(&pkg, 1);
	set_gps_course_deg(&pkg, 1);
	set_gps_speed_kmph(&pkg, 1);
	set_bpm_temperature(&pkg, 1);
	set_bpm_altitude(&pkg, 1);
	set_bpm_pressure(&pkg, 1);
	set_status_sd(&pkg, 1);
	set_bar_speed(&pkg, 1);
	set_is_open(&pkg, 1);
	
	//Show package data
	print_pkg(pkg);

	return 0;
}
