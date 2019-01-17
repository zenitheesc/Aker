#include "comm.h"

//---Setters---
void set_mode(package * pkg, uint32_t mode){
	pkg->mode = mode;	
}

void set_gps_isValid(package * pkg, uint32_t gps_isValid){
	pkg->gps_isValid = gps_isValid;
}

void set_gps_lat(package * pkg, uint32_t gps_lat){
	pkg->gps_lat = gps_lat;
}

void set_gps_lng(package * pkg, uint32_t gps_lng){
	pkg->gps_lng = gps_lng;
}

void set_gps_hdop_value(package * pkg, uint32_t gps_hdop_value){
	pkg->gps_hdop_value = gps_hdop_value;
}

void set_gps_satellites_value(package * pkg, uint32_t gps_satellites_value){
	pkg->gps_satellites_value = gps_satellites_value;
}

void set_gps_altitude_meters(package * pkg, uint32_t gps_altitude_meters){
	pkg->gps_altitude_meters = gps_altitude_meters;
}

void set_gps_course_deg(package * pkg, uint32_t gps_course_deg){
	pkg->gps_course_deg = gps_course_deg;
}

void set_gps_speed_kmph(package * pkg, uint32_t gps_speed_kmph){
	pkg->gps_speed_kmph = gps_speed_kmph;
}

void set_bpm_temperature(package * pkg, uint32_t bpm_temperature){
	pkg->bpm_temperature = bpm_temperature;
}

void set_bpm_altitude(package * pkg, uint32_t bpm_altitude){
	pkg->bpm_altitude = bpm_altitude;
}

void set_bpm_pressure(package * pkg, uint32_t bpm_pressure){
	pkg->bpm_pressure = bpm_pressure;
}

void set_status_sd(package * pkg, uint32_t status_sd){
	pkg->status_sd = status_sd;
}

void set_bar_speed(package * pkg, uint32_t bar_speed){
	pkg->bar_speed = bar_speed;
}

void set_is_open(package * pkg, uint32_t is_open){
	pkg->is_open = is_open;
}

//---Getters---
uint32_t get_mode(package pkg){
	return pkg.mode;
}

uint32_t get_gps_isValid(package pkg){
	return pkg.gps_isValid;
}

uint32_t get_gps_lat(package pkg){
	return pkg.gps_lat;
}

uint32_t get_gps_lng(package pkg){
	return pkg.gps_lng;
}

uint32_t get_gps_hdop_value(package pkg){
	return pkg.gps_hdop_value;
}

uint32_t get_gps_satellites_value(package pkg){
	return pkg.gps_satellites_value;
}

uint32_t get_gps_altitude_meters(package pkg){
	return pkg.gps_altitude_meters;
}

uint32_t get_gps_course_deg(package pkg){
	return pkg.gps_course_deg;
}

uint32_t get_gps_speed_kmph(package pkg){
	return pkg.gps_speed_kmph;
}

uint32_t get_bpm_temperature(package pkg){
	return pkg.bpm_temperature;
}

uint32_t get_bpm_altitude(package pkg){
	return pkg.bpm_altitude;
}

uint32_t get_bpm_pressure(package pkg){
	return pkg.bpm_pressure;
}

uint32_t get_status_sd(package pkg){
	return pkg.status_sd;
}

uint32_t get_bar_speed(package pkg){
	return pkg.bar_speed;
}

