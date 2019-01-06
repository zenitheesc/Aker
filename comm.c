#include "comm.h"

int32_t get_mode(package pkg){
	return pkg.mode;
}

int main(){

	package pkg;

	pkg.mode = 2;

	printf("%d\n", get_mode(pkg));

	return 0;
}
