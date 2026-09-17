#include <iostream>  // Include the iostream library for input/output operations
#include <algorithm> // Include the algorithm library for using the sort function and greater<int>()
#include <string.h>  // Include string.h for character array operations (not used in this code)
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before standard library components

int main() {
    int n; // Declare an integer variable to store the size of the array
    cin >> n; // Input the size of the array from the user

    int a[n]; // Declare an array of size 'n' (Variable-length arrays are allowed in some compilers, but std::vector is preferred in standard C++)

    // Input the elements of the array
    for (int i = 0; i < n; i++) {
        cin >> a[i]; // Read each element of the array from the user
    }

    // Output the array before sorting
    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " "; // Print each element followed by a space
    }
    cout << endl; // Move to the next line for better readability

    // Sort the array in ascending order using the sort function
    // The 'sort' function is defined in the <algorithm> library and sorts the array in ascending order by default
    sort(a, a + n); // Sorts the elements in the range [a, a + n) in ascending order

    // Output the array after ascending sort
    cout << "Array after ascending sort: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " "; // Print each element of the sorted array
    }
    cout << endl; // Move to the next line for better readability

    // Sort the array in descending order using the sort function with greater<int>()
    // 'greater<int>()' is a comparator function defined in the <functional> library
    sort(a, a + n, greater<int>()); // Sorts the elements in the range [a, a + n) in descending order

    // Output the array after descending sort
    cout << "Array after descending sort: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " "; // Print each element of the descendingly sorted array
    }
    cout << endl; // Move to the next line for better readability

    return 0; // Return 0 indicates successful program execution
}
