/*
Min and max in an array of objects
----------------------------------
Read n students (name, roll, marks; names have no spaces) into an array of
Student objects. Then find:
  1. the smallest marks value (just the number),
  2. the whole student object with the minimum marks,
  3. the whole student object with the maximum marks.

Sample input
3
Rahim 1 80
Karim 2 60
Salma 3 95

Expected output (once the BUG below is fixed)
Karim 2 60
Salma 3 95

NOTE: as written this file does NOT compile - see the "BUG" comment in main().
*/

#include <iostream> // Include the input/output stream library for using cin and cout
#include <string> // Include the string library for std::string (a text variable of any length)
#include <climits> // Include the climits library for INT_MAX and INT_MIN (largest/smallest int values)
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

// A class is a blueprint: every Student object will contain these three members
class Student{
    public: // members below can be used from outside the class (from main)
    string name; // student's name
    int roll; // roll number
    int marks; // marks obtained
}; // Define a class named Student (note the semicolon after the closing brace)

int main(){ // Program execution starts here
    // Name without space
    int n; // number of students
    cin >> n; // read n
    // An array of n Student objects: a[0] ... a[n-1], each box holds a whole student.
    // (Size from a variable is a g++ extension called a variable length array.)
    Student a[n];

    // Getting the minimum marks

    // Read the students: one pass fills box i. a[i].name means "the name member of object a[i]".
    for(int i=0; i<n; i++){
        cin >> a[i].name >> a[i].roll >> a[i].marks; // cin >> reads one word/number at a time
    }

    // Idea for a minimum: start with the biggest possible int (INT_MAX = 2147483647),
    // so that ANY real mark is smaller and replaces it on the first comparison.
    int min_marks = INT_MAX;
    // One pass compares the best-so-far with student i and keeps the smaller
    for(int i=0; i<n; i++){
        // BUG: a[i].name is a string, but min_marks is an int. min() needs two values of the
        // SAME type, so the compiler stops with "no matching function for call to min(int&, string&)".
        // Fix: compare the marks, not the name:  min_marks = min(min_marks, a[i].marks);
        min_marks = min(min_marks, a[i].name);
    }

    // Now, we want the object with the minimum marks
    // Instead of just the number, keep a copy of the WHOLE best object so we know its name and roll too.
    Student min_obj; // an object that will hold a copy of the weakest student
    min_obj.marks = INT_MAX; // start "infinitely high" so the first real student beats it

    // One pass: if student i has fewer marks than the best-so-far, remember student i
    for(int i=0; i<n; i++){
        if(a[i].marks < min_obj.marks){
            // "=" between two objects copies every member (name, roll and marks) at once
            min_obj = a[i];
        }
    }
    // With marks 80, 60, 95: 80 < INT_MAX -> Rahim; 60 < 80 -> Karim; 95 < 60? no. Result: Karim
    cout << min_obj.name << " " << min_obj.roll << " " << min_obj.marks << endl; // print the whole object

    // Now, we want the object with the maximum marks
    // Same idea, reversed: start at the smallest int (INT_MIN) so any real mark is bigger.
    Student max_obj; // will hold a copy of the top student
    max_obj.marks = INT_MIN; // -2147483648

    // One pass: if student i has more marks than the best-so-far, remember student i
    for(int i=0; i<n; i++){
        if(a[i].marks > max_obj.marks){
            max_obj = a[i]; // copy the whole object
        }
    }
    // With marks 80, 60, 95: Rahim -> (60 is not bigger) -> Salma. Result: Salma
    cout << max_obj.name << " " << max_obj.roll << " " << max_obj.marks << endl; // print the whole object

    return 0; // Indicate that the program ended successfully
}
