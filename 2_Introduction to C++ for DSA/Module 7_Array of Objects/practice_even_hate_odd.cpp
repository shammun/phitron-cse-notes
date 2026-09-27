/*

Even Hate Odd
time limit per test: 5 seconds
memory limit per test: 256 megabytes
You are given an array a of n integers. You have two kinds of operations

1. increment any element in a (increase it by one).
2. decrement any element in a (decrease it by one).

What is the minimum number of operations to make the number of even elements equal to the number of odd elements, or detect that this is impossible?

Input
The first line contains a single integer t(1≤t≤10)  the number of test cases.

The first line of each test case contains an integer n(1≤n≤10^5) the number of elements in the array a.

The second line of each test case contains n integers ai(1≤ai≤10^5) the elements of the array a.

Output
For each test case, print the minimum number of operations required, or −1 if it's impossible

Example
Input
3
4
1 2 3 4
4
1 1 1 1
3
1 2 3
Output
0
2
-1

*/

#include <iostream> // Include the input/output stream library for using cin and cout
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

// The idea: one +1 or -1 turns an even number odd, or an odd number even.
// So each operation moves exactly one element from one group to the other,
// and the only question is how many elements have to move.
// Trace with {1,1,1,1}: n = 4, target = 2, even_count = 0 -> 2 odd numbers must become even -> answer 2.
int main(){ // Program execution starts here
    int t; // number of test cases
    cin >> t; // read t
    int answers[10]; // t is at most 10; answers[test] stores the result of each test case to print at the end

    // One pass of this loop solves one whole test case (test = 0, 1, ..., t-1)
    for(int test=0; test<t; test++){
        int n; // how many numbers in this test case
        cin >> n; // read n

        // If n is odd, it can't be done: two equal groups need an even total.
        // The numbers must still be read, or they would be taken as the next test case.
        if(n%2 != 0){ // % gives the remainder; n%2 != 0 means n is odd
            for(int i=0; i<n; i++){ // read and throw away all n numbers
                int x; // temporary box, used only to consume one number
                cin >> x; // read it (value not needed)
            }
            answers[test] = -1; // impossible
            continue; // skip the rest of this pass and go to the next test case
        }

        int target = n/2; // each group must end up with exactly half
        // Room for up to 100001 numbers (n <= 10^5). About 400 KB, declared inside the loop
        // on the stack; it fits, but a global array or vector is the safer habit for big sizes.
        int a[100001];
        int even_count = 0; // how many even numbers we have seen so far

        // Read array and count even numbers
        for(int i=0; i<n; i++){
            cin >> a[i]; // read the i-th number
            if(a[i]%2 == 0){ // remainder 0 when divided by 2 -> even
                even_count++; // one more even number
            }
        }

        if(even_count == target){ // already balanced
            answers[test] = 0; // no operation needed
            continue; // next test case
        }

        // Every extra even number must become odd (or every missing one must
        // come from an odd number): one operation each.
        if(even_count > target){ // too many evens
            answers[test] = even_count - target; // turn the extra evens into odds
        } else{ // too few evens (too many odds)
            answers[test] = target - even_count; // turn that many odds into evens
        }
    }

    // Print the stored answers, one per line, in test-case order
    for(int i=0; i<t; i++){
        cout << answers[i] << endl; // endl = newline (and flush the output)
    }

    return 0; // Indicate that the program ended successfully
}
