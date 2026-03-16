/* Citation and Sources...
Final Project Milestone 1:
Module: Menu
Filename: Menu.cpp
Version 1.0
Author: Aryan Chowdhury St No: 138197181 Email: ichowdhury6@myseneca.ca
For OOP244 NAA
Revision History
-----------------------------------------------------------
Date      Reason
2026/03/11			Milestone 1 
-----------------------------------------------------------
Most of the work was done by myself while also using AI tools such as ChatGPT & Claude to guide me along the way to understand crucial concepts. Especially when stuck I would ask questions to gain more understanding, the comments throughout this file highlights that clearly. I feel as if this project would've been almost impossible to finish without the help of AI if done completely & utterly alone. 
-----------------------------------------------------------*/

#include "Menu.h" 
#include <cstring>
#include <cctype>
#include <iomanip>

using namespace std;

namespace seneca {

	MenuItem::MenuItem() {
		menuItemName = nullptr;
		setSafeEmptyState(); // sets object to empty state while reusing code :) 
	} // end of MenuItem();

	MenuItem::MenuItem(const char* string, unsigned int indents, unsigned int indentSize, int rowNumber) {
		menuItemName = nullptr;
		setSafeEmptyState(); // we're gonna first set it to a safe empty state by reusing code (function above)  

		bool notValidString = false; // a flag to check if the content of the string is valid (not empty or if it only contains whitespace)

		if (!string || !*string) { 
			notValidString = true; // if the string is null or if the first character of the string is the null terminator (which means it's an empty string) we set the flag to true
		} else {
			notValidString = true; 
			for (const char* currentCharacter = string; *currentCharacter; ++currentCharacter) {
				if (!std::isspace(static_cast<unsigned char>(*currentCharacter))) { // used Claude to help me figure out how to check if a string only contains whitespace
					notValidString = false; // if we find any character that is not a whitespace, we set the flag to false & break out the loop
					break;
				}
			}
		}

		bool notValidIndent = false; // flag 
		if (indents > 4u || indentSize > 4u) { 
			notValidIndent = true; 
		}

		bool notValidRow = false; // flag 
		if (rowNumber > static_cast<int>(MaximumNumberOfMenuItems)) { // make sure row number isn't bigger than the constant we gave in Constants.h also used Claude to figure this out
			notValidRow = true; 
		}

		if (notValidString == true || notValidIndent == true || notValidRow == true) {
			return; // if any of the flags are true, we return early & the object will remain in a safe empty state 
		}

		// if not we copy the values given as arguments over to the current object
		size_t length = std::strlen(string); 
		menuItemName = new char[length + 1];
		std::strcpy(this->menuItemName, string);

		this->menuItemIndents = indents;
		this->menuItemIndentSize = indentSize;
		this->menuItemNumber = rowNumber; 
	} // end of MenuItem(const char* string, unsigned int indents, unsigned int indentSize, int row); 

	MenuItem::~MenuItem() {
		delete[] this->menuItemName; // deletes the dynamically allocated memory for the menu item name to prevent memory leaks
		this->menuItemName = nullptr; // not needed but good practice to set back to nullptr after deleting
	} // end of ~MenuItem();

	MenuItem& MenuItem::setSafeEmptyState() {
		delete[] menuItemName; // deletes any dynamically allocated memory for the menu item name to prevent memory leaks
		this->menuItemName = nullptr;  // sets item name to nullptr so it's safe 
		this->menuItemIndents = 0u; 
		this->menuItemIndentSize = 0u;
		this->menuItemNumber = 0;
		return *this;
	} // end of setSafeEmptyState();

	MenuItem::operator bool() const { 
		return this->menuItemName != nullptr; // the object is considered valid if the menu item name isn't nullptr (aka valid string) 
	} // end of operator bool() const;

	std::ostream& MenuItem::display(std::ostream& COUT) const {
		if (!*this) { // uses the operator bool() from above 
			COUT << "??????????"; // if object isn't valid print 10 question marks (specified in instructions) 
			return COUT; 
		}

		unsigned totalNumberOfSpaces = this->menuItemIndents * this->menuItemIndentSize; // calculates total spaces to print

		for (unsigned i = 0; i < totalNumberOfSpaces; i++) {
			COUT.put(' '); // prints the number of spaces we calculated right before 
		}

		if (this->menuItemNumber >= 0) {
			COUT << setw(2) << this->menuItemNumber << "- "; // will print a - after the menuItemNumber so it should format as "4- The name of the menu item"
		}

		const char* firstNonspace = this->menuItemName; // 
		while (*firstNonspace && std::isspace(static_cast<unsigned char>(*firstNonspace))) {
			++firstNonspace; // basically checking if there's any whitespaces so it doesn't mess up on matrix. Used Claude to help me figure this out 
		}
		COUT << firstNonspace; // 
		return COUT;
	} // end of display(std::ostream& COUT) const;



} // end of namespace seneca 

