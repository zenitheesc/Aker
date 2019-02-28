#include "codeGenerator.h"

int main(){

	CodeGenerator code_gen;
	int user_choice;
	int number_of_functions;
	int number_of_modules;
	int *functions_ids;
	int *modules_ids;
	int control = 1;
	int number_of_states;
	//stores the ammount of states and it's functions
	//state 1: function 1, function 2..
	//state 2: function 1, ...
	int **states_functions;

	while(control==1){
			system("clear");
			cout << "=================================================" << endl;
			cout << "=              Aker - Code Generator            =" << endl;
			cout << "=================================================" << endl;
			cout << "  Choose one option:                             " << endl;
			cout << "    1. Register one function;                    " << endl;
			cout << "    2. Register one module;                      " << endl;
			cout << "    3. Generate code;                            " << endl;
			cout << "    4. Exit;                                     " << endl;
			cout << "  Your choice: ";
			cin  >>  user_choice;

			switch (user_choice) {
					case 1:{
							system("clear");
							cout << "=================================================" << endl;
							cout << "=              Aker - Code Generator            =" << endl;
							cout << "=================================================" << endl;
							code_gen.create_functions_database();
							break;
					}
					case 2:{
							system("clear");
							cout << "=================================================" << endl;
							cout << "=              Aker - Code Generator            =" << endl;
							cout << "=================================================" << endl;
							code_gen.create_modules_database();
							break;
					}
					case 3:{
							system("clear");
							cout << "=================================================" << endl;
							cout << "=              Aker - Code Generator            =" << endl;
							cout << "=================================================" << endl;
							cout << "  How many modules do you want?                  " << endl;

							cin  >> number_of_modules;
							modules_ids = (int*)malloc((number_of_modules+1)*sizeof(int));
							*(modules_ids + number_of_modules) = -1;
							cout << "  Entry modules IDs:                           " << endl;
							for(int i = 0; i<number_of_modules ; i++){
									cin  >> *(modules_ids + i);
							}

							system("clear");
							cout << "=================================================" << endl;
							cout << "=              Aker - Code Generator            =" << endl;
							cout << "=================================================" << endl;
							cout << "  How many states do you want?                  " << endl;

							cin  >> number_of_states;
							//allocates memory for the states_function** rows
							states_functions = (int**)malloc(number_of_states*sizeof(int*));

							//For each state, read its functions
							for(int i = 0; i<number_of_states ; i++){
								system("clear");
								cout << "=================================================" << endl;
								cout << "=              Aker - Code Generator            =" << endl;
								cout << "=================================================" << endl;
								cout << "  How many functions do you want in state " << i << "?" << endl;

								cin  >> number_of_functions;
								//allocates memory for the states_functions** cols
								states_functions[i] = (int*)
													malloc((number_of_functions+1)*sizeof(int));
								*(states_functions[i] + number_of_functions) = -1;
								cout << "  Entry functions IDs:                           " << endl;
								for(int j = 0; j<number_of_functions ; j++){
										cin  >> states_functions[i][j];
								}
							}

							//Starts the code
							code_gen.start(modules_ids);
							//Write the  code
							code_gen.state_machine_code(states_functions, number_of_states);
							//Finishes the code
							code_gen.finish();

							break;
					}
					case 4:{
							control = 0;
					}
			}
	}
	return 0;
}
