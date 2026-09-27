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

#include <iostream> // Include the input/output stream library for using cout
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

// The idea: one +1 or -1 turns an even number odd, or an odd number even.
// So each operation moves exactly one element from one group to the other,
// and the only question is how many elements have to move.
int main(){
    int t;
    cin >> t;
    int answers[10]; // t is at most 10

    for(int test=0; test<t; test++){
        int n;
        cin >> n;

        // If n is odd, it can't be done: two equal groups need an even total.
        // The numbers must still be read, or they would be taken as the next test case.
        if(n%2 != 0){
            for(int i=0; i<n; i++){
                int x;
                cin >> x;
            }
            answers[test] = -1;
            continue;
        }

        int target = n/2; // each group must end up with exactly half
        int a[100001];
        int even_count = 0;

        // Read array and count even numbers
        for(int i=0; i<n; i++){
            cin >> a[i];
            if(a[i]%2 == 0){
                even_count++;
            }
        }

        if(even_count == target){
            answers[test] = 0;
            continue;
        }

        // Every extra even number must become odd (or every missing one must
        // come from an odd number): one operation each.
        if(even_count > target){
            answers[test] = even_count - target;
        } else{
            answers[test] = target - even_count;
        }
    }

    for(int i=0; i<t; i++){
        cout << answers[i] << endl;
    }

    return 0; // Indicate that the program ended successfully
}