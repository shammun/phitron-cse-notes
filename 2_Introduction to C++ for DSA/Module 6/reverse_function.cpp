#include<iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
#include <sstream> // Include the stringstream library for string stream operations
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    int n;
    cin >> n; // Take input from the user
    int a[n]; // Create an array of size n
    for(int  i=0; i<n; i++){
        cin >> a[i]; // Take input for the array
    }
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
    reverse(a, a+n); // Reverse the array using the reverse function
    for(int i=0; i<n; i++){
        cout << a[i] << " "; // Print the array
    }

    cout << "Now, we will reverse the string" << endl;
    string s;
    cin >> s; // Take input from the user
    reverse(s.begin(), s.end()); // Reverse the string using the reverse function
    cout << s << endl; // Print the reversed string

    return 0; // Indicate that the program ended successfully
}