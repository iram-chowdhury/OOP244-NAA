/* Citation and Sources...
-----------------------------------------------------------
Workshop 4
Module: Account
Filename: Account.cpp
-----------------------------------------------------------
Author: Aryan Chowdhury
Student number: 138197181
Email: ichowdhury6@myseneca.ca
Subject: OOP244-NAA
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date      Reason
V1.0 2026/01/29
-----------------------------------------------------------
Done all the work by myself with help from AI modules such as Claude & ChatGPT, guiding me along the way whenever I got stuck. Helped me understand core concepts so I could finish this workshop. 
-----------------------------------------------------------  
*/

#include <iostream>
#include "Account.h"

using namespace std;
namespace seneca {
 

   void Account::cpyName(const char* src) {
      int i;
      for (i = 0; src && src[i] && i < NameMaxLen; i++) {
         m_holderName[i] = src[i];
      }
      m_holderName[i] = char(0);
   }
   bool Account::isValidNumber(int number) const {
      return number >= 10000 && number <= 99999;
   }
   Account::Account(const char* holderName) {  
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0]) {
         cpyName(holderName);
         m_number = 0;
      }
   }
   Account::Account(const char* holderName, int number, double balance ) {
      m_holderName[0] = char(0);
      m_number = -1;
      m_balance = 0.0;
      if (holderName && holderName[0] && isValidNumber(number)
         && balance > 0) {
         cpyName(holderName);
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout.fill(' ');
         cout.width(NameMaxLen);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " | ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << " ";
         cout.fill(' ');
         cout.width(30);
         cout.setf(ios::left);
         cout << m_holderName;
         cout.unsetf(ios::left);
         cout << " |  NEW  |         0.00 ";
      }
      else {
         cout << " Bad Account                    | ----- | ------------ ";
      }
      return cout;
   }

   Account::operator bool() const {
      if (m_holderName[0] != '\0' && isValidNumber(m_number) && m_balance >= 0.0) {
      return true;
      } else {
      return false;
      }
   }

   Account::operator int() const {
      return m_number;
   }

   Account::operator double() const {
      return m_balance;
   }

   Account::operator const char*() const {
      return m_holderName;
   }

   char& Account::operator[] (int index) {
      index %= NameMaxLen;
      return m_holderName[index];
   }

   char Account::operator[] (int index) const {
      index %= NameMaxLen;
      return m_holderName[index];
   }

   bool Account::operator~() const {
      return m_number == 0;
   }

   Account& Account::operator=(int number) {
      if (m_number == 0) {
         if (isValidNumber(number)) {
            m_number = number;
         } else {
            m_holderName[0] = '\0';
            m_number = -1;
            m_balance = 0.0;
         }
      }
      return *this;
   }

   Account& Account::operator=(double balance) {
      if (balance >= 0.0) {
         m_balance = balance;
      } else {
         m_holderName[0] = '\0';
         m_number = -1;
         m_balance = 0.0;
      }
      return *this;
   }
   
   Account& Account::operator+=(double value) {
      if (*this && value > 0.0) {
         m_balance += value;
      }
      return *this;
   }

   Account& Account::operator-=(double value) {
      if (*this && value > 0.0 && value <= m_balance) {
         m_balance -= value;
      }
      return *this;
   }

   Account& Account::operator<<(Account& otherAccount) {
      if (this != &otherAccount  && *this && otherAccount) {
         m_balance += otherAccount.m_balance;
         otherAccount.m_balance = 0.0;
      }
      return *this;
   }

   Account& Account::operator>>(Account& otherAccount) {
      if (this != &otherAccount && *this && otherAccount) {
         otherAccount.m_balance += m_balance;
         m_balance = 0.0;
      }
      return *this;
   }

   Account& Account::operator++() {
      if (*this) {
         m_balance += 1.0;
      }
      return *this;
   }

   Account Account::operator++(int) {
      Account backUp = *this;
      if (*this) {
         m_balance += 1.0;
      }
      return backUp;
   }

   Account& Account::operator--() {
      if (*this) {
         m_balance -= 1.0;
      }
      return *this;
   }

   Account Account::operator--(int) {
      Account backUp = *this;
      if (*this) {
         m_balance -= 1.0;
      }
      return backUp;
   }


   
} // End of namespace seneca