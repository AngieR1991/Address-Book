/*******************************************************************
 *
 * AUTHOR: Angie Roman
 * DATE CREATED: 22 February 2022
 * FILE: main.cpp
 * DESC: address book functions
 ******************************************************************/

#include <iostream>
#include <string>
#include "record.h"
#include "list.h"
#include "addressBook.h"

void run_program() {
    list records(get_file_name()); /* Lets user create their own .txt file */
    std::string input_name = "";
    std::string input_address = "";
    std::string input_phone = "";
    std::string dummy = "";
    int input_year = 0;
    int menu_selection = 0;

    display_commands();
    do { // do while menu_selection != 6
        menu_selection = get_menu_selection();
        switch (menu_selection) {
        case 1: // case 1 - add record 
            std::cout << "------------------------------------------------\n";
            std::cout << "Add a new Record\n";
            input_name = get_name();
            input_address = get_address();
            input_phone = get_phone_number();
            records.add_record(input_name, input_address, input_phone);
            break; 

        case 2: // case 2 - print specific record by name
            std::cout << "------------------------------------------------\n";
            std::cout << "Print Record(s) with the same name\n";
            input_name = get_name();
            records.print_record(input_name);
            break; 

        case 3: // case 3 - modify specific record by name 
            std::cout << "------------------------------------------------\n";
            std::cout << "Modify Record(s) with the same name\n";
            input_name = get_name();
            input_address = get_address();
            input_phone = get_phone_number();
            records.modify_record(input_name, input_address, input_phone);
            break; 

        case 4: // case 4 - print all records
            std::cout << "------------------------------------------------\n";
            std::cout << "Printing Records...\n";
            records.print_all_records();
            break; 

        case 5: // case 5 - delete specific record by name
            std::cout << "------------------------------------------------\n";
            std::cout << "Delete Record(s) with the same name\n";
            input_name = get_name();
            records.delete_record(input_name);
            break; 
        } 

        if (menu_selection != 6) {
            display_commands();
        }
    } while (menu_selection != 6); 

    return; 
}

void display_commands() {
    std::cout << "What would you like to do?\n";
    std::cout << "\t1: Add a new contact\n";
    std::cout << "\t2: Display a contact using the name as the key. \n";
    std::cout << "\t3: Modify a contact  using the name as the key. \n";
    std::cout << "\t4: Print all information in the database.\n";
    std::cout << "\t5: Delete an existing contact from the database.\n";
    std::cout << "\t6: Quit the program.\n";
    return; 
}

int get_menu_selection() {

    int selection = 0;

    std::cin >> selection;
    while (std::cin.fail() || selection < 1 || selection > 7) { // while input is not valid
        if (std::cin.fail()) {
            std::cout << "Your input was not an integer. Please enter an integer: ";
        }
        else if (selection < 1 || selection > 6) {
            std::cout << "Not a valid choice.\n";
            display_commands();
        } 
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin >> selection;
    } 
    std::cin.clear(); // clear buffer
    return selection; 
}

std::string get_name() {
    // get_name variables
    std::string name = "";
    std::cin.clear();
    std::cin.ignore(256, '\n');
    std::cout << "Please enter the person's name: ";
    std::getline(std::cin, name);
    return name; 
}

std::string get_address() {
    std::string address = "";
    std::cout << "Please enter the person's address:\n";
    std::getline(std::cin, address);
    return address; 
}

std::string get_phone_number() {
    std::string phone_number = "";
    std::cout << "Please enter the contact's telephone number: ";
    std::getline(std::cin, phone_number);
    return phone_number; 
}

std::string get_file_name() {

    std::string file_name = "";
    int count = 0;
    std::cout << "Please enter your FILE NAME ('.txt' file extension will be added):" << std::endl;
    std::cout << "Type 'contacts' if you want to work with an existing address book" << std::endl;
    std::getline(std::cin, file_name);
    file_name += ".txt";
    return file_name; 
}