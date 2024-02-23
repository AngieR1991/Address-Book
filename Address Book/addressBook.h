/*******************************************************************
 *
 * AUTHOR: Angie Roman
 * DATE CREATED: 22 February 2022
 * FILE: main.cpp
 * DESC: Most functionality is in this file
 ******************************************************************/

#include <string>

 /**********
  * FUNC: run_program
  * DESC: Runs the entire program
  **********/
void run_program();

/**********
 * FUNC: display_commands
 * DESC: Displays menu
 **********/
void display_commands();

/**********
 * FUNC: get_menu_selection
 * DESC: Gets input for menu selection
 **********/
int get_menu_selection();

/**********
 * FUNC: get_name
 * DESC: Gets input for name
 * RETURN: the name of the person to add 
 **********/
std::string get_name();

/**********
 * FUNC: get_address
 * DESC: Gets input for address
 * RETURN: the address for the person
 **********/
std::string get_address();

/**********
 * FUNC: get_phone_number
 * DESC: Gets input for phone_number
 * RETURN: phone number for the person
 **********/
std::string get_phone_number();

/**********
 * FUNC: get_file_name
 * DESC: Gets input for file name
 * RETURN: name of the file to save the list into
 **********/
std::string get_file_name();