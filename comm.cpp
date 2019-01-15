#include "comm.h"

//---Setters---
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

//---Getters---
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

//--Utils--
void print_pkg(package pkg){
	cout << "mode: " << get_mode(pkg) << "\n";
	cout << "gps_isValid: " << get_gps_isValid(pkg) << "\n";
	cout << "gps_lat: " << get_gps_lat(pkg) << "\n";
	cout << "gps_lng: " << get_gps_lng(pkg) << "\n";
	cout << "gps_hdop_value: " << get_gps_hdop_value(pkg) << "\n";
	cout << "gps_satellites_value: " << get_gps_satellites_value(pkg) << "\n";
	cout << "gps_altitude_meters: " << get_gps_altitude_meters(pkg) << "\n";
	cout << "gps_course_deg: " << get_gps_course_deg(pkg) << "\n";
	cout << "gps_speed_kmph: " << get_gps_speed_kmph(pkg) << "\n";
	cout << "bpm_temperature: " << get_bpm_temperature(pkg) << "\n";
	cout << "bpm_altitude: " << get_bpm_altitude(pkg) << "\n";
	cout << "bpm_pressure: " << get_bpm_pressure(pkg) << "\n";
	cout << "status_sd: " << get_status_sd(pkg) << "\n";
	cout << "bar_speed: " << get_bar_speed(pkg) << "\n";
	cout << "is_open: " << get_is_open(pkg) << "\n";
}

int main(){

	package pkg;
	uint8_t* pkg_data;
	
	cout << "Size of pkg: " << sizeof(pkg) << "\n";
	
	//Package initialization
	set_mode(&pkg, 3);
	set_gps_isValid(&pkg, 6);
	set_gps_lat(&pkg, 2);
	set_gps_lng(&pkg, 5);
	set_gps_hdop_value(&pkg, 3);
	set_gps_satellites_value(&pkg, 1);
	set_gps_altitude_meters(&pkg, 1);
	set_gps_course_deg(&pkg, 1);
	set_gps_speed_kmph(&pkg, 1);
	set_bpm_temperature(&pkg, 1);
	set_bpm_altitude(&pkg, 1);
	set_bpm_pressure(&pkg, 1);
	set_status_sd(&pkg, 1);
	set_bar_speed(&pkg, 4);
	set_is_open(&pkg, 257);

	print_pkg(pkg);
		
	return 0;
}
