/*

Practice Day 01 (Module 2.5) - Question 2: move an array into a bigger one

Read an int array A of N elements. Then read M (M >= N) and make a second
array B of M elements. Copy the N values of A into the start of B, delete A,
and read the remaining M - N values straight into B. Print B.

Sample input
5
1 2 3 4 5
10
6 7 8 9 10

Sample output
1 2 3 4 5 6 7 8 9 10

*/

#include <iostream> // cin and cout
using namespace std; // write cin/cout instead of std::cin/std::cout

int main(){ // the program starts running here
    int n; // size of the first array A
    cin >> n; // cin skips spaces/newlines and reads one whole number

    // A is made with new because we need to delete it half way through the
    // program. A stack array such as `int a[n];` cannot be deleted - it stays
    // until main ends. That is the whole point of this question.
    // new int[n] gives n int boxes on the heap and returns the first box's address.
    int *a = new int[n];
    for(int i=0; i<n; i++){ // i = 0..n-1
        cin >> a[i]; // a[i] = box i of the heap array
    }

    int m; // the new, bigger size
    cin >> m; // the new, bigger size

    // No array can grow once it exists, so "growing" means: make a bigger one...
    int *b = new int[m];

    // ...copy the old values into its first n boxes...
    // Sample: b becomes 1 2 3 4 5 ? ? ? ? ?  (? = not filled yet)
    for(int i=0; i<n; i++){
        b[i] = a[i]; // copy box i of A into box i of B
    }

    // ...and give the old array back. From here on only b is used.
    // delete[] (with brackets) because a points to an array, not one int.
    // (a still holds the old address afterwards, but it must not be used any more.)
    delete[] a;

    // The boxes b[n] .. b[m-1] are still empty: read the rest of the values
    // into them. The loop starts at n, not at 0, so the copied values stay.
    // Sample: i = 5..9 reads 6 7 8 9 10 -> b = 1 2 3 4 5 6 7 8 9 10
    for(int i=n; i<m; i++){
        cin >> b[i];
    }

    // Print all m values of B, each followed by a space
    for(int i=0; i<m; i++){
        cout << b[i] << " ";
    }
    cout << endl; // finish the line

    delete[] b; // b is finished with too, so hand it back

    return 0; // the program ended fine
}
