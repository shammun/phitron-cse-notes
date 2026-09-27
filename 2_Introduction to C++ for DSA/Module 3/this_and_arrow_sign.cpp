/*
 * `this` and the arrow sign (->).
 *
 * Sometimes we want the constructor's parameters to have the SAME names as the
 * members (roll, cls, gpa) because they are the most natural names. Then inside
 * the constructor, "roll" alone means the PARAMETER (the nearest name wins), and
 * roll = roll; would just copy the parameter into itself - the member stays garbage.
 *
 * `this` solves it. Inside any member function (a constructor is one), C++ gives us
 * a hidden pointer called `this` that holds the address of the object the function
 * is working on. When `Student rahim(45, 8, 3.3);` runs, `this` points at rahim;
 * when `Student karim(1, 8, 5.0);` runs, `this` points at karim.
 *
 * Because `this` is a POINTER, we reach members through it with the arrow ->.
 *   this->roll   means   (*this).roll   means "the roll member of the current object".
 *
 * Output:
 *   1 8 5
 *   45 8 3.3
 */

#include <iostream> // Include the iostream library to enable input/output operations
#include <string.h> // Include string.h for character array operations (not used in this code)
using namespace std; // Use the standard namespace to simplify code (avoids prefixing 'std::')

// Define a class named 'Student' to encapsulate the properties of a student
class Student {
    public: // members and constructor usable from main
    int roll; // Integer to store the student's roll number
    int cls; // Integer to store the student's class/grade level
    double gpa; // Double to store the student's GPA (Grade Point Average)

    // Constructor for the 'Student' class
    // A constructor is a special function that initializes object attributes when an object is created
    // (same name as the class, no return type, called automatically).
    // Here, the constructor takes three parameters: roll, cls, and gpa
    Student(int roll, int cls, double gpa) {
        // 'this->' is a pointer to the current object.
        // It differentiates between the constructor parameter 'roll' and the class attribute 'roll'.
        // Left side  this->roll = the object's member; right side roll = the parameter.
        this->roll = roll; // Assign the parameter 'roll' to the class attribute 'roll'
        // We can also use the equivalent notation (*this).roll instead of 'this->roll'
        this->cls = cls;   // Assign the parameter 'cls' to the class attribute 'cls'
        // We can also use the equivalent notation (*this).cls instead of 'this->cls'
        this->gpa = gpa;   // Assign the parameter 'gpa' to the class attribute 'gpa'
        // We can also use the equivalent notation (*this).gpa instead of 'this->gpa'

        // Note: Instead of 'this->roll', we could also use the equivalent notation '(*this).roll'.
        // The brackets are required: *this.roll would be read as *(this.roll), which does not compile,
        // because the dot binds tighter than the star. That is exactly why the shorter -> exists.
        // 'this->' is more commonly used for clarity and simplicity.
    }
};

int main() {
    // Create an object of the 'Student' class named 'rahim' with roll=45, cls=8, and gpa=3.3
    // While this constructor call runs, 'this' holds the address of rahim.
    Student rahim(45, 8, 3.3);

    // Create another object of the 'Student' class named 'karim' with roll=1, cls=8, and gpa=5.0
    // Now 'this' holds the address of karim, so karim's own members get filled.
    Student karim(1, 8, 5.0);

    // Output the details of 'karim' using 'cout'
    // 'cout' prints the values in a readable format with fields separated by spaces
    // rahim and karim are normal objects (not pointers), so main uses the dot, not the arrow.
    cout << karim.roll << " " << karim.cls << " " << karim.gpa << endl; // 1 8 5 (5.0 prints as 5)

    // Output the details of 'rahim' using 'cout'
    cout << rahim.roll << " " << rahim.cls << " " << rahim.gpa << endl; // 45 8 3.3

    // Return 0 indicates that the program executed successfully
    return 0;
}
