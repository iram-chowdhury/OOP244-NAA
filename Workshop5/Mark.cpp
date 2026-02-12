/* Citation and Sources...
-----------------------------------------------------------
Workshop 5
Module: Mark
Filename: Mark.cpp
-----------------------------------------------------------
Author: Aryan Chowdhury
Student number: 138197181
Email: ichowdhury6@myseneca.ca
Subject: OOP244-NAA
-----------------------------------------------------------
Revision History
-----------------------------------------------------------
Version Date      Reason
V1.0 2026/02/04
-----------------------------------------------------------
Done all the work by myself with help from AI modules such as Claude & ChatGPT, guiding me along the way whenever I got stuck. Helped me understand core concepts so I could finish this workshop. 
-----------------------------------------------------------  
*/

#include <iostream>
#include <cmath> // for round function
#include <iomanip> // for formatting
#include "Mark.h"
using namespace std;
namespace seneca {
   bool Mark::isValid()const {
      return  (m_value >= 0 && m_value <= 100);
   }
   Mark::Mark(int value, char type) {
      *this = type;
      m_value = double(value);
   }

   Mark::Mark(double value) {
      m_type = MARK;
      m_value = value;
   }

   Mark& Mark::operator+=(const Mark& M) {
      m_value += M.m_value;
      return *this;
   }

   Mark& Mark::operator-=(const Mark& M) {
      m_value -= M.m_value;
      return *this;
   }

   Mark Mark::operator+(const Mark& M) const {
      return Mark(*this) += M;
   }

   Mark Mark::operator-(const Mark& M)const {
      return Mark(*this) -= M;
   }

   Mark& Mark::operator/=(int other) {
      m_value = m_value / other;
      return *this;
   }

   Mark Mark::operator/(int other) const {
      return Mark(m_value / other);
   }

   Mark& Mark::operator=(int value) {
      m_value = value;
      return *this;
   }

   Mark& Mark::operator=(char type) {
      m_type = MARK;
      if (type == GRADE || type == GPA) {
         m_type = type;
      }
      return *this;
   }

   double Mark::raw() const {
      return m_value;
   }

   Mark::operator int() const {
      int value = -1;
      if (isValid()) {
         value = int(std::round(m_value < 0 ? 0 : m_value));
      }
      return value;
   }
   Mark::operator bool() const {
      return isValid();
   }


   // returns the GPA not the m_value!!!
   Mark::operator double() const {
      double gpa = 0;
      if (!isValid()) gpa = -1;
      else gpa = m_value * 0.04;
      return gpa;
   }

   Mark::operator const char* () const {
      // removes the constantness of m_grade!
      // You will learn this at the end of the semester.
      char* grade = const_cast<char*>(m_grade);

      int value = int(*this);
      grade[1] = grade[2] = '\0';
      if (value < 0 || value > 100) grade[0] = 'X';
      else if (value >= 90) grade[0] = 'A', grade[1] = '+';
      else if (value >= 80) grade[0] = 'A';
      else if (value >= 75) grade[0] = 'B', grade[1] = '+';
      else if (value >= 70) grade[0] = 'B';
      else if (value >= 65) grade[0] = 'C', grade[1] = '+';
      else if (value >= 60) grade[0] = 'C';
      else if (value >= 55) grade[0] = 'D', grade[1] = '+';
      else if (value >= 50) grade[0] = 'D';
      else grade[0] = 'F';
      return m_grade;
   }

   // student helper function implementations go here
   ostream& Mark::display(ostream& ostr) const {
      if (!isValid()) {
         if (m_type == GRADE) {
            ostr << "**"; 
         } else {
            ostr << "***";
         }
      } else {
         switch (m_type) {
            case GPA:
               ostr << fixed << setprecision(1) << setw(3) << double(*this);
               break;
            case MARK:
               ostr << right << setfill('_') << setw(3) << int(*this);
               break;
            case GRADE: 
               ostr << left << setfill(' ') << setw(3) << (const char*)(*this);
               break;
         } 
      }
      return ostr;
   } 

   ostream& display(const Mark& M, char type, ostream& ostr) {
      M.display(ostr); 

      if (type != MARK) {
         ostr << ": ";
         Mark temp = M;
         temp = type;
         temp.display(ostr);
      }
      
      return ostr; 
   }

   ostream& operator<<(ostream& ostr, const Mark& M) {
      return M.display(ostr);
   }

   istream& operator>>(istream& istr, Mark& M) {
      int value; 
      char nextChar;
      bool done = false;

      while (!done) {
         istr >> value;
         if(istr.fail()) {
            istr.clear();
            istr.ignore(1000, '\n');
            cout << "Invalid integer, try again.\n> ";
         } else {
            nextChar = istr.get();
            if (nextChar != '\n') {
               istr.ignore(1000, '\n');
               cout << "Invalid trailing characters. Please enter only an integer.\n> ";
            } else if (value < 0 || value > 100) {
               cout << "Invalid mark. Enter a value between 0 and 100.\n> ";
            } else {
               M = value;
               done = true;
            }
         }
      }
      return istr;
   }

   ifstream& operator>>(std::ifstream& ifstr, Mark& M) {
      int value;
      char type;
      char comma;

      if (ifstr >> value >> comma >> type) {
         if (comma == ',') {
            M = value;
            M = type;
         } else {
            ifstr.setstate(ios::failbit); 
         }
      }
      return ifstr; 
   }

   double operator+(double left, const Mark& right) {
      return left + right.raw();
   }

   int operator+(int left, const Mark& right) {
      return left + int(right);
   }

   double operator-(double left, const Mark& right) {
      return left - right.raw();
   }

   int operator-(int left, const Mark& right) {
      return left - int(right);
   }

   double operator/(double left, const Mark& right) {
      return left / right.m_value;
   }

   int operator/(int left, const Mark& right) {
      return left / int(std::round(right.m_value));  
   }

} // end of namespace seneca