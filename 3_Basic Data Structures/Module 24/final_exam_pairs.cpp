/*

Pairs

Problem Statement

You will be given a list  of type pairs. Each pair will contain one string S and
one unique integer I. The string will contain only English lowercase alphabets and
no spaces.

You need to sort the pairs according to the string values in ascending order. If
there are multiple pairs with the same string, you need to sort them according to
the integer value in descending order.

Input Format
- First line will contain N, the size of the list A.
- Next N lines will contain pairs of string S and integer I.

Constraints
1. 1 < N <= 10^5
2. 1 <= |S| <= 10^5
3. -10^9 <= I <= 10^9

Output Format
- Output the final list after sorting according to the question.

Sample Input 0
5
sakib 1
rakib 2
tasfia 3
asfia 4
afia 5

Sample Output 0
afia 5
asfia 4
rakib 2
sakib 1
tasfia 3

Sample Input 1
6
sakib 5
rakib 3
tasfia 2
sakib 6
afia 1
sakib 4

Sample Output 1
afia 1
rakib 3
sakib 6
sakib 5
sakib 4
tasfia 2

*/

// A re-typed copy of final_exam_question_2_Pairs.cpp (same logic, plus return 0).


#include <bits/stdc++.h>    // GCC shortcut: includes the whole standard library (string, queue, vector, ...)

using namespace std;        // write string, priority_queue, cout ... without std::



/*
 * Idea: a priority queue with our own compare class (custom_compare_class.cpp
 * in Module 23). Push every pair, then pop them one by one; the compare
 * class decides which pair comes out first:
 *   - smaller name first (ascending by name);
 *   - for the same name, bigger number first (descending by number).
 *
 * How to read cmp: operator()(l, r) returns true when l should come out
 * AFTER r (l has lower priority). So:
 *   l.name > r.name  -> true : the bigger name waits, smaller names go first.
 *   l.val  < r.val   -> true : on a name tie, the smaller number waits.
 *
 * Strings compare with < and > in dictionary (alphabetical) order:
 * "afia" < "asfia" because at the second letter 'f' < 's'.
 * Cost: N pushes and N pops, O(log N) each -> O(N log N).
 */

// One (name, number) item of the list.
class Pair{
    public:                 // usable from outside the class
        string name;        // the string S
        int val;            // the integer I

        // Constructor: `Pair obj(name, val);` runs this.
        // this->name is the member; plain name is the parameter.
        Pair(string name, int val){
            this->name = name;
            this->val = val;
        }
};


// The compare class: the priority queue calls cmp()(l, r) whenever it needs
// to know which of two pairs has LOWER priority. (A class with operator()
// can be called like a function.) l and r are taken by reference (&), so
// the pairs are not copied for every comparison.
class cmp{
    public:
        bool operator()(Pair &l, Pair &r){
            // Different names: the alphabetically bigger one comes out later.
            if(l.name > r.name){
                return true;
            } else if(l.name < r.name){
                return false;
            } else {
                // Same name: the smaller number comes out later, so the
                // bigger number is printed first.
                return l.val < r.val;
            }
        }
};

int main(){
    // priority_queue<type, container that stores it, compare class>
    priority_queue<Pair, vector<Pair>, cmp> pq;
    int N;
    cin >> N;               // size of the list

    // Read every pair and push it; the heap keeps the "first to print" on top.
    for(int i=0; i<N; i++){
        string name;
        int val;
        cin >> name >> val;         // e.g. "sakib 5"
        Pair obj(name, val);        // build the Pair with the constructor
        pq.push(obj);               // a copy goes into the heap, O(log N)
    }

    // Print the top and remove it, until nothing is left: that prints the
    // whole list in the required order.
    while(!pq.empty()){
        cout << pq.top().name << " " << pq.top().val << endl;
        pq.pop();                   // remove the pair just printed
    }

    return 0;               // program finished normally
}
