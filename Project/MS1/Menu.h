/* Citation and Sources...
Final Project Milestone 1:
Module: Menu
Filename: Menu.h
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

#ifndef SENECA_MENU_H
#define SENECA_MENU_H
#include <iostream>
#include "constants.h"

namespace seneca {
	class MenuItem {
	private:
		char* menuItemName{}; // pointer to a dynamically allocated string that will hold the name of the menu item
		unsigned int menuItemIndents{}; // unsigned int to hold the number of indents for the menu item (how many times we indent before displaying menu item name)
		unsigned int menuItemIndentSize{}; // unsigned int to hold the indent size of the menu item (how many spaces before the menu item name is displayed)
		int menuItemNumber{}; // int to hold the row number of the menu item 


	public:
		MenuItem(); // default constructor that sets to safe empty state 
		MenuItem(const char* string, unsigned int indents, unsigned int indentSize, int row); // constructor that applies the name of the menu item, the number of indents, the indent size & the row number	
		~MenuItem(); // destructor 
		MenuItem& setSafeEmptyState(); // function to set safe empty state 
		MenuItem(const MenuItem&) = delete; // copy constructor that's deleted to prevent copying of MenuItem objects
		MenuItem& operator=(const MenuItem&) = delete; // copy assignment operator that's deleted to prevent copying of MenuItem objects
		std::ostream& display(std::ostream& COUT = std::cout) const; // function to display the menu item (takes an optional ostream reference parameter that defaults to std::cout, returns the ostream reference after displaying the menu item)
		operator bool() const; // conversion operator to bool that returns true if the menu item is valid (has a non-null name) & false otherwise	
	};
} // end of namespace seneca

#endif // end of Menu.h 