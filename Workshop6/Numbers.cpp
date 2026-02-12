/* Citation and Sources...
-----------------------------------------------------------
Workshop 6
Module: Numbers
Filename: Numbers.cpp
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
Done all the work by myself with help from AI modules such as Claude & ChatGPT, guiding me along the way whenever I got stuck. Helped me understand core concepts so I could finish this workshop.
-----------------------------------------------------------
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Numbers.h"

using namespace std;

namespace seneca {

	int Numbers::numberCount() const {
		int count = 0;

		if (m_filename == nullptr) {
			return 0; // if there's no file there are no numbers
		}

		ifstream file(m_filename);
		if (!file) {
			return 0; // if file can't be opened there are no numbers
		}
		
		char ch{};
		while (file.get(ch)) {
			if (ch == '\n') {
				count++; // count the number of lines in the file, which corresponds to the number of numbers
			}
		}
		return count;
	} // numberCount() 

	bool Numbers::load() {
		bool ok = false;

		delete[] m_numbers; // clear any previous data
		m_numbers = nullptr;
		m_numCount = 0;

		if (m_filename == nullptr) {
			return false; // if there's no file we can't load anything
		}
		m_numCount = numberCount(); // get the number of numbers in the file
		if (m_numCount <= 0) {
			return false; // if there are no numbers in the file we can't load anything
		}

		ifstream file(m_filename);
		if (!file) {
			return false;
		}

		m_numbers = new double[m_numCount]; 
		int i = 0;
		while (i < m_numCount && (file >> m_numbers[i])) {
			i++; // read the numbers from the file into the array
		}

		if (i == m_numCount) {
			ok = true; 
			sort(); // sort the numbers after loading them (from Numbers_prof.cpp)
		}
		else {
			delete[] m_numbers; // if we couldn't read all the numbers clear the array & return false
			m_numbers = nullptr;
			m_numCount = 0; 
			ok = false; 
		}
		return ok;
	} // load() 

	void Numbers::save() const {
		// only save if this is the original object, it's not empty, and there's a filename to save to
		if (m_isOriginal && !isEmpty() && m_filename != nullptr) {
			ofstream file(m_filename);

			for (int i = 0; i < m_numCount; i++) {
				file << m_numbers[i] << endl; // write the numbers to the file one per line
			}
		}
	} // save()

	std::ostream& Numbers::display(std::ostream& os) const {
		// 1) handle the "empty object" case first
		if (isEmpty()) {
			os << "Empty list";
			return os; // return the same stream for chaining
		}

		// 2) from here on we know we have data
		os << std::fixed << std::setprecision(2);

		// 3) header line (exact characters matter for matching the output)
		os << "=========================" << '\n';

		// 4) print source label:
		//    - original object prints filename
		//    - copy prints "*** COPY ***"
		if (m_isOriginal && m_filename != nullptr) {
			os << m_filename << '\n';
		}
		else {
			os << "*** COPY ***" << '\n';
		}

		// 5) print the numbers, comma + space separated
		for (int i = 0; i < m_numCount; i++) {
			os << m_numbers[i];
			if (i < m_numCount - 1) os << ", ";
		}
		os << '\n';

		// 6) divider
		os << "-------------------------" << '\n';

		// 7) stats section
		os << "Total of " << m_numCount << " number(s)" << '\n';
		os << "Largest number:  " << max() << '\n';
		os << "Smallest number: " << min() << '\n';
		os << "Average:         " << average() << '\n';

		// 8) footer line 
		os << "=========================";

		return os;
	} // display()

	Numbers::~Numbers() {
		save(); // only writes if original + not empty
		delete[] m_numbers;
		m_numbers = nullptr;
		delete[] m_filename; 
		m_filename = nullptr; 

	}

	Numbers::Numbers(const Numbers& other) {
		setEmpty(); // set to empty state using setEmpty() from Numbers_prof.cpp
		m_isOriginal = false; 

		if (!other.isEmpty()) { 
			m_numCount = other.m_numCount;
			m_numbers = new double[m_numCount];
			for (int i = 0; i < m_numCount; i++) {
				m_numbers[i] = other.m_numbers[i];
			}
		}
	}

	Numbers& Numbers::operator=(const Numbers& other) {
		if (this != &other) { // check for self assignment from src/other
			delete[] m_numbers; // if it's not src/other set to empty state
			m_numbers = nullptr;
			m_numCount = 0;

			if (!other.isEmpty()) { 
				m_numCount = other.m_numCount;
				m_numbers = new double[m_numCount];
				for (int i = 0; i < m_numCount; i++) {
					m_numbers[i] = other.m_numbers[i];
				}
			}
		}
		return *this;
	} // operator=

	Numbers& Numbers::operator+=(double value) {
		if (!isEmpty()) {
			// 1) create a larger array
			double* temp = new double[m_numCount + 1];

			// 2) copy existing numbers
			for (int i = 0; i < m_numCount; i++) {
				temp[i] = m_numbers[i];
			}

			// 3) append new value at end
			temp[m_numCount] = value;

			// 4) delete old memory 
			delete[] m_numbers;

			// 5) redirect pointer to new array
			m_numbers = temp;

			// 6) update count
			m_numCount++; 

			// 7) keep numbers sorted (prof already wrote sort()) 
			sort();
		}
		return *this; 
	} // operator+=()

	std::ostream& operator<<(std::ostream& os, const Numbers& N) {
		return N.display(os); 
	} // operator<<

	std::istream& operator>>(std::istream& is, Numbers& N) {
		double value{};
		if (is >> value) {      // only add if extraction succeeded
			N += value;
		}
		return is;
	}




} // end of namespace seneca 