uint32_t get_is_open(package pkg){
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

//Prints a byte
void print_byte(byte& byte){
	cout << to_integer<uint8_t>(byte) << endl;
}

//Prints the byte vector
void print_byte_vector(vector<byte> byteArr){
	uint8_t i = 0;
	for(i = 0; i < PACKAGE_SIZE; i++){
		cout <<(unsigned)byteArr[i];
	}
}

//Prints the uint8_t byte array
void print_byte_array(uint8_t* buffer){
	uint8_t i = 0;
	for(i = 0; i < PACKAGE_SIZE; i++){
		cout << (unsigned)buffer[i];
	}
}

//struct to byte vector (vector<byte>)
vector<byte> struct_to_byte_vector(package pkg){
	
	//Vector with byte array
	vector<byte> byteArr(PACKAGE_SIZE);

	//Mode
	//Reads the 4 bytes of data
	uint32_t data = get_mode(pkg);

	//Splits the 4 bytes in single bytes
	uint8_t data_1 = (data & 0xff000000UL) >> 24;
	uint8_t data_2 = (data & 0x00ff0000UL) >> 16;
	uint8_t data_3 = (data & 0x0000ff00UL) >> 8;
	uint8_t data_4 = (data & 0x000000ffUL);

	//Asset each byte to the vector of bytes
	byteArr[0] =  byte {data_1};
	byteArr[1] =  byte {data_2};
	byteArr[2] =  byte {data_3};
	byteArr[3] =  byte {data_4};

	//gps_isValid
	data = get_gps_isValid(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[4] =  byte {data_1};
	byteArr[5] =  byte {data_2};
	byteArr[6] =  byte {data_3};
	byteArr[7] =  byte {data_4};

	//get_gps_lat
	data = get_gps_lat(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[8] =  byte {data_1};
	byteArr[9] =  byte {data_2};
	byteArr[10] =  byte {data_3};
	byteArr[11] =  byte {data_4};

	//get_gps_lng
	data = get_gps_lng(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[12] =  byte {data_1};
	byteArr[13] =  byte {data_2};
	byteArr[14] =  byte {data_3};
	byteArr[15] =  byte {data_4};

	//get_gps_hdop_value
	data = get_gps_hdop_value(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[16] =  byte {data_1};
	byteArr[17] =  byte {data_2};
	byteArr[18] =  byte {data_3};
	byteArr[19] =  byte {data_4};

	//get_gps_satellites_value
	data = get_gps_satellites_value(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[20] =  byte {data_1};
	byteArr[21] =  byte {data_2};
	byteArr[22] =  byte {data_3};
	byteArr[23] =  byte {data_4};

	//get_gps_altitude_meters
	data = get_gps_altitude_meters(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[24] =  byte {data_1};
	byteArr[25] =  byte {data_2};
	byteArr[26] =  byte {data_3};
	byteArr[27] =  byte {data_4};

	//get_gps_course_deg
	data = get_gps_course_deg(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[28] =  byte {data_1};
	byteArr[29] =  byte {data_2};
	byteArr[30] =  byte {data_3};
	byteArr[31] =  byte {data_4};

	//get_gps_speed_kmph
	data = get_gps_speed_kmph(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[32] =  byte {data_1};
	byteArr[33] =  byte {data_2};
	byteArr[34] =  byte {data_3};
	byteArr[35] =  byte {data_4};

	//get_bpm_temperature
	data = get_bpm_temperature(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[36] =  byte {data_1};
	byteArr[37] =  byte {data_2};
	byteArr[38] =  byte {data_3};
	byteArr[39] =  byte {data_4};

	//get_bpm_altitude
	data = get_bpm_altitude(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[40] =  byte {data_1};
	byteArr[41] =  byte {data_2};
	byteArr[42] =  byte {data_3};
	byteArr[43] =  byte {data_4};

	//get_bpm_pressure
	data = get_bpm_pressure(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[44] =  byte {data_1};
	byteArr[45] =  byte {data_2};
	byteArr[46] =  byte {data_3};
	byteArr[47] =  byte {data_4};

	//get_status_sd
	data = get_status_sd(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[48] =  byte {data_1};
	byteArr[49] =  byte {data_2};
	byteArr[50] =  byte {data_3};
	byteArr[51] =  byte {data_4};

	//get_bar_speed
	data = get_bar_speed(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[52] =  byte {data_1};
	byteArr[53] =  byte {data_2};
	byteArr[54] =  byte {data_3};
	byteArr[55] =  byte {data_4};

	//get_is_open
	data = get_is_open(pkg);
	data_1 = (data & 0xff000000UL) >> 24;
	data_2 = (data & 0x00ff0000UL) >> 16;
	data_3 = (data & 0x0000ff00UL) >> 8;
	data_4 = (data & 0x000000ffUL);

	byteArr[56] =  byte {data_1};
	byteArr[57] =  byte {data_2};
	byteArr[58] =  byte {data_3};
	byteArr[59] =  byte {data_4};

	return byteArr;
}

//byte vector to struct
package byte_vector_to_struct(vector<byte> byteArr){

	package pkg;

	//Mode
	//Combines the four bytes of data in one 32 bit value
	//If you don't convert each byte to uint8_t before, it goes wrong
	uint32_t data = (uint32_t)(((to_integer<uint8_t>(byteArr[0])) << 24) | 
		((to_integer<uint8_t>(byteArr[1])) << 16) 
		| ((to_integer<uint8_t>(byteArr[2])) << 8) 
		| ((to_integer<uint8_t>(byteArr[3]))));
	//Assign the value to the package
	set_mode(&pkg, data);

	//gps_isValid
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[4])) << 24) | 
		((to_integer<uint8_t>(byteArr[5])) << 16) 
		| ((to_integer<uint8_t>(byteArr[6])) << 8) 
		| ((to_integer<uint8_t>(byteArr[7]))));
	set_gps_isValid(&pkg, data);

	//gps_lat
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[8])) << 24) | 
		((to_integer<uint8_t>(byteArr[9])) << 16) 
		| ((to_integer<uint8_t>(byteArr[10])) << 8) 
		| ((to_integer<uint8_t>(byteArr[11]))));
	set_gps_lat(&pkg, data);

	//gps_lng
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[12])) << 24) | 
		((to_integer<uint8_t>(byteArr[13])) << 16) 
		| ((to_integer<uint8_t>(byteArr[14])) << 8) 
		| ((to_integer<uint8_t>(byteArr[15]))));
	set_gps_lng(&pkg, data);

	//gps_hdop_value
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[16])) << 24) | 
		((to_integer<uint8_t>(byteArr[17])) << 16) 
		| ((to_integer<uint8_t>(byteArr[18])) << 8) 
		| ((to_integer<uint8_t>(byteArr[19]))));;
	set_gps_hdop_value(&pkg, data);

	//gps_satellites_value
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[20])) << 24) | 
		((to_integer<uint8_t>(byteArr[21])) << 16) 
		| ((to_integer<uint8_t>(byteArr[22])) << 8) 
		| ((to_integer<uint8_t>(byteArr[23]))));
	set_gps_satellites_value(&pkg, data);

	//gps_altitude_meters
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[24])) << 24) | 
		((to_integer<uint8_t>(byteArr[25])) << 16) 
		| ((to_integer<uint8_t>(byteArr[26])) << 8) 
		| ((to_integer<uint8_t>(byteArr[27]))));
	set_gps_altitude_meters(&pkg, data);

	//gps_course_deg
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[28])) << 24) | 
		((to_integer<uint8_t>(byteArr[29])) << 16) 
		| ((to_integer<uint8_t>(byteArr[30])) << 8) 
		| ((to_integer<uint8_t>(byteArr[31]))));
	set_gps_course_deg(&pkg, data);

	//gps_speed_kmph
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[32])) << 24) | 
		((to_integer<uint8_t>(byteArr[33])) << 16) 
		| ((to_integer<uint8_t>(byteArr[34])) << 8) 
		| ((to_integer<uint8_t>(byteArr[35]))));
	set_gps_speed_kmph(&pkg, data);

	//bpm_temperature
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[36])) << 24) | 
		((to_integer<uint8_t>(byteArr[37])) << 16) 
		| ((to_integer<uint8_t>(byteArr[38])) << 8) 
		| ((to_integer<uint8_t>(byteArr[39]))));
	set_bpm_temperature(&pkg, data);

	//bpm_altitude
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[40])) << 24) | 
		((to_integer<uint8_t>(byteArr[41])) << 16) 
		| ((to_integer<uint8_t>(byteArr[42])) << 8) 
		| ((to_integer<uint8_t>(byteArr[43]))));
	set_bpm_altitude(&pkg, data);

	//bpm_pressure
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[44])) << 24) | 
		((to_integer<uint8_t>(byteArr[45])) << 16) 
		| ((to_integer<uint8_t>(byteArr[46])) << 8) 
		| ((to_integer<uint8_t>(byteArr[47]))));
	set_bpm_pressure(&pkg, data);

	//status_sd
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[48])) << 24) | 
		((to_integer<uint8_t>(byteArr[49])) << 16) 
		| ((to_integer<uint8_t>(byteArr[50])) << 8) 
		| ((to_integer<uint8_t>(byteArr[51]))));
	set_status_sd(&pkg, data);

	//bar_speed
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[52])) << 24) | 
		((to_integer<uint8_t>(byteArr[53])) << 16) 
		| ((to_integer<uint8_t>(byteArr[54])) << 8) 
		| ((to_integer<uint8_t>(byteArr[55]))));
	set_bar_speed(&pkg, data);

	//is_open
	data = (uint32_t)(((to_integer<uint8_t>(byteArr[56])) << 24) | 
		((to_integer<uint8_t>(byteArr[57])) << 16) 
		| ((to_integer<uint8_t>(byteArr[58])) << 8) 
		| ((to_integer<uint8_t>(byteArr[59]))));
	set_is_open(&pkg, data);

	return pkg;
}

