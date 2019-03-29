#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <iostream>
#include <cstddef>
#include <vector>

#define PACKAGE_SIZE 62 
#define NUM_OF_DATA  15 //number of data in package array
#define NUM_OF_FRAGMENTS 10

using namespace std;

typedef struct package{
	uint32_t mode;
	uint32_t gps_isValid;
	uint32_t gps_lat;
	uint32_t gps_lng;
	uint32_t gps_hdop_value;
	uint32_t gps_satellites_value;
	uint32_t gps_altitude_meters;
	uint32_t gps_course_deg;
	uint32_t gps_speed_kmph;
	uint32_t bpm_temperature;
	uint32_t bpm_altitude;
	uint32_t bpm_pressure;
	uint32_t status_sd;
	uint32_t bar_speed;
	uint32_t is_open;
	//The checksum must ALWAYS be the last package element
	uint32_t checksum; 
}package;

//---Setters---
void set_mode(package *, uint32_t);

void set_gps_isValid(package *, uint32_t);

void set_gps_lat(package *, uint32_t);

void set_gps_lng(package *, uint32_t);

void set_gps_hdop_value(package *, uint32_t);

void set_gps_satellites_value(package *, uint32_t);

void set_gps_altitude_meters(package *, uint32_t);

void set_gps_course_deg(package *, uint32_t);

void set_gps_speed_kmph(package *, uint32_t);

void set_bpm_temperature(package *, uint32_t);

void set_bpm_altitude(package *, uint32_t);

void set_bpm_pressure(package *, uint32_t);

void set_status_sd(package *, uint32_t);

void set_bar_speed(package *, uint32_t);

void set_is_open(package *, uint32_t);

void set_checksum(package *, uint32_t);
//---Getters---
uint32_t get_mode(package);

uint32_t get_gps_isValid(package);

uint32_t get_gps_lat(package);

uint32_t get_gps_lng(package);

uint32_t get_gps_hdop_value(package);

uint32_t get_gps_satellites_value(package);

uint32_t get_gps_altitude_meters(package);

uint32_t get_gps_course_deg(package);

uint32_t get_gps_speed_kmph(package);

uint32_t get_bpm_temperature(package);

uint32_t get_bpm_altitude(package);

uint32_t get_bpm_pressure(package);

uint32_t get_status_sd(package);

uint32_t get_bar_speed(package);

uint32_t get_is_open(package);

uint32_t get_checksum(package);
//---Utils---

//Prints package data using struct
void print_struct_pkg(package);

//Prints a byte
void print_byte(byte&);

//Prints the byte vector
void print_byte_vector(vector<byte>);

//Prints the uint8_t byte array
void print_byte_array(uint8_t*);

//struct to byte vector (vector<byte>)
vector<byte> struct_to_byte_vector(package);

//byte vector to struct
package byte_vector_to_struct(vector<byte>);

//Byte vector to uint8_t array
uint8_t* byte_vector_to_array(vector<byte>);

//uint8_t array to byte vector
vector<byte> array_to_byte_vector(uint8_t*);

//Calculates the checksum
uint32_t checksum(uint8_t*);

//Verify if the package checksum is equal to the
//checksum calculated here
//0 is equal, otherise not equal
uint32_t verify_checksum(uint8_t*);

//This generates a byte vector whith the data of
//the package. The difference is that every byte
//of data is repeated n times in the output
vector<byte> gen_repeated_bytes(vector<byte>, uint8_t);

//This regerates the original vector based on the 
//vector with repeated bytes, by picking the most
//recurrent value of each set of repetition
vector<byte> undo_repeated_bytes(vector<byte>, uint8_t);