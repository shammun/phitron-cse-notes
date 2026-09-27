/*
 * Why we need dynamic objects - the SOLUTION.
 *
 * In why_we_need_dynamic_object.cpp, fun() returned the address of a local object
 * that died when fun() ended. Here fun() creates the object with `new`:
 *   - `new Student(2, 5, 4.95)` reserves memory for one Student on the HEAP,
 *     runs the constructor to fill it, and returns the address of that memory.
 *   - Heap memory is NOT freed when a function ends. It stays until we call
 *     `delete` on its address. So the address fun() returns is still valid in main.
 *
 * Output: 2 5 4.95
 */

#include <iostream> // Include the iostream library for input/output operations
#include <string.h> // Include string.h for operations on character arrays (not used in this code)
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before cin, cout, etc.

// Define a class named 'Student' to encapsulate the properties of a student
class Student {
    public: // members and constructor usable from outside the class
    int roll; // Integer to store the student's roll number
    int cls;  // Integer to store the student's class/grade level
    double gpa; // Double to store the student's GPA (Grade Point Average)

    // Constructor for the 'Student' class
    // A constructor is a special function that initializes object attributes when an object is created
    // (same name as the class, no return type, runs automatically - also when the object is made with new).
    Student(int roll, int cls, double gpa) {
        // 'this' = pointer to the object being built; this->roll is its member, plain roll is the parameter.
        this->roll = roll; // Assign the parameter 'roll' to the class attribute 'roll'
        this->cls = cls;   // Assign the parameter 'cls' to the class attribute 'cls'
        this->gpa = gpa;   // Assign the parameter 'gpa' to the class attribute 'gpa'

        // 'this->' is used to clearly distinguish between class attributes and function parameters
    }
};

// Function that dynamically creates and returns a pointer to a 'Student' object
// Return type Student* = the address of a Student.
Student* fun() {
    // Dynamically allocate memory for the 'Student' object on the heap
    // karim itself is a small local pointer variable (it dies when fun ends), but the
    // OBJECT it points to is on the heap and keeps living.
    Student* karim = new Student(2, 5, 4.95);

    // Return the pointer to the dynamically allocated object
    // Only the address is copied back to main; the heap object stays where it is.
    return karim;
}

int main() {
    // Call the 'fun' function and store the returned pointer in 'p'
    // 'p' points to a dynamically allocated object created in the 'fun' function
    Student* p = fun();

    // Access and print the attributes of the dynamically allocated object using the arrow operator (->)
    // The arrow operator is used because 'p' is a pointer to the object
    // p->roll is short for (*p).roll: go to the object at address p, take its roll.
    cout << p->roll << " " << p->cls << " " << p->gpa << endl; // 2 5 4.95

    // Free the dynamically allocated memory to prevent memory leaks
    // delete destroys the heap object and gives its memory back. After this, p must not be used.
    delete p;

    return 0; // Return 0 indicates successful program execution
}
