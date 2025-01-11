#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file;
    
    // Open file in write mode (output mode)
    file.open("sample.txt", ios::out);
    if (!file) {
        cout << "Error in creating file!!!";
        return 0;
    }
    
    // Write A to Z to the file
    file << "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    // Print the current write position using tellp
    cout << "Current position after writing A to Z is: " << file.tellp() << endl;

    // Use seekp to move the write pointer to position 5 (after writing 'E')
    file.seekp(5);
    file << "#";  // Replace the character at position 5 (F) with '#'

    // Print the current write position after seekp and modification
    cout << "Position after seekp and modifying: " << file.tellp() << endl;
    
    // Close the file after writing
    file.close();

    // Open file in read mode
    file.open("sample.txt", ios::in);
    if (!file) {
        cout << "Error in opening file!!!";
        return 0;
    }

    // Print the current read position using tellg
    cout << "Current read position at start: " << file.tellg() << endl;

    // Use seekg to move the read pointer to position 5
    file.seekg(5);
    
    // Print the current read position after seekg
    cout << "Position after seekg(5): " << file.tellg() << endl;
    
    // Read one character from position 5
    char ch;
    file >> ch;
    cout << "Character read at position 5: \"" << ch << "\"" << endl;

    // Move to position 10 and read from there
    file.seekg(10);
    cout << "Position after seekg(10): " << file.tellg() << endl;
    file >> ch;
    cout << "Character read at position 10: \"" << ch << "\"" << endl;

    // Close the file after reading
    file.close();
    
    return 0;
}
