// Topic: the all-in-one header <bits/stdc++.h>, plus the ready-made min, max and swap functions.
// Example input:  7 3
// Example output:
//   3 7        (min then max of a and b)
//   2 8        (min and max of the list 2..8)
//   3 7        (a and b after swapping: a was 7, b was 3)

#include <bits/stdc++.h>

// bits/stdc++.h is a header file that
// includes all the standard library headers
// in one file.
// It is a common practice to include the
// header file using the #include directive
// in a C++ program.
// So this one line gives us <iostream> (cin, cout), <algorithm> (min, max, swap, sort),
// <string>, <vector> and the rest - no need to remember which header holds what.
// Note: it is a GCC-only header (fine for contests/practice), and it makes compiling a bit slower.

using namespace std; // Lets us write cin, cout, min, max, swap instead of std::cin, std::cout, std::min ...

// main() is where the program starts running.
int main(){
    int a,b; // Two integer variables for the two numbers we will read
    cin >> a >> b; // Read two integers separated by space/newline: first goes into a, second into b
    // The manual way (commented out, kept for comparison): print the smaller one first using if/else.
    // if(a < b) cout << a << " " << b << endl;
    // else cout << b << " " << a << endl;

    // min(a,b) returns the smaller of the two, max(a,b) the larger. Both must be the same type.
    // With a = 7, b = 3 this prints "3 7".
    cout << min(a,b) << " " << max(a,b) << endl;

    // if more than two numbers:
    // put them inside curly braces { } - that makes an "initializer list", and min/max
    // return the smallest/largest value in that list. Here it prints "2 8".
    cout << min({2,3,4,5,6,7,8}) << " " << max({2,3,4,5,6,7,8}) << endl;

    // swap in C (commented out): we need a third variable 'temp' to hold one value
    // while the other is copied over.
    // int temp = a;
    // a = b;
    // b = temp;
    // cout << a << " " << b << endl;

    // swap:
    // swap(a,b) exchanges the values of a and b in one call (it does the temp trick for us).
    // With a = 7, b = 3 -> after swap a = 3, b = 7.
    swap(a,b);
    cout << a << " " << b << endl; // Print the swapped values

    return 0; // Program ended successfully
}