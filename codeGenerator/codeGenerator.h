#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
using namespace std;

#define code_file_name "code.cpp"

//This struct aims to help data handling in codeGenerator
//With this structure the developers are able to index
//the database's file much more easily
typedef struct DATA_BASE_FOR_CODE_GENERATOR {
        int id;
        string name;
        int number_of_parameters;
        vector<string> param_types;
        vector<string> param_names;
        string module_of_function;
        string module_classifier;
        string return_type;
} code_generator_struct;

//Class: Code Generator
//This class aims to have all the parameteres, attributes
//and functions used to operate the database, to generate
//the final code and to handle the user interface.
class CodeGenerator {
public:

    //UI Related: stores the command inserted by the user in the menu
    int user_choice;

    //This function prints the main menu on the console and gets the
    //the user input that defines to where the interface should go
    int console_initial_menu();

    //Prints the interface for the addition of functions in database
    //and handles this functionality, registering a new function
    //as defined by the user
    void console_new_function();

    //Prints the interface for the addition of modules in database
    //and handles this functionality, registering a new module
    //as defined by the user
    void console_new_module();

    //Generate the final code
    //It encapsulates some other functions of the class and writes
    //the final version of the generated C++ program
    void console_generate();

    void ui_initial_menu(int);

    void ui_new_function(int, string, string, string, int, vector<string>, vector<string>);

    void ui_new_module(int, string, string);

    void ui_generate(int, vector<int>, vector<int>, int, vector<vector<int>>);

    //Setters
    void set_user_choice(int);

    void set_modules_ids(vector<int>);

    void set_number_of_states(int);

    void set_states_functions(vector<vector<int>>);

    void set_function_id(int);

    void set_function_name(string);

    void set_return_type(string);

    void set_number_of_parameters(int);

    void set_param_types_list(vector<string>);

    void set_param_names_list(vector<string>);

    void set_module_id(int);

    void set_module_name(string);

    void set_number_of_modules(int);

    void set_module_classifier(string);

    void set_module_of_function(string);

    //Gettes
    int get_user_choice();

    vector<int> get_modules_ids();

    int get_number_of_states();

    vector<vector<int>> get_states_functions();

    int get_function_id();

    string get_function_name();

    string get_return_type();

    int get_number_of_parameters();

    vector<string> get_param_types_list();

    vector<string> get_param_names_list();

    int get_module_id();

    string get_module_name();

    int get_number_of_modules();

    string get_module_classifier();

    string get_module_of_function();

    //Returns a 2D char array with all the modules names in the database
    vector<string> get_all_modules_names_by_classifier(string);

    //Returnas a 2D char array with all the function names of a module
    vector<string> get_all_functions_of_a_module(string);

    //Returns the function ID using its name
    int get_function_id_by_name(string);

    //Returns the module ID using its name
    int get_module_id_by_name(string);

private:

    //Number of Modules
    int number_of_modules;
    //An array of all the modules IDs that will be used to access each
    //module information in the database
    vector<int> modules_ids;
    //The number of functions of the current state
    int number_of_functions;
    //The number of states of the states machine of the program
    int number_of_states;
    //An 2D array storing the functions IDs of each state in the format
    //ROW: States  X  COL: IDs
    vector<vector<int>> states_functions;
    //Function id
    int function_id;
    //Function name
    string function_name;
    //Function return type
    string return_type;
    //Number of parameteres of the function being added to the database
    int number_of_parameters;
    //List of parameteres type
    vector<string> param_types_list;
    //List of parameters name
    vector<string> param_names_list;
    //Module id
    int module_id;
    //Module name
    string module_name;
    //Classifies the module
    string module_classifier;
    //Module that function belongs to
    string module_of_function;
    //Current max value of the state machine
    //Shared with all the instances of the CodeGenrator
    static int curr_state_number;

    //Starts the code
    //This function handles the writing of the first features that
    //a C++ code should have
    int console_start();

    //Generate the state machine code
    //This functions iterates over the number of states choosen by the
    //user and, for each state, generates a linear code containing
    //each function associated to that respective state
    int console_state_machine_code();

    //Finishes the code
    //This function handles the writing of the last features that
    //a C++ code should have, finishing the file of the code
    void finish();

    //Generate linear code based into a vector of functions IDs
    //This function is intended to be used inside the state_machine_code.
    //For each state is called this function passing an array with the
    //IDs of the functions belonging to the respective state. Then is
    //generate a code that calls each function sucessively, adding extras
    //features like one variable for each parameter, etc.
    int console_linear_function(vector<int>);

    //Inclues the functions for the system initial setup
    //The initial setup is a state with id 0. This state is note
    //declared by the user and appears automatically when the code
    //is generated. Is used to make the initial setup needed for
    //the code to run
    void initial_setup();

    //Used when the program is generating the code. Handles the user interface
    //for choosing how much modules and which one will be added to the code
    //and then adds it to the generated code
    void console_insert_modules();

    //Used when the program is generating the code. Handles the creation
    //of the program states as defined by the user. Also, allows the user
    //to choose which functions will belong to each state, generating the
    //respective code by the end
    void console_insert_functions();

    //Append functions records into CodeGenerator Functions DataBase
    //This functions aims to register a new function with its attributes
    //such like parameters types and names into the functions database
    //in a way that It can be accessed with the code_generator_struct struct
    void console_create_functions_database();

    //TODO
    //Verify if the user input for the function name fits a series
    //of rules defined both by the developes and by C++ syntax
    int check_function_name(string);

    //Append modules records into CodeGenerator Modules DataBase
    //This functions aims to register a new module into the modules database
    //in a way that It can be accessed with the code_generator_struct struct
    void console_create_modules_database();

    //TODO
    //Verify if the user input for the module name fits a series
    //of rules defined both by the developes and by C++ syntax
    int check_module_name(string);

    void ui_create_functions_database();

    void ui_create_modules_database();


    void ui_insert_modules(int, vector<int>);

    void ui_insert_functions(vector<vector<int>>);

    int ui_start();

    int ui_state_machine_code();

    int ui_linear_function(vector<int>);

    string functions_data_base_path = "functions_data_base.dat";
    string modules_data_base_path = "modules_data_base.dat";
    code_generator_struct data_for_functions;
    code_generator_struct data_for_modules;

};
