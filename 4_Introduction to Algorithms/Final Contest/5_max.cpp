/*

Max

Problem Statament

You are given an empty array initially. Then, you will be given Q queries to perform on this array. You will 
be given 2 types of queries to perform.

- 1 X - add  to the array.
- 2 - If the array is empty print empty otherwise print the element which occurrence is maximum , if there 
exist multiple element with maximum occurrence print the largest value which occurrence is maximum and erase 
max (1, ⌊total occurrences of that element / 2⌋) occurrences of that value.

Here, ⌊x⌋ represents the largest integer less than or equal to a given number x. For example : ⌊5/2⌋ = ⌊2.5⌋ = 2

It is guaranteed that at least one type 2 query will be present in all the test case.

Note: The input file is too large. Must use fast I/O and don't use endl. Use "\n" instead of endl.

Fast I/O: Add these 2 lines at the first of main function -

ios::sync_with_stdio(false);
cin.tie(nullptr);

Input Format

- The first line contains a single positive integer Q.
- The next Q lines will contains the queries.

Constraints
- 1 <= Q <= 10^5
- 1 <= X <= 10^9


Output Format
If the query type is 2 print the desired output as written in the problem statement. Dont' forget to print a 
newline after each test case.

Sample Input 0
12
2
1 12
1 10
1 12
1 12
1 10
1 12
1 10
1 10
2
1 15
2

Sample Output 0
empty
12
10

Explanation 0
During the first 2 type of query, the array is empty so you must print empty. For the next 2 type of query, 
10 appears 4 times and 12 also appears 4 times. Since their occurrences are the same you must print 12 because 
it is greater than 10. After printing 12, remove ⌊4/2⌋ = 2 means erase 2 occurrences of 12.

*/

// Solution idea: two containers from the Basic Data Structures course.
//   * map<int,int> cnt   : how many times each value is in the array now.
//   * set<pair<int,int>> : one pair {count, value} for every value present.
// A set keeps its pairs sorted, first by count, then by value. So its LAST
// pair is the value with the highest count, and among equal counts the
// largest value - exactly the one query 2 asks for, found in O(log n).
// Whenever a count changes, the old pair is erased and the new pair inserted,
// so the set always agrees with the map.

#include <iostream>     // cin, cout
#include <map>          // map
#include <set>          // set

using namespace std;    // no std:: prefix

int main(){
    // The input is large: fast I/O, and "\n" instead of endl.
    // sync_with_stdio(false) stops cin/cout from keeping in step with
    // scanf/printf (much faster); cin.tie(nullptr) stops cin from flushing
    // cout before every read.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;                      // number of queries
    cin >> Q;

    map<int, int> cnt;          // cnt[x] = occurrences of x in the array
    set<pair<int, int>> order;  // {cnt[x], x} for every x with cnt[x] > 0

    while(Q--){                 // handle one query per pass
        int type;               // 1 = add, 2 = report and remove
        cin >> type;

        if(type == 1){
            int x;              // the value to add
            cin >> x;
            // x's count goes up by one: take out its old pair (if it had one)
            // and put in the new one.
            // (cnt[x] on a missing key creates it with value 0.)
            if(cnt[x] > 0){
                order.erase({cnt[x], x});
            }
            cnt[x]++;
            order.insert({cnt[x], x});
        }
        else{
            if(order.empty()){              // nothing in the array
                cout << "empty" << "\n";
                continue;                   // go straight to the next query
            }

            // prev(order.end()) is the last, i.e. biggest, pair.
            // (end() points one PAST the last element; prev steps back one.)
            // In the sample: {4, 10} and {4, 12} tie on count, and {4, 12}
            // comes later because 12 > 10, so 12 is printed.
            pair<int, int> top = *prev(order.end());   // * reads the element
            int c = top.first;      // its count
            int x = top.second;     // its value
            cout << x << "\n";

            // Remove max(1, c / 2) copies: with 4 copies, 2 go; with 1 copy,
            // 1 goes (c / 2 would be 0, hence the max with 1).
            int remove = max(1, c / 2);
            order.erase(top);       // old pair out
            cnt[x] -= remove;
            // Put x back only if some copies are left; a value with count 0
            // is no longer in the array.
            if(cnt[x] > 0){
                order.insert({cnt[x], x});
            }
            else{
                cnt.erase(x);       // forget x entirely
            }
        }
    }

    // Each query does a constant number of map/set operations: O(log n) each.
    return 0;
}
