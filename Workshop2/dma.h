/* Citation and Sources...
-----------------------------------------------------------
Workshop 2
Module: dma.h
Filename: dma.h
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

#ifndef SENECA_DMA_H
#define SENECA_DMA_H

struct Samples {
    char* m_title;   // Dynamically allocated title
    int* m_data;     // Dynamically allocated array of integers
    int m_size;   // Number of elements in m_data
};

Samples* CreateSamples(const char* title);
void add(Samples& target, const int data[], int size);
void append(int*& data, int size, const int appendedData[], int dataSize);
void freemem(Samples*& s);

#endif // !SENECA_DMA_H