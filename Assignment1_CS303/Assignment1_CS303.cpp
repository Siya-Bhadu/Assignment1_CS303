// Assignment1_CS303.cpp : This file contains the 'main' function. Program execution begins and ends there.
// NAME: Siya Bhadu
// CLASS: CS303

#include <iostream> // For input/output streamd
#include <fstream> // For file handling
#include <stdexcept> // For exceptions like out_of_range

using namespace std;
const int MAX_SIZE = 1000; // Declares maximum size of the array

// 1. Function that finds integer & returns index value if it exists.

int findIndex(const int array[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}


// 2. Function that updates an integer in an array by index and returns both old and new values. 

void modifyValue(int array[], int index, int newValue, int& oldValue, int& returnedNewValue)
{
    if (index < 0 || index >= MAX_SIZE) {
        throw std::out_of_range("Index out of bounds."); 
    }

    oldValue = array[index]; // Store the original value
    array[index] = newValue; // Update array with the new value
    returnedNewValue = newValue; // Pass the new value back to the caller
}


// 3. A function that adds a new integer to the end of the array

void addIntToArray(int array[], int& size, int newInt)
{
    if (size >= MAX_SIZE) { // Checks to ensure it is within range
        throw std::overflow_error("Array is full, cannot add more integers."); 
    }

    array[size] = newInt; // Add the new integer at the end of the array
    size++; // Increase the array size to reflect addition of the new element
}


// 4. A function which intakes an index of an array and removes the integer altogether

void removeInt(int array[], int& size, int indexToModify) {
    if (indexToModify < 0 || indexToModify >= size) {
        throw std::out_of_range("Index is out of bounds."); // Throw exception if index is invalid
    }

    // Shift elements left to overwrite the removed element
    for (int i = indexToModify; i < size - 1; i++) {
        array[i] = array[i + 1]; // Move each element one position left
    }

    --size; // Decrease array size since one element was removed
}


int main()
{
    int array[MAX_SIZE];
    int size = 0;
    string fileName = "A1input.txt";
    int oldValue = 0;
    int newValue = 0;
    int returnedNewValue = 0;
    int newInt = 0;
    int indexToModify = 0;


    // Open the input file
    ifstream inFile(fileName);
    if (!inFile) {
        cerr << "Error opening file: " << fileName << endl;
        return 1;
    }

    // Read data from the file into the array
    while (inFile >> array[size]) {
        ++size;
        if (size >= MAX_SIZE) {
            cout << "Array size exceeded maximum limit of " << MAX_SIZE << endl;
            break;
        }
    }
    inFile.close();


    // 1.
    int numberToFind;
    cout << "Enter the number to find: ";
    cin >> numberToFind;

    // Find the index of the number in the array
    int index = findIndex(array, size, numberToFind);

    if (index != -1) {
        cout << "Number " << numberToFind << " found at index " << index << "." << endl;
    }
    else {
        cout << "Number " << numberToFind << " not found in the array." << endl;
    }


    // 2. *Q2 - Includes Try/Catch Block

    try {
        cout << "Enter desired index to change: ";
        cin >> index;

        if (index < 0 || index >= size) {
            throw out_of_range("Invalid index entered.");
        }

        oldValue = array[index];
        cout << "The value is: " << array[index] << endl;

        cout << "Enter the index's new value: ";
        cin >> newValue;

        modifyValue(array, index, newValue, oldValue, returnedNewValue);

        // Print the array after modification
        cout << "New Array: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }


    // 3. *Q2 - Includes Try/Catch Block

    try {
        cout << "Enter a new integer to add: ";
        cin >> newInt;

        addIntToArray(array, size, newInt);

        cout << "New Array: ";
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }
    catch (const overflow_error& e) {
        cerr << "Error: " << e.what() << endl;
    }


    // 4.

    cout << "Type the index of the number that you want to remove: ";
    cin >> indexToModify;

    try {
        removeInt(array, size, indexToModify);
    }
    catch (const std::out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }

    cout << "New Array: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;

}

