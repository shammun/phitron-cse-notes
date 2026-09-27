/*
There will be N number of students in the class.
Please sort the array of objects according to the marks. If there are same marks for some students,
then sort them according to the roll number.

This file shows several ways to write the comparator function that sort() needs.
NOTE: as written it does NOT compile (two functions named dsc - see the BUG below),
and main() never actually calls sort(). See the notes in main() for how to finish it.

Sample input
4
Rakib 3 76
Sakib 2 80
Maruf 1 80
Nakib 4 60
Sorted with dsc2 (marks high -> low, tie: roll low -> high) it would print
Maruf 1 80
Sakib 2 80
Rakib 3 76
Nakib 4 60
*/

#include <iostream> // Include the input/output stream library for using cin and cout
#include <string> // Include the string library for std::string
#include <climits> // Include the climits library for INT_MAX and INT_MIN (not used in this file)
#include <algorithm> // Include the algorithm library for sort function
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

// A class is a blueprint: every Student object bundles a name, a roll and marks
class Student{
    public: // members can be used from outside the class
    string name; // student's name (no spaces)
    int roll; // roll number
    int marks; // marks obtained
}; // Define a class named Student

// A comparator is a function sort() calls with two elements (l = left, r = right).
// It must return true exactly when l should come BEFORE r in the final order.

// Comparator function to sort students in descending order based on marks
// (and, when marks are equal, in ascending order of roll). Written out case by case:
bool dsc(Student l, Student r){
    if(l.marks > r.marks){ // l has more marks -> l goes first
        return true;
    } else if(l.marks < r.marks){ // l has fewer marks -> l goes after r
        return false;
    } else{ // same marks -> the smaller roll goes first
        return l.roll < r.roll;
    }
}

// Shorter way to write the above function (same result, not faster):
// handle the tie first, otherwise compare marks.
bool dsc2(Student l, Student r){
    if(l.marks == r.marks){ // tie on marks
        return l.roll < r.roll; // smaller roll first
    } else{
        return l.marks > r.marks; // bigger marks first
    }
}

// Shortest version, using the ternary operator:  condition ? value_if_true : value_if_false
// It is only shorter to write; the speed is the same as dsc and dsc2.
bool dsc3(Student l, Student r){
    return (l.marks == r.marks) ? l.roll < r.roll : l.marks > r.marks; // tie -> roll ascending, else marks descending
}

// Comparator function to sort students in ascending order based on marks
// (and, when marks are equal, in DESCENDING order of roll: l.roll > r.roll).
// BUG: this function has the same name and the same parameters as the first dsc above.
// C++ does not allow two identical functions, so compilation fails with
// "redefinition of 'bool dsc(Student, Student)'". Fix: give it another name, e.g. asc.
bool dsc(Student l, Student r){
    if(l.marks < r.marks){ // fewer marks first
        return true;
    } else if(l.marks > r.marks){
        return false;
    } else{ // same marks -> bigger roll first
        return l.roll > r.roll;
    }
}

int main(){ // Program execution starts here
    // Name without space
    int n; // number of students
    cin >> n; // read n
    Student a[n]; // array of n Student objects (variable size: a g++ extension)

    // One pass reads one student into box i
    for(int i=0; i<n; i++){
        cin >> a[i].name >> a[i].roll >> a[i].marks; // cin >> reads one word/number at a time
    }

    // Note: sort() is never called, so the students print in the order they were typed.
    // To actually sort, add before this loop:  sort(a, a+n, dsc2);
    // (a = start of the array, a+n = one past the end, dsc2 = which comparator to use)
    for(int i=0; i<n; i++){
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl; // print one student per line
    }

    return 0; // Indicate that the program ended successfully
}
