/*

Practice Day 02 (Module 7.5) - Question 2: reverse an array of students

Make a Student class with a name, a roll and marks. Read N, then N students
(name, roll, marks; names have no spaces) into an array of Student objects.
Reverse the array and print the students in their new order, one per line.

Sample input
5
Asif 29 95
Sakib 55 89
Zubair 57 93
Ahsan 39 86
Joy 12 99

Sample output
Joy 12 99
Ahsan 39 86
Zubair 57 93
Sakib 55 89
Asif 29 95

*/

#include <iostream>  // Include the input/output stream library for using cin and cout
#include <string>    // Include the string library for std::string
#include <algorithm> // Include the algorithm library for swap()
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

// One object holds the three facts about one student
class Student{
    public:
    string name; // no spaces, so cin >> is enough to read it
    int roll;
    int marks;
};

int main(){
    int n;
    cin >> n;

    Student a[n]; // an array of n Student objects, a[0] to a[n-1]
    for(int i=0; i<n; i++){
        // a[i] is one whole object; .name, .roll and .marks are its parts
        cin >> a[i].name >> a[i].roll >> a[i].marks;
    }

    // Reverse in place: swap the first object with the last, the second with
    // the second-last, and so on, stopping at the middle. Box i pairs with
    // box n-1-i. swap() works on whole objects too - all three members move
    // together, so a student's name, roll and marks never get separated.
    // With 5 students: swap a[0],a[4] and a[1],a[3]; a[2] (Zubair) stays put.
    for(int i=0; i<n/2; i++){
        swap(a[i], a[n-1-i]);
    }

    // Print the reversed array, one student per line
    for(int i=0; i<n; i++){
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }

    return 0; // Indicate that the program ended successfully
}
