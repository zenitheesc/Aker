#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define PACKAGE_SIZE 60 

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
}package;

//---Setters---
void set_mode(package *, int32_t);

void set_gps_isValid(package *, int32_t);

void set_gps_lat(package *, int32_t);

void set_gps_lng(package *, int32_t);

void set_gps_hdop_value(package *, int32_t);

void set_gps_satellites_value(package *, int32_t);

void set_gps_altitude_meters(package *, int32_t);

void set_gps_course_deg(package *, int32_t);

void set_gps_speed_kmph(package *, int32_t);

void set_bpm_temperature(package *, int32_t);

void set_bpm_altitude(package *, int32_t);

void set_bpm_pressure(package *, int32_t);

void set_status_sd(package *, int32_t);

void set_bar_speed(package *, int32_t);

void set_is_open(package *, int32_t);

//---Getters---
int32_t get_mode(package);

int32_t get_gps_isValid(package);

int32_t get_gps_lat(package);

int32_t get_gps_lng(package);

int32_t get_gps_hdop_value(package);

int32_t get_gps_satellites_value(package);

int32_t get_gps_altitude_meters(package);

int32_t get_gps_course_deg(package);

int32_t get_gps_speed_kmph(package);

int32_t get_bpm_temperature(package);

int32_t get_bpm_altitude(package);

int32_t get_bpm_pressure(package);

int32_t get_status_sd(package);

int32_t get_bar_speed(package);

int32_t get_is_open(package);

int8_t get_parity_bit(package);


//---Utils---

//Prints package data using struct
void print_struct_pkg(package);

//Prints array package
void print_array_pkg(uint8_t*);

//Converts a package to byte array
uint8_t* struct_to_byte_array(package);



