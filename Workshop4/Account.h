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

#ifndef SENECA_ACCOUNT_H_
#define SENECA_ACCOUNT_H_
#include <iostream>

namespace seneca {
   const int NameMaxLen = 30;
   class Account {
      double m_balance;
      int m_number;
      char m_holderName[NameMaxLen + 1];
      void cpyName(const char* src); // copies the src into the m_holderName array
      bool isValidNumber(int number)const; // returns true if number is a valid account number
   public:
      Account(const char* holderName = nullptr);
      Account(const char* holderName, int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      operator const char*() const;
      char& operator[] (int index);
      char operator[] (int index) const;
      bool operator~() const;
      Account& operator=(int number);
      Account& operator=(double balance);
      Account& operator+=(double value);
      Account& operator-=(double value);
      Account& operator<<(Account& otherAccount);
      Account& operator>>(Account& otherAccount);
      Account& operator++();
      Account operator++(int);
      Account& operator--();
      Account operator--(int);




   };
  

}
#endif // SENECA_ACCOUNT_H_