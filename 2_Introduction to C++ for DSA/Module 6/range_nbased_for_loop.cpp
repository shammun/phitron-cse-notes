#include<iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
#include <sstream> // Include the stringstream library for string stream operations
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    string s;
    cin >> s; // Take input from the user with spaces
    /*
    for(int i = 0; i < s.size(); i++){
        cout << s[i] << " ";
    }
    */
    // Shortcut for the above code
    for(char c: s){
        cout << c << " ";
    }

    return 0; // Indicate that the program ended successfully
}
