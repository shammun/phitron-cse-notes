/*

Problem Statement

You will be given data for N students, where each student will have a name (nm), class (cls), section (s), student ID (id), math marks (math_marks), and English marks (eng_marks).

Your task is to sort the students data according to the total marks (sum of math_marks and eng_marks) in descending order. If multiple student have the same total marks then sort them according to the id in ascending order as the id will be unique.

Input Format

First line will contain N.
Next N lines will contain nm, cls, s, id, math_marks and eng_marks respectively.
Constraints

1 <= N <= 100
1 <= |nm| <= 100 and will contain only English alphabets.
1 <= cls <= 10
'A' <= s <= 'Z'
1 <= id <= 1000
0 <= math_marks, eng_marks <= 100
Output Format

Output the students data in descending order according to the total marks.

Example (made up)
Input
3
rahim 5 A 3 50 40
karim 6 B 1 45 45
jodu 7 C 2 99 10
Output
jodu 7 C 2 99 10
karim 6 B 1 45 45
rahim 5 A 3 50 40
(totals: jodu 109; karim and rahim both 90 -> smaller id 1 (karim) first)

*/

#include <iostream> // Include the input/output stream library for using cin and cout
#include <string> // Include the string library for std::string
#include <climits> // Include the climits library for INT_MAX and INT_MIN (not used in this file)
#include <algorithm> // Include the algorithm library for sort function
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

// A class is a blueprint: every Student object bundles these six members.
// "public:" lets main() and dsc() read them directly with the dot, e.g. a[i].id
class Student{
    public:
    string nm; // name (letters only, no spaces)
    int cls; // class
    char s; // section letter, one character
    int id; // unique id
    int math_marks; // math marks
    int eng_marks; // English marks
}; // Define a class named Student

// Comparator for sort(): true when student l must come BEFORE student r.
// First key: total marks (math + English), bigger first.
// Tie on the total: smaller id first.
bool dsc(Student l, Student r){
    if(l.math_marks + l.eng_marks > r.math_marks + r.eng_marks){ // l has the bigger total
        return true; // l first
    } else if(l.math_marks + l.eng_marks < r.math_marks + r.eng_marks){ // r has the bigger total
        return false; // r first
    } else{ // same total
        return l.id < r.id; // smaller id first
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
