/*******************************************************************
 *
 * AUTHOR: Angie Roman
 * DATE CREATED: 22 February 2022
 * FILE: main.cpp
 * DESC: all functions of file modification
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "record.h"
#include "list.h"
#include "addressBook.h"

list::list() {

    int records_read = 0;
    start = NULL;
    file_name = "contacts.txt";

    records_read = read_file();

    // print messages for files
    if (records_read < 0) {
        std::cout << "'" << file_name << " was not found.\n";
        std::cout << "New file will be created : '" << file_name << std::endl; 
    }
    else if (records_read == 0) { 
        std::cout << "'" << file_name << "' has been found and is empty.\n";
    }
    else { 
        std::cout << "'" << file_name << "' has been read. " << records_read << " records have been added to the database.\n";
    } 
    std::cout << "------------------------------------------------\n";
} 

list::list(std::string file) {

    int records_read = 0;
    start = NULL;
    file_name = file;

    records_read = read_file();
    // print messages for files
    if (records_read < 0) {
        std::cout << "'" << file_name << " was not found.\n";
        std::cout << "Therefore, no records have been added to the list and '" << file_name << "' will be created.\n";
    }
    else if (records_read == 0) {
        std::cout << "'" << file_name << "' has been found but is empty.\n";
        std::cout << "Therefore, no records have been added to the database.\n";
    }
    else { 
        std::cout << "'" << file_name << "' has been read. " << records_read << " records have been added to the database.\n";
    } 
    std::cout << "------------------------------------------------\n";
} 

list::~list() {
    write_file();
    delete_all_records();
} 

int list::read_file() {

    std::ifstream read_file(file_name.c_str());
    struct record* temp = NULL;
    struct record* index = NULL;
    struct record* previous = NULL;
    int file_char_length = 0;
    int record_count = 0;
    std::string dummy = "";

    if (!read_file.is_open()) 
    {
        read_file.close();
        return -1;
    } 

    read_file.seekg(0, read_file.end); // move read pointer to end of file
    file_char_length = read_file.tellg(); // return file pointer position
    if (file_char_length == 0) 
    {
        read_file.close();
        return 0;
    } 
    read_file.seekg(0, read_file.beg); // reset file pointer to beginning
    do { // do while !read_file.eof()
        // do while temporary variables
        std::string address = "";

        temp = new record;
        index = start;
        std::getline(read_file, temp->name);
        std::getline(read_file, temp->address);
        std::getline(read_file, temp->phoneNumber);
        std::getline(read_file, dummy);
        ++record_count;

        while (index != NULL) 
        {
            previous = index;
            index = index->next;
        } 
        if (previous == NULL)
        {
            temp->next = start;
            start = temp;
        }
        else { // else if previous != NULL
            previous->next = temp;
            temp->next = index;
        } 
    } while (!read_file.eof()); 

    read_file.close();
    return record_count; 
}

int list::write_file() {

    std::ofstream write_file(file_name.c_str());
    record* index = start;
    int record_count = 0;

    if (start == NULL) {
        std::cout << "The database is empty. Therefore, no records have been added to file: " << file_name << '\n';
        write_file.close();
        return -1;
    } 
    do { // do while index != NULL
        write_file << index->name << "\n";
        write_file << index->address << "\n";
        write_file << index->phoneNumber << "\n";

        index = index->next;
        ++record_count;
    } while (index != NULL); 
    std::cout << record_count << " Contacts have been added to file: " << file_name << "\n";
    write_file.close();
    return 0; 
}

void list::delete_all_records() {
  
    struct record* temp = start;
    struct record* index = NULL;
    int records_deleted = 0;

    std::cout << "------------------------------------------------\n";
    if (start != NULL) {
        while (index != NULL) {
            temp = index;
            index = index->next;
            start = index;
            delete temp;
            ++records_deleted;
        } 
        std::cout << records_deleted << " records removed from the memory.\n";
    }
    else { // else if start == NULL
        std::cout << "The Database is empty. Therefore, no records have been removed.\n";
    }
    std::cout << "------------------------------------------------\n";
    return; 
}

int list::add_record(std::string input_name, std::string input_address, std::string input_phone_number) {
    struct record* temp = NULL;
    struct record* index = start;
    struct record* previous = NULL;

    temp = new record;
    temp->name = input_name;
    temp->address = input_address;
    temp->phoneNumber = input_phone_number;
    while (index != NULL) {
        previous = index;
        index = index->next;
    } 
    if (previous == NULL) {
        temp->next = start;
        start = temp;
    }
    else { // else if previous != NULL
        previous->next = temp;
        temp->next = index;
    } 
    std::cout << "------------------------------------------------\n";
    std::cout << "Record has been added.\n";
    std::cout << "------------------------------------------------\n";
    return 1; 
}

int list::print_record(std::string input_name) {
    struct record* index = start;
    int records_printed = 0;

    std::cout << "------------------------------------------------\n";
    if (start == NULL) {
        std::cout << "The Database is empty. Therefore, no records of " << input_name << " exist.\n";
        std::cout << "------------------------------------------------\n";
        return -1;
    } 
    while (index != NULL) {
        if (input_name == index->name) {
            ++records_printed;
            std::cout << "================================================\n";
            std::cout << "Record #" << records_printed << " of:\n";
            std::cout << "Name: " << index->name << "\n";
            std::cout << "Address: " << index->address << '\n';
            std::cout << "Telephone Number: " << index->phoneNumber << '\n';
        } 
        index = index->next;
    } 

    if (records_printed == 0) {
        std::cout << "No records of " << input_name << " found.\n";
    }
    else { // else if records_printed > 0
        std::cout << records_printed << " records of " << input_name << " printed." << '\n';
    } 
    std::cout << "------------------------------------------------\n";
    return 1; 
}

int list::modify_record(std::string input_name, std::string input_address, std::string input_phone_number) {
    
    struct record* index = start;
    int records_modified = 0;

    std::cout << "------------------------------------------------\n";
    if (start == NULL) {
        std::cout << "The Database is empty. Therefore, no records of " << input_name << " exist.\n";
        std::cout << "------------------------------------------------\n";
        return -1; // modify_record return
    } 

    while (index != NULL) {
        if (input_name == index->name) 
        {
            index->address = input_address;
            index->phoneNumber = input_phone_number;
            ++records_modified;
        } 
        index = index->next;
    } 
    if (records_modified == 0) {
        std::cout << "No records of " << input_name << " found.\n";
    }
    else { // else if records_modified != 0
        std::cout << records_modified << " records of " << input_name << " records_modified.\n";
    } 
    std::cout << "------------------------------------------------\n";
    return 1; 
}

void list::print_all_records() {

    struct record* index = start;
    int record_count = 0;

    std::cout << "------------------------------------------------\n";
    if (start == NULL) {
        std::cout << "The Database is empty. Therefore, no records have been _printed.\n";
        std::cout << "------------------------------------------------\n";
        return; // print_all_records return
    } 
    while (index != NULL) {
        ++record_count;
        std::cout << "================================================\n";
        std::cout << "Record #" << record_count << '\n';
        std::cout << "Name: " << index->name << '\n';
        std::cout << "Address: " << index->address << '\n';
        std::cout << "Telephone Number: " << index->phoneNumber << '\n';
        index = index->next;
    }
    std::cout << record_count << " Records printed.\n";
    std::cout << "------------------------------------------------\n";
    return; 
}

int list::delete_record(std::string input_name) {

    struct record* temp = NULL;
    struct record* index = start;
    struct record* previous = NULL;
    int records_deleted = 0;

    std::cout << "------------------------------------------------\n";
    if (start == NULL) {
        std::cout << "The Database is empty. No records to delete. " << input_name << " exist.\n";
        std::cout << "------------------------------------------------\n";
        return -1; 
    } 
    while (index != NULL) {
        if (input_name == index->name) {
            temp = index;
            if (index == start) { 
                index = index->next;
                start = index;
            }
            else { 
                index = index->next;
                previous->next = index;
            } 
            delete temp;
            ++records_deleted;
        }
        else { 
            previous = index;
            index = index->next;
        } 
    } 
    if (records_deleted == 0) {
        std::cout << "No records of " << input_name << " found.\n";
    }
    else { 
        std::cout << records_deleted << " records of " << input_name << " records_deleted.\n";
    }
    std::cout << "------------------------------------------------\n";
    return 1; 
}