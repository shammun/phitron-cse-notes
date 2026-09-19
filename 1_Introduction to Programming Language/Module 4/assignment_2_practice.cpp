// Prefix sums, printed in reverse.
//
// A re-typing of assignment_2_get_prefix_sum.cpp, with the same logic. The
// problem statement and the samples are at the top of that file; typing the
// solution out again from memory is the point of this one.
//
// The assignments in this module are the first C++ in the course, so the few
// new words are worth a line each:
//
//   #include <iostream>    cin and cout, C++'s reading and printing
//   #include <vector>      the vector type used below
//   using namespace std;   lets you write cout, cin and vector instead of
//                          std::cout, std::cin and std::vector
//   (<algorithm> and <string> are included out of habit; this file does not
//   use anything from them.)
//
//   cin >> n;              reads one value into n. No & and no "%d": cin
//                          works out the type from the variable itself.
//   cout << x << " ";      prints x and then a space; << chains left to
//                          right.
//
//   vector<long long> nums(n);   n boxes of type long long, all set to 0.
//   A vector is C's array with the awkward parts removed: its size can be
//   decided while the program runs, and it knows how big it is. Indexing is
//   the same, nums[0] to nums[n-1].
//
// The idea of the program: a prefix sum array, where runningSum[i] holds the
// total of everything from nums[0] up to nums[i]. Each entry is the previous
// entry plus one more number, so the whole thing is built in a single pass
// instead of re-adding from the start for every index.
//
// Why long long and not int: A[i] can be 10^9 and there can be 10^5 of them,
// so the last prefix sum can reach 10^14. An int stops at about 2.1 * 10^9
// and would wrap round into a negative number. The input used on the site -
// 1000000000 three times - already prints 3000000000, which an int could not
// hold.

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    // runningSum[i] = nums[0] + nums[1] + ... + nums[i]
    vector<long long>runningSum(n);
    // The first entry has nothing before it, so it is just the first number.
    // It must be set separately: the loop below reads runningSum[i-1], and
    // starting that loop at i = 0 would reach runningSum[-1], outside the
    // vector.
    runningSum[0] = nums[0];

    // One addition per element: the previous total plus the next number.
    for(int i=1; i<n; i++){
        runningSum[i] = runningSum[i-1] + nums[i];
    }

    // The task asks for the prefix sums printed backwards, so walk from the
    // last index n-1 down to 0. The condition is i >= 0, not i > 0, or the
    // first element would be left out.
    for(int i=n-1; i>=0; i--){
        cout << runningSum[i] << " ";
    }

    // Ends the line (and flushes the output).
    cout << endl;

    return 0;

}