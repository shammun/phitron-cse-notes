#include<iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
#include <sstream> // Include the stringstream library for string stream operations
#include <algorithm> // Include the algorithm library for sort function
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    string s;
    cin >> s; // Take input from the user with spaces
    cout << s << endl; // Output the entered string
    sort(s.begin(), s.end()); // Sort the string
    cout << "After sorting using sort function: " << s << endl; // Output the sorted string

    return 0; // Indicate that the program ended successfully
}