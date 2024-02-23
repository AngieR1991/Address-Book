/*******************************************************************
 *
 * AUTHOR: Angie Roman
 * DATE CREATED: 22 February 2022
 * FILE: main.cpp
 * DESC: main function that runs the entire project
 ******************************************************************/

#include <iostream>
#include <string>
#include "addressBook.h"

int main(int argc, char* argv[]) {

    if (argc > 1) {
        std::cout << "Application does not take arguments." << std::endl;
        return -1;
    } 

    std::cout << "************************************************\n";
    std::cout << "*                 Welcome User                 *\n";
    std::cout << "*         This is Angie's Address Book         *\n";
    std::cout << "************************************************\n";;
    run_program();
    std::cout << "************************************************\n";
    std::cout << "*                App terminated                *\n";
    std::cout << "************************************************\n";
    return 0;
}