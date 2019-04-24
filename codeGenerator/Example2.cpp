#include "codeGenerator.h"

int main(){

	CodeGenerator code_gen;
	int control = 1;

	while(control==1){
			
			code_gen.ui_initial_menu();

			switch (code_gen.user_choice) {
					case 1:{
							code_gen.ui_create_functions_database();

							break;
					}
					case 2:{
							code_gen.ui_create_modules_database();

							break;
					}
					case 3:{
							
							code_gen.generate();

							break;
					}
					case 4:{
							control = 0;
					}
			}
	}
	return 0;
}
