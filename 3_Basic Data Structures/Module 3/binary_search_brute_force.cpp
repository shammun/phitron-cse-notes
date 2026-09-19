/*

Codeforces group - Z. Binary Search

Given an array of n numbers and q questions, answer each question "is this value in
the array?" with "found" or "not found".

This file is the honest first answer: look at every element, every time. The file next
to it (binary_search_efficient.cpp) solves the same problem the fast way. Read the two
together - the point of the lesson is the difference between them.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // n = how many numbers are in the array, q = how many questions follow.
    int n, q;
    cin >> n >> q;

    // `int a[n]` with n read at run time is a variable-length array. It is a GCC
    // extension, not standard C++, but it works on the judge and keeps this file short.
    // The numbers may arrive in any order; a linear scan does not care.
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    // One pass of this loop = one question answered.
    for(int i=0; i<q; i++){
        int x;
        cin >> x;

        // flag is the answer to "did I ever see x?". It starts at 0 (no) and is reset
        // for every new query - forgetting to reset it would make every query after the
        // first successful one say "found".
        int flag = 0;

        // Linear search: walk the whole array and compare each box with x.
        for(int j=0; j<n; j++){
            if(a[j] == x){
                flag = 1;
                // break leaves this inner loop only, not the query loop above, which is
                // exactly what is wanted: stop scanning, then go on to the next query.
                // Without it the scan would keep running to the end for nothing.
                break;
            }
        }
        if(flag == 1){
            cout << "found" << endl;
        }
        else{
            cout << "not found" << endl;
        }
    }

    // What this costs. The inner scan is up to n comparisons, and it runs once per
    // query, so the whole program is about n * q comparisons: O(n*q).
    // With the sample (n = 5, q = 3) that is 15 - nothing. On the real judge n and q
    // both go up to 10^5, so n * q is 10^10 comparisons. A judge does roughly 10^8 per
    // second, so this needs minutes and gets Time Limit Exceeded.
    //
    // Notice where the waste is: the array never changes between queries, yet every
    // query starts reading it from index 0 again, learning nothing from the last one.
    // Sorting the array once turns the order into information every query can use, and
    // that is what binary_search_efficient.cpp does.

    return 0;
}