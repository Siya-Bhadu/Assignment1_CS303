// Assignment1_CS303.h
// NAME: Siya Bhadu
// CLASS: CS303
// Header file for Assignment1_CS303.cpp

#pragma once
#include <stdexcept> // for exceptions

// Maximum size of the array
const int MAX_SIZE = 1000;

// 1. Function that finds integer & returns index value if it exists
int findIndex(const int array[], int size, int target);

// 2. Function that updates an integer in an array by index and returns old and new values
void modifyValue(int array[], int index, int newValue, int& oldValue, int& returnedNewValue);

// 3. Function that adds a new integer to the end of the array
void addIntToArray(int array[], int& size, int newInt);

// 4. Function that removes an integer from the array at a given index
void removeInt(int array[], int& size, int indexToModify);
