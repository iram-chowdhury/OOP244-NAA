/* Citation and Sources...
-----------------------------------------------------------
Workshop 2
Module: dma.cpp
Filename: dma.cpp
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
#include "dma.h"
#include "cstr.h"

using namespace std; 
using namespace seneca;

Samples* CreateSamples(const char* title) {
    Samples* sample = new Samples;

    int length = strlen(title) + 1; 
    sample->m_title = new char[length];

    strcpy(sample->m_title, title);

    sample->m_data = nullptr;
    sample->m_size = 0;

    return sample;
}

void add(Samples& target, const int data[], int size) {
    if (target.m_data == nullptr) {
        // Initial allocation
        target.m_data = new int[size];
        for (int i = 0; i < size; i++) {
            target.m_data[i] = data[i];
        }
        target.m_size = size;
        
    }
    else {
        int newSize = target.m_size + size;
        int* newData = new int[newSize];

        for (int i = 0; i < target.m_size; i++) {
            newData[i] = target.m_data[i];
        }

        for (int i = 0; i < size; i++) {
            newData[target.m_size + i] = data[i];
        }

        delete[] target.m_data;
        target.m_data = newData;
        target.m_size = newSize;
    }
}

void append(int*& data, int size, const int appendedData[], int dataSize) {
    int* newData = new int[size + dataSize];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    for (int i = 0; i < dataSize; i++) {
        newData[size + i] = appendedData[i];
    }

    delete[] data;
    data = newData;
}

void freemem(Samples*& target) {
    if (target) {
        delete[] target->m_title;
        delete[] target->m_data;
        delete target;
        target = nullptr;
    }
}
