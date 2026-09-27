/*
 * Why we need dynamic objects - the PROBLEM (this program is wrong on purpose).
 *
 * fun() creates a local object karim on its stack memory and returns karim's
 * ADDRESS. But a local object is destroyed the moment fun() returns, so main gets
 * an address that points to memory which no longer belongs to any object
 * (a "dangling pointer"). Reading through it is undefined behaviour: it may print
 * garbage, may print the right numbers by luck, or may crash.
 *
 * The fix is in why_we_need_dynamic_object_solve.cpp: create the object with
 * `new`, so it lives on the heap and survives after fun() returns.
 */

#include <iostream> // Include the iostream library for input/output operations
#include <string.h> // Include string.h for character array operations (not used in this code)
using namespace std; // Use the standard namespace to avoid prefixing 'std::'

// Define a class named 'Student' to encapsulate the properties of a student
class Student {
    public: // members and constructor usable from outside the class
    int roll; // Integer to store the student's roll number
    int cls;  // Integer to store the student's class/grade level
    double gpa; // Double to store the student's GPA (Grade Point Average)

    // Constructor for the 'Student' class
    // A constructor is a special function that initializes object attributes when an object is created
    // (same name as the class, no return type, runs automatically).
    Student(int roll, int cls, double gpa) {
        // 'this' = pointer to the object being built; this->roll is its member, plain roll is the parameter.
        this->roll = roll; // Assign the parameter 'roll' to the class attribute 'roll'
        this->cls = cls;   // Assign the parameter 'cls' to the class attribute 'cls'
        this->gpa = gpa;   // Assign the parameter 'gpa' to the class attribute 'gpa'

        // 'this->' is used to clearly distinguish between class attributes and function parameters
    }
};

// Function that returns a pointer to a 'Student' object
// Return type Student* = "the address of a Student", not a Student itself.
Student* fun() {
    Student karim(2, 5, 4.95); // Create a static (local, stack) object 'karim' inside the function

    // A pointer 'p' is initialized to store the address of 'karim'
    // &karim = "address of karim"; Student* p = a variable that can hold such an address.
    Student* p = &karim;

    // Return the pointer 'p' which points to 'karim'
    // NOTE: 'karim' is a local object and exists only while this function executes
    // BUG (intended, to show the problem): after this return karim is destroyed, so the
    // returned address is dangling. Fix: Student* p = new Student(2, 5, 4.95); instead.
    return p; // The pointer becomes invalid after the function exits
}

int main() {
    Student* p = fun(); // Call the function and store the returned pointer in 'p'

    // Attempt to access the attributes of the object pointed to by 'p'
    // p is a pointer, so members are reached with the arrow: p->roll means (*p).roll.
    // This is undefined behaviour because the object 'karim' no longer exists: it usually
    // prints garbage values (the stack memory has been reused), though by luck it may
    // sometimes still show 2 5 4.95. Either way the program is wrong.
    cout << p->roll << " " << p->cls << " " << p->gpa << endl;

    return 0; // Return 0 indicates successful program execution
}
