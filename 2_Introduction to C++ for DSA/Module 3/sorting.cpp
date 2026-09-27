/*
 * Sorting an array with the built-in sort() function.
 *
 * sort(first, last) rearranges the elements from address `first` up to (but NOT
 * including) address `last` into ascending order (small to big). It is fast:
 * about n*log(n) steps, much quicker than bubble sort for big arrays.
 * sort(first, last, greater<int>()) uses a different comparison, so the order
 * becomes descending (big to small).
 *
 * Sample input:          Sample output:
 *   5                      Array before sorting: 3 1 5 2 4
 *   3 1 5 2 4              Array after ascending sort: 1 2 3 4 5
 *                          Array after descending sort: 5 4 3 2 1
 */

#include <iostream>  // Include the iostream library for input/output operations
#include <algorithm> // Include the algorithm library for using the sort function and greater<int>()
#include <string.h>  // Include string.h for character array operations (not used in this code)
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before standard library components

int main() {
    int n; // Declare an integer variable to store the size of the array
    cin >> n; // Input the size of the array from the user

    int a[n]; // Declare an array of size 'n' (Variable-length arrays are allowed in some compilers such as g++, but std::vector is preferred in standard C++)

    // Input the elements of the array
    // i goes 0, 1, ..., n-1: one pass reads one number into box a[i].
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
    // a = address of the first box, a + n = address just AFTER the last box (a[n-1]),
    // so the range [a, a + n) covers the whole array. {3,1,5,2,4} -> {1,2,3,4,5}
    sort(a, a + n); // Sorts the elements in the range [a, a + n) in ascending order

    // Output the array after ascending sort
    cout << "Array after ascending sort: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " "; // Print each element of the sorted array
    }
    cout << endl; // Move to the next line for better readability

    // Sort the array in descending order using the sort function with greater<int>()
    // 'greater<int>()' is a comparator (a function object) defined in the <functional> library
    // (it is available here because <algorithm>/<iostream> bring it in with g++).
    // A comparator answers "should x come before y?". greater<int>() answers x > y,
    // so bigger numbers come first. {1,2,3,4,5} -> {5,4,3,2,1}
    // The () after greater<int> creates the comparator object that is passed to sort.
    sort(a, a + n, greater<int>()); // Sorts the elements in the range [a, a + n) in descending order

    // Output the array after descending sort
    cout << "Array after descending sort: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " "; // Print each element of the descendingly sorted array
    }
    cout << endl; // Move to the next line for better readability

    return 0; // Return 0 indicates successful program execution
}
