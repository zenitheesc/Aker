#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

#define code_file_name "code.cpp"

//This struct aims to help data handling in codeGenerator
typedef struct DATA_BASE_FOR_CODE_GENERATOR {
		int id;
		char name[100];
		int number_of_parameters;
		char param_types[10][100];
		char param_names[10][100];
} code_generator_struct;

class CodeGenerator {
public:

	int user_choice;
	int *modules_ids;
	int number_of_states;
	int **states_functions;


	//Generate the state machine code given the user input
	int state_machine_code();

	//Append functions records into CodeGenerator Functions DataBase
	void create_functions_database();

	//Check users function input;
	int check_function_name(char* name);

	//Append modules records into CodeGenerator Modules DataBase
	void create_modules_database();

	//Check users modules input;
	int check_module_name(char* name);

	//Generate linear code based into a vector of functions IDs
	int linear_function(int *id_functions);

	//Starts the code
	int start();

	//Finishes the code
	void finish();

	//Inclues the functions for the system initial setup
	void initial_setup();

	//Inteface functions
	int ui_initial_menu();

	void ui_create_functions_database();

	void ui_create_modules_database();

	void ui_insert_modules();

	void ui_insert_functions();


private:
	//Current max value of the state machine
	//Shared with all the instances of the CodeGenrator
	static int curr_state_number;

	string functions_data_base_path = "functions_data_base.dat";
	string modules_data_base_path = "modules_data_base.dat";
	code_generator_struct data_for_functions;
	code_generator_struct data_for_modules;

};
