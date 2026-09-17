#include <iostream> // This header file is used to perform input and output operations
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

int main(){
    int x; // Declaring an integer variable x to store the user input
    cin >> x; // Taking input from the user and storing it in variable x

    // cin.ignore() is used to ignore the newline character left in the input buffer after reading the integer
    // This is necessary because the newline character would otherwise be read by the next input operation
    cin.ignore();

    char s[100]; // Declaring a character array s to store the string input
    // cin.getline() is used to read a line of text from the user, including spaces
    // The first argument is the character array to store the input
    // The second argument is the maximum number of characters to read
    cin.getline(s, 100);

    // Printing the integer and the string on separate lines
    // The endl manipulator is used to insert a newline character and flush the output buffer
    cout << x << endl << s << endl;

    // Another way to take string input with spaces
    // We don't need to use char array or cin.getline()
    string s2; // Declaring a string variable s2 to store the user input
    int y;
    cin >> y;
    cin >> s2; // Taking input from the user and storing it in variable s2

    cout << y << endl << s2 << endl; // Printing the string on a single line

    return 0; // return 0 indicates that the program ended successfully
}