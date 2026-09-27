/*

N Times

time limit per test: 1 second
memory limit per test: 256 megabytes
Given a number N and a character C. Print the character(C) N times.

Note: Solve this problem using function.

Input

The first line contains a number T (1≤T≤50) the number of test cases.
Next T lines contains a number N and a character C (1≤N≤100).

Output
Print T lines, for every line print the character(C) N times separated by space.

Examples
Input
2
1 n
5 O
Output
n
O O O O O

Input
1
8 z
Output
z z z z z z z z

*/

#include <iostream> // Include the input/output stream library for using cin and cout (it also makes std::string usable here)
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

// The problem asks for a function. This one builds the whole answer line as
// a string and returns it: n copies of c with one space between them.
// Parameters: n = how many copies, c = the character. Return value: the finished line.
// With n = 3, c = 'O' the string grows "O" -> "O O" -> "O O O".
string generateString(int n, char c){
    string s = ""; // start with an empty string
    // One pass appends one copy of c; i counts the copies already added (0 .. n-1)
    for(int i=0; i<n; i++){
        s += c; // += adds one character to the end of a string
        if (i != n-1){ // not the last copy yet
            s += " "; // a space after every copy except the last
        }
    }
    return s; // a string can be returned like an int - it is copied out
}

int main(){ // Program execution starts here
    int t; // number of test cases
    cin >> t; // read t

    // T is at most 50: keep each test case's line and print them all at the end
    int n[50]; // n[i] = count for test case i
    char c[50]; // c[i] = character for test case i
    string outputs[50]; // outputs[i] = finished line for test case i

    // One pass reads one test case and builds its answer
    for(int i=0; i<t; i++){
        cin >> n[i] >> c[i]; // cin skips the space between the number and the character
        outputs[i] = generateString(n[i], c[i]); // call the function and store what it returns
    }

    // Print all answers, one line each
    for(int i=0; i<t; i++){
        cout << outputs[i] << endl; // endl = newline (and flush)
    }

    return 0; // Indicate that the program ended successfully
}
