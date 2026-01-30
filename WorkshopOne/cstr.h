/* Citation and Sources...
-----------------------------------------------------------
Workshop 1
Module: 
Filename: cstr.cpp
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
All of this code was supplied by the workshop. I haven't changed anything. ^_^ 
-----------------------------------------------------------
*/

#include <cstddef>
#ifndef SENECA_CSTR_H
#define SENECA_CSTR_H

namespace seneca {
  char* strcat(char* des, const char* src);

  char tolower(char ch);

  char* tolower(char* des, const char* src);

  char* tolower(char* str);

  int strcmp(const char* s1, const char* s2);

  int strcmp(const char* s1, const char* s2, size_t len);
  
  char* strcpy(char* des, const char* src);

  char* strcpy(char* des, const char* src, size_t len);

  char* strncpy(char* des, const char* src, size_t len);

  size_t strlen(const char* str);

  const char* strstr(const char* str, const char* toFind);

  bool isalpha(char ch);

  bool isspace(char ch);
}

#endif // !SENECA_CSTR_H