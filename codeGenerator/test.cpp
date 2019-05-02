#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef struct test_struct{
	string name;
	string last_name;
	int age;
} test_struct;

int main(){

	test_struct ts;
	ifstream data_base;

	data_base.open("test_file.txt");

	data_base.seekg(0, ios_base::beg);
	data_base.read(ts, sizeof(test_struct));

	data_base.close();

	return 0;
}