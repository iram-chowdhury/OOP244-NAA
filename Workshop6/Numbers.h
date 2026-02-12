/***********************************************************************
// OOP244 Workshop 6 lab
// 
// File	Numbers.h
// Version 0.1
// Author	Fardad Soleimanloo
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: Numbers
Filename: Numbers.h
-----------------------------------------------------------
Author: Aryan Chowdhury
Student number: 138197181
Email: ichowdhury6@myseneca.ca
Subject: OOP244-NAA
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date      Reason
V1.0 2026/02/11
-----------------------------------------------------------
Most of this header was provided but in private everything under the comments was added by me 
-----------------------------------------------------------
*/

#ifndef SENECA_NUMBERS_H_
#define SENECA_NUMBERS_H_
#include <iostream>
namespace seneca {
   class Numbers {
   private:
      double* m_numbers;
      char* m_filename;
      bool m_isOriginal;
      int m_numCount;
      bool isEmpty()const;
      void setEmpty();
      void setFilename(const char* filename);
      void sort();
      // everything under here was added by me
      std::ostream& display(std::ostream& os) const;
      int numberCount() const;
      bool load();
      void save() const;

   public:
      Numbers();
      Numbers(const char* filename);
      double average()const;
      double max()const;
      double min()const;
      // everything under here was added by me 
      ~Numbers(); // destructor 
      Numbers(const Numbers& other); // copy constructor 
      Numbers& operator=(const Numbers& other); // assignment operator
      Numbers& operator+=(double value); // lets us do N += 50 instead of something like N.add(50)
      friend std::ostream& operator<<(std::ostream& os, const Numbers& N); // enables cout << N
      friend std::istream& operator>>(std::istream& is, Numbers& N);
   };
   // everything under here was also added by me
   std::ostream& operator<<(std::ostream& os, const Numbers& N); // enables cout << N
   std::istream& operator>>(std::istream& is, Numbers& N); // enables file >> N 


} // end of namespace seneca 
#endif // !SENECA_NUMBERS_H_

