/*

Max
time limit per test: 1 second
memory limit per test: 256 megabytes
Given a number N, and N numbers, find maximum number in these N numbers.

Input
First line contains a number N (1 ≤ N ≤ 103).

Second line contains N numbers Xi (0 ≤ Xi ≤ 109).

Output
Print the maximum number.

Example
Input
5
1 8 5 7 5
Output
8

*/

// (In the statement above, "103" means 10^3 = 1000 and "109" means 10^9 -
//  the superscripts were lost when the text was copied.)
// Idea: walk through the numbers once, always remembering the biggest seen so far.

#include <iostream> // gives cin (read from keyboard) and cout (print to screen)
using namespace std; // lets us write cin/cout instead of std::cin/std::cout

int main(){ // the program starts running here
    int n; // how many numbers will follow
    cin >> n; // cin skips spaces/newlines and reads one whole number

    // Read the n numbers into an array (values up to 10^9 still fit in an int,
    // whose largest value is about 2.1 * 10^9)
    // int arr[n] uses a size known only at run time (a "variable-length array").
    // Standard C++ does not allow this, but g++ accepts it as an extension;
    // the standard-C++ way is int *arr = new int[n]; (see max_using_max_function.cpp).
    int arr[n];
    for(int i=0; i<n; i++){ // i = 0..n-1, one number per pass
        cin >> arr[i]; // store the i-th number in box i
    }

    // Keep "the biggest seen so far". Start with the first number, not 0,
    // so the idea would still work if the numbers could be negative.
    // (The variable is named max. That is allowed: a local variable simply hides
    //  any std::max function of the same name inside main.)
    int max = arr[0];
    // Start at i = 1: box 0 is already in max.
    // Trace with 1 8 5 7 5: max=1 -> 8>1 so max=8 -> 5,7,5 are not bigger -> 8
    for(int i=1; i<n; i++){
        if(arr[i] > max){ // is this number bigger than the best so far?
            max = arr[i]; // found a bigger one - remember it instead
        }
    }

    cout << max << endl; // print the answer; endl = newline

    return 0; // the program ended fine
}