//Byte vector to uint8_t array
uint8_t* byte_vector_to_array(vector<byte> byteArr){

	// Buffer
	uint8_t* buffer;
	buffer = (uint8_t*) malloc(PACKAGE_SIZE);

	// Counter
	uint8_t i = 0;

	//Assets the byteArr values to uint8_t array
	for(i = 0; i < PACKAGE_SIZE; i++){
		buffer[i] = to_integer<uint8_t>(byteArr[i]);
	}

	return buffer;
}

//uint8_t array to byte vector
vector<byte> byte_array_to_vector(uint8_t* buffer){

	//Creates a byte vector
	vector<byte> byteArr(PACKAGE_SIZE);

	// Fill with the buffer content
	uint8_t i = 0;
	for(i = 0; i < PACKAGE_SIZE; i++){
		byteArr[i] = byte{buffer[i]};
	}

	return byteArr;
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

	//****Tests****
	//Single byte var
	byte myByte {0b0011};
	print_byte(myByte);

	//Creating a Vector of bytes
	vector<byte> byteArr1(NUM_OF_DATA, byte {8});
	//How to set a position
	byteArr1[2] = byte{30};
	
	//Testing struct_to_byte_vector and byte_vector_to_struct
	vector<byte> byteArr2 = struct_to_byte_vector(pkg);
	package pkg2;
	pkg2 = byte_vector_to_struct(byteArr2);
	print_pkg(pkg2);

	//Testing byte_vector_to_array and byte_array_to_vector
	uint8_t* buffer;
	buffer = byte_vector_to_array(byteArr2);
	print_byte_array(buffer);
	cout << "\n";
	vector<byte> byteArr3 = byte_array_to_vector(buffer);
	print_byte_vector(byteArr3);
	cout << "\n";

	return 0;
}
