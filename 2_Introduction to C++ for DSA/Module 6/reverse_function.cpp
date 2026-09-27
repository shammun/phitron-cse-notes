/*
The reverse() function.

reverse(first, last) turns around everything from first up to (but NOT
including) last. It works on arrays (give it pointers) and on strings
(give it iterators begin() and end()).
Example: a = {1, 2, 3, 4} -> reverse(a, a+4) -> {4, 3, 2, 1}.
*/

#include<iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string>   // Gives us std::string
#include <sstream> // stringstream library; not actually used in this file
// BUG: reverse() lives in <algorithm>, and this file does not include it.
// With this g++ the file does not compile ("'reverse' was not declared in this scope").
// Fix: add the line  #include <algorithm>  (or #include <bits/stdc++.h>) with the other includes.
using namespace std; // Lets us write cin, cout, string, reverse instead of std::cin, ...

int main() {
    int n; // how many numbers
    cin >> n; // Take input from the user
    int a[n]; // Create an array of size n (a size known only at run time is a g++ extension, called a VLA)
    // Read the n numbers into a[0], a[1], ..., a[n-1].
    for(int  i=0; i<n; i++){
        cin >> a[i]; // Take input for the array
    }
    // The same job done by hand with two pointers (commented out, kept for comparison):
    /*
    // Reverse the array using a for loop
    // Reverse the array using two pointers
    int i=0; // Initialize the first pointer to the first element
    int j=n-1; // Initialize the second pointer to the last element
    while(i < j){
        int temp = a[i]; // Store the value of the first pointer in a temporary variable
        a[i] = a[j]; // Assign the value of the second pointer to the first pointer
        a[j] = temp; // Assign the value of the temporary variable to the second pointer
        i++; // Increment the first pointer
        j--; // Decrement the second pointer
    }
    */
    // Reverse the array using the reverse function
    // for sort function,, this is sort(a, a+n);
    // a is the address of a[0]; a+n is the address just past the last element a[n-1],
    // so the range [a, a+n) is the whole array.
    reverse(a, a+n); // Reverse the array using the reverse function
    // Print the reversed array, numbers separated by spaces.
    for(int i=0; i<n; i++){
        cout << a[i] << " "; // Print the array
    }

    // Note: no newline was printed after the numbers, so this message appears on the same line.
    cout << "Now, we will reverse the string" << endl;
    string s; // a word to reverse
    cin >> s; // Take input from the user (one word: cin >> stops at a space)
    // begin() marks the first character, end() marks one past the last, so this is the whole string.
    reverse(s.begin(), s.end()); // Reverse the string using the reverse function ("abc" -> "cba")
    cout << s << endl; // Print the reversed string

    return 0; // Indicate that the program ended successfully
} // end of main
