/*******************************************************************
 *
 * AUTHOR: Angie Roman
 * DATE CREATED: 22 February 2022
 * FILE: main.cpp
 * DESC: record header file, contains variable for file
 ******************************************************************/

#include <string>
#ifndef RECORD_H
#define RECORD_H
struct record {
    std::string name;
    std::string address;
    std::string phoneNumber;
    struct record* next;
};
#endif