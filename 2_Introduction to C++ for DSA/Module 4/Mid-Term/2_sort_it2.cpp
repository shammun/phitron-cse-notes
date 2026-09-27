/*

Problem Statement

You will be given an array A and the size of that array N. You need to create a function named sort_it(). After taking the input for the size in main function, call that function by giving the size as parameter and take the array input inside that function. After that, you need to sort the array in descending order. Then, return that array from the function and receive it in the main function. Finally, print the sorted array in the main function.

Input Format

First line will contain N.
Second line will contain the array A.
Constraints

1 <= N <= 10^5
-10^9 <= A[i] <= 10^9 Where 0 <= i < N
Output Format

Ouptut the array in descending order.
Sample Input 0

5
1 4 2 3 5
Sample Output 0

5 4 3 2 1

*/

#include <iostream>  // cin and cout (reading input and printing output)
#include <algorithm> // sort() and greater<int>()
using namespace std; // write cin/cout/sort instead of std::cin/std::cout/std::sort

// The question insists that the array is read and sorted inside sort_it()
// and then returned to main. Returning an array means returning its address,
// and that only works for an array made with new: it lives on the heap, so
// it survives the end of the function (a local `int a[n]` would not).
//   Parameter n : how many numbers to read.
//   Returns     : int* = address of the first element of the sorted heap array.
int* sort_it(int n){
    int* a = new int[n]; // new int[n]: reserve n ints on the heap; a holds the address of the first one
    // Read n numbers; pass i stores the next number in a[i]
    for(int i=0; i<n; i++){
        cin >> a[i]; // cin >> skips spaces/newlines and reads one whole number
    }
    // sort(first, one-past-last, rule). a..a+n covers the whole array.
    // {1,4,2,3,5} -> {5,4,3,2,1}
    sort(a, a+n, greater<int>()); // greater<int>() puts the bigger value first -> descending
    return a; // hand the address back to main
}

int main(){ // program starts here

    int n;     // size of the array
    cin >> n;  // read N in main, as the question asks
    int* sorted_array = sort_it(n); // n is read here in main and passed in, as asked

    // Print the sorted array (it is already sorted in descending order).
    // i walks 0..n-1; a pointer can be indexed just like an array.
    for(int i=0; i<n; i++){
        cout << sorted_array[i] << " "; // value then a space
    }
    cout << endl; // end the output line

    delete[] sorted_array; // new[] in the function, delete[] once main is done with it

    return 0; // program ended normally
}