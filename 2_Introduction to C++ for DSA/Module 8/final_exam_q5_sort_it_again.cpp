/*

Problem Statement

You will be given data for N students, where each student will have a name (nm), class (cls), section (s), student ID (id), math marks (math_marks), and English marks (eng_marks).

Your task is to sort the students data according to the eng_marks in descending order. If multiple student have the same eng_marks then sort them according to the math_marks in
descending order. If multiple student have the same math_marks then sort them accoding to the id in ascending order as the id will be unique.

Input Format

First line will contain N.
Next N lines will contain nm, cls, s, id, math_marks and eng_marks respectively.
Constraints

1 <= N <= 1000
1 <= |nm| <= 100 and will contain only English alphabets.
1 <= cls <= 10
'A' <= s <= 'Z'
1 <= id <= 10^9
0 <= math_marks, eng_marks <= 100
Output Format

Output the data in sorted order as instructed.
Sample Input 0

6
akib 2 R 1001 32 53
rakib 1 E 1002 93 97
sakib 8 M 1003 34 88
bokib 3 Q 1004 93 58
jessica 4 F 1005 94 88
noname 8 R 1006 17 61
Sample Output 0

rakib 1 E 1002 93 97
jessica 4 F 1005 94 88
sakib 8 M 1003 34 88
noname 8 R 1006 17 61
bokib 3 Q 1004 93 58
akib 2 R 1001 32 53
Sample Input 1

6
akib 2 R 1001 32 53
rakib 1 E 1002 94 88
sakib 8 M 1003 34 88
bokib 3 Q 1004 93 58
jessica 4 F 1005 94 88
noname 8 R 1006 17 61
Sample Output 1

rakib 1 E 1002 94 88
jessica 4 F 1005 94 88
sakib 8 M 1003 34 88
noname 8 R 1006 17 61
bokib 3 Q 1004 93 58
akib 2 R 1001 32 53

*/

#include <iostream> // Include the input/output stream library for using cin and cout
#include <string> // Include the string library for std::string
#include <climits> // Include the climits library for INT_MAX and INT_MIN (not used in this file)
#include <algorithm> // Include the algorithm library for sort function
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

// A class is a blueprint: every Student object bundles these six members.
// "public:" lets main() and dsc() read them directly with the dot, e.g. a[i].eng_marks
class Student{
    public:
    string nm; // name (letters only, no spaces)
    int cls; // class
    char s; // section letter, one character
    int id; // unique id; up to 10^9 still fits in an int (int max is about 2.1 * 10^9)
    int math_marks; // math marks
    int eng_marks; // English marks
}; // Define a class named Student

// Comparator for sort(): true when student l must come BEFORE student r.
// Three keys, checked in order - a later key only matters when every
// earlier one is tied:
//   1. English marks, bigger first
//   2. math marks, bigger first
//   3. id, smaller first (ids are unique, so this always decides)
// Sample 1: rakib (94, 88) and jessica (94, 88) tie on both marks -> id 1002 < 1005 -> rakib first.
bool dsc(Student l, Student r){
    if(l.eng_marks > r.eng_marks){ // key 1 decides: l has more English marks
        return true;
    } else if(l.eng_marks < r.eng_marks){ // key 1 decides: r has more
        return false;
    } else{ // English tied -> look at math
        if(l.math_marks > r.math_marks){ // key 2 decides: l has more math marks
            return true;
        } else if(l.math_marks < r.math_marks){ // key 2 decides: r has more
            return false;
        } else{ // both tied -> key 3
            return l.id < r.id; // smaller id first
        }
    }
}

int main(){ // Program execution starts here
    int n; // number of students
    cin >> n; // read n

    Student a[n]; // an array of n Student objects (size from a variable: a g++ extension)
    // One pass reads all six fields of one student; cin >> skips the spaces between them
    for(int i=0; i<n; i++){
        cin >> a[i].nm >> a[i].cls >> a[i].s >> a[i].id >> a[i].math_marks >> a[i].eng_marks;
    }

    // a = first box, a+n = one past the last box, so the whole array is sorted
    sort(a, a+n, dsc); // sort() asks dsc() which of two students goes first

    // Print the sorted students, all six fields on one line each
    for(int i=0; i<n; i++){
        cout << a[i].nm << " " << a[i].cls << " " << a[i].s << " " << a[i].id << " " << a[i].math_marks << " " << a[i].eng_marks << endl;
    }

    return 0; // the program ended successfully
}
