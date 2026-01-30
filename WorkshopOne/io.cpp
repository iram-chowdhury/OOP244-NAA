/* Citation and Sources...
-----------------------------------------------------------
Workshop 1
Module: 
Filename: io.cpp
-----------------------------------------------------------
Author: Aryan Chowdhury
Student number: 138197181
Email: ichowdhury6@myseneca.ca
Subject: OOP244-NAA
-----------------------------------------------------------
Revision History
------- --------- ------------------------------------------
Version Date      Reason
V1.0   2026/02/22
-----------------------------------------------------------
I have done most of the the coding by myself aside from the copied code that my professor provided to complete my work. I also used AI assistants (Claude & ChatGPT) to help guide me on most of the functions past the first one. On how to solve the void print(); function in io.cpp, specifically with learning how to convert the phone number mathematically. To help me with understanding the overloaded print function & how to format it correctly, used it as a guide to teach me how to use the & symbol to reference & about the strstr object that I used. It also taught me about the size_t unsigned integer as I had no knowledge of this prior. Continued for the rest of the functions.   
-----------------------------------------------------------
*/

#include <iostream>
#include <cstring>
#include "io.h"

using namespace std; 

namespace seneca {
  void read(char name[]) {
    cout << "Name\n> ";
    cin >> name; 
  }

  void print(long long phoneNumber) {
     int area = phoneNumber / 10000000;
    int mid = (phoneNumber / 10000) % 1000;
    int last = phoneNumber % 10000;

    cout << "(";

    if (area < 100) {
      cout << "0";
    }
    if (area < 10) {
      cout << "0";
    }
    cout << area << ") ";

    if (mid < 100) {
      cout << "0";
    }
    if (mid < 10) {
      cout << "0";
    }
    
    cout << mid << "-";

    if (last < 1000) {
      cout << "0";
    }
    if (last < 100) {
      cout << "0";
    }
    if (last < 10) {
      cout << "0";
    }

    cout << last << endl;
  }

  void print(const PhoneRec &phoneRecord,  size_t &row, const char* filter) {
    if (filter == nullptr || 
        strstr(phoneRecord.firstName, filter) != nullptr ||
        strstr(phoneRecord.lastName, filter) != nullptr) {
          cout << row << ": " << phoneRecord.firstName << " " << phoneRecord.lastName << " ";
          print(phoneRecord.phoneNumber);
          ++row; 
        }
  }

  bool read(PhoneRec &reference, FILE* openedFile) {
    if (fscanf(openedFile, "%s %s %lld", reference.firstName, reference.lastName, &reference.phoneNumber) != 3) {
      return false; 
    }

    return true;
  }

  void print(PhoneRec* records[], int sizeOfArray, const char* filter) {
    size_t row = 1; 

    for(int i = 0; i < sizeOfArray; i++) {
      if (records[i] != nullptr) {
        print(*records[i], row, filter);
      }
    }
  }
  

  void setPointers(PhoneRec* pointers[],  PhoneRec records[], int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; i++) {
      pointers[i] = &records[i];
    }
  }

  void sort(PhoneRec* pointers[], size_t sizeOfArray, bool flag) {
  for (size_t i = 0; i < sizeOfArray - 1; i++) {
    for (size_t j = i + 1; j < sizeOfArray; j++) {
      if (flag) { // sort by lastName
        if (strcmp(pointers[i]->lastName, pointers[j]->lastName) > 0) {
          PhoneRec* temp = pointers[i];
          pointers[i] = pointers[j];
          pointers[j] = temp;
        }
      } else { // sort by firstName
        if (strcmp(pointers[i]->firstName, pointers[j]->firstName) > 0) {
          PhoneRec* temp = pointers[i];
          pointers[i] = pointers[j];
          pointers[j] = temp;
        }
      }
    }
  }
}


}