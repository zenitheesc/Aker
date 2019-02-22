#include "CodeGenerator.h"

int main(){

	string user_input;
	CodeGenerator code_gen;

	//Rads the user input
	cout << "Enter a string informing which componentes\n";
	cout << "you want to add to your system: \n\n";
	cout << "Options: \n1-GPS\n2-BMP\n3-Communication\n\nInput:";
	getline(cin, user_input);

	//Starts the code
	code_gen.start();
	//Write the linear code
	code_gen.state_machine_code(user_input);
	//Finishes the code
	code_gen.finish();

	return 0;
}
