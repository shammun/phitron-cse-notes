/*
 * Returning an object from a function.
 *
 * fun() builds a local Student object and returns it. This works fine:
 * `return karim;` hands back a COPY of the whole object (all its members),
 * and that copy is stored in obj in main. The original karim is destroyed when
 * fun() ends, but we no longer need it - we already have our own copy.
 *
 * Compare with why_we_need_dynamic_object.cpp: there fun() returns only the
 * ADDRESS of its local object, and that address points to a dead object.
 * Returning the object itself (by value) is safe; returning its address is not.
 *
 * Output: 254.95   (roll 2, cls 5 and gpa 4.95 printed with no spaces between them)
 */

#include <iostream> // Include the iostream library to enable input/output operations
#include <string.h> // Include string.h for character array operations (not used in this code)
using namespace std; // Use the standard namespace to simplify code (avoids prefixing 'std::')

// Define a class named 'Student' to encapsulate the properties of a student
class Student {
    public: // members and constructor usable from outside the class
    int roll; // Integer to store the student's roll number
    int cls; // Integer to store the student's class/grade level
    double gpa; // Double to store the student's GPA (Grade Point Average)

    // Constructor for the 'Student' class
    // A constructor is a special function that initializes object attributes when an object is created
    // (same name as the class, no return type, runs automatically).
    // Here, the constructor takes three parameters: roll, cls, and gpa
    Student(int roll, int cls, double gpa) {
        // 'this' is a pointer to the current object (it holds the object's address).
        // It differentiates between the constructor parameter 'roll' and the class attribute 'roll'.
        this->roll = roll; // Assign the parameter 'roll' to the class attribute 'roll'
        // We can also use the equivalent notation (*this).roll instead of 'this->roll'
        this->cls = cls;   // Assign the parameter 'cls' to the class attribute 'cls'
        // We can also use the equivalent notation (*this).cls instead of 'this->cls'
        this->gpa = gpa;   // Assign the parameter 'gpa' to the class attribute 'gpa'
        // We can also use the equivalent notation (*this).gpa instead of 'this->gpa'

        // Note: Instead of 'this->roll', we could also use the equivalent notation '(*this).roll'
        // (the brackets matter: the dot is applied before the star),
        // but 'this->' is more commonly used for clarity and simplicity.
    }
};

// A function whose return type is Student: it gives back a whole Student object.
Student fun(){
    Student karim(2, 5, 4.95); // Creates a local ("static" in the course's words) object on fun's stack memory
    // Why this works: the object is returned BY VALUE, i.e. all its members are copied
    // out to the caller before karim is destroyed at the end of fun().
    // A normal (stack) array cannot be returned from a function this way (C/C++ do not
    // allow an array as a return type; returning its name only returns an address that
    // dies with the function), but an object CAN be returned, because objects are copied
    // just like int or double values.
    // Note: karim is NOT like a C "static" variable (one declared with the static keyword,
    // which lives for the whole program). karim is an ordinary local variable; it is safe
    // only because a copy is returned.
    return karim; // hand a copy of karim (roll=2, cls=5, gpa=4.95) back to the caller
}

int main(){
    Student obj = fun(); // call fun(); the returned copy is stored in obj
    // No " " between the values, so they are printed stuck together: 2, 5, 4.95 -> "254.95"
    cout << obj.roll << obj.cls << obj.gpa << endl;
    return 0; // program finished normally
}