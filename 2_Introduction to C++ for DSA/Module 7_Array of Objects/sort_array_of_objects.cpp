/*
There will be N number of students in the class.
Please sort the array of objects according to the marks. So, the student with the highest
marks will be in the first index, and student with the lowest marks will be the the last index of the array.

The program sorts twice: first descending (highest marks first), then ascending
(lowest marks first), printing the array after each sort.
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

// sort() knows how to compare ints, but not two Student objects. So we give it a
// comparator: a function that receives two students (l = left, r = right) and
// returns true when l must come BEFORE r in the sorted order.

// Comparator function to sort students in descending order based on marks
// l goes first when it has MORE marks. e.g. l = 99, r = 80 -> true -> 99 is placed first.
bool dsc(Student l, Student r){
    return l.marks > r.marks;
}

// Comparator function to sort students in ascending order based on marks
// l goes first when it has FEWER marks.
bool asc(Student l, Student r){
    return l.marks < r.marks;
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

    // Descending order
    // sort(start, end, comparator): a = first box, a+n = one past the last box, so all n are sorted.
    // We pass the comparator's NAME (no brackets); sort() calls it again and again while sorting.
    sort(a, a+n, dsc);

    // Print after the descending sort: Maruf 99, Sakib 80, Rakib 76, Nakib 60, Nakib 50, Ropon 45
    for(int i=0; i<n; i++){
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }

    // Ascending order
    sort(a, a+n, asc); // same array, now lowest marks first
    // Print after the ascending sort: Ropon 45, Nakib 50, Nakib 60, Rakib 76, Sakib 80, Maruf 99
    for(int i=0; i<n; i++){
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }

    return 0; // Indicate that the program ended successfully
}

/*

Input:
6
Rakib 3 76
Sakib 2 80
Maruf 1 99
Nakib 4 60
Nakib 5 50
Ropon 6 45
*/
