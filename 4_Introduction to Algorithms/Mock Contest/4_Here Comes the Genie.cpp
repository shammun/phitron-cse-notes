/*

Here Comes The Genie_

Problem Statement

Here comes the genie with  bags. The -th bag contains  balls of color . Your goal is to collect as many 
balls as possible. However, the genie has a condition: the number of balls you take from each color must 
be distinct. More formally, if you take  balls of color  where , then you cannot take  balls of another 
color .

For example, suppose n = 3 and a = [1, 2, 4].

You can take c = [1, 2, 3] or c = [1, 2, 4]. However, you cannot take c = [1, 2, 2] or c = [1, 1, 4], as 
these sets violate the condition of having distinct elements.

It's acceptable to take 0 balls from multiple bags. For instance, c = [0, 0, 1] or c = [1, 1, 4] are valid.

Now, you ask yourself: What is the maximum number of balls that you can collect?

Input Format

- First line contains n
- Next line contains the array a_1, a_2, a_3, ..., a_n

Constraints
1 <= n <= 2X10^5
1 <= a_i <= 10^9

Output Format
Output the maximum number of balls that you can collect.

Sample Input 0
4
1 1 2 1

Sample Output 0
3

Sample Input 1
3
1 4 5

Sample Output 1
10

Sample Input 2
4
5 1 1 4

Sample Output 2
10

*/

// Solution idea: sort, then be greedy.
// Sort the bags from biggest to smallest. The biggest bag may give everything
// it has. Each next bag must give a SMALLER amount than the bag before it
// (the amounts have to be different, and going down keeps them different), so
// it gives the smaller of "what it has" and "one less than the previous
// amount". Once the allowed amount reaches 0, every remaining bag gives 0,
// which is allowed.
// Why biggest first: a big bag can always afford a big amount, so letting it
// take the top value wastes nothing, and it leaves the smaller values free for
// the smaller bags.
//
// Example 1 4 5 -> sorted 5 4 1 -> take 5, then 4, then 1 -> 10.
// Example 1 1 2 1 -> sorted 2 1 1 1 -> take 2, 1, then 0, 0 -> 3.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    // greater<long long>() sorts from big to small.
    sort(a.begin(), a.end(), greater<long long>());

    // total can reach about 2*10^5 values of 10^9, far beyond int: long long.
    long long total = 0;
    long long allowed = a[0];   // the most the current bag may give

    for(int i = 0; i < n; i++){
        // Give as much as the bag has, but never more than allowed.
        long long take = min(a[i], allowed);
        total += take;

        // The value `take` is now used, so the next bag must give less.
        // 0 is the floor: many bags may give 0 together.
        allowed = max(take - 1, 0LL);
    }

    cout << total << endl;

    // Sorting dominates: O(n log n).
    return 0;
}
