/*
 * Constructor.
 *
 * A CONSTRUCTOR is a special function inside a class that runs AUTOMATICALLY
 * every time an object of that class is created. We use it to fill the
 * object's members in one line, instead of writing obj.roll = ...; obj.cls = ...;
 * one by one.
 *
 * How to recognise a constructor:
 *   - it has exactly the same name as the class (Student),
 *   - it has NO return type (not even void),
 *   - the values in brackets when creating an object, Student rahim(21, 7, 3.8),
 *     are passed to its parameters.
 *
 * Sample input: 5 9 4.2
 * Sample output:
 *   21 7 3.8
 *   5 9 4.2
 */

#include <iostream> // Include the iostream library for input/output operations (cin, cout)
#include <string.h> // Include string.h for operations on character arrays (not used in this example but generally for strings)
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before cin, cout, etc.

// Define a class named 'Student' to represent a student's information
class Student {
    public: // members and the constructor can be used from outside the class (main)
    int roll; // Integer to store the roll number of the student
    int cls; // Integer to store the class/grade of the student ("class" itself is a C++ keyword, so the member is named cls)
    double gpa; // Double to store the GPA (Grade Point Average) of the student

    // Constructor for the 'Student' class to initialize the attributes
    // Same name as the class, no return type. r, c, g are ordinary parameters
    // that receive the three values written in brackets when an object is created.
    // The constructor must be public too, otherwise main could not create objects with it.
    Student(int r, int c, double g) {
        roll = r; // Initialize the 'roll' attribute with the value passed in 'r'
        cls = c;  // Initialize the 'cls' attribute with the value passed in 'c'
        gpa = g;  // Initialize the 'gpa' attribute with the value passed in 'g'
        // Inside the class, plain "roll" means THIS object's roll member.
    }
};

int main() {
    // Create an instance of the Student class named 'rahim' and initialize it using the constructor
    // This calls Student(21, 7, 3.8): r=21, c=7, g=3.8 are copied into rahim's members.
    // Note: since the class now has a constructor with 3 parameters, "Student x;" with no
    // values would NOT compile any more - every object must be given the 3 values.
    Student rahim(21, 7, 3.8); // 'rahim' has roll=21, cls=7, gpa=3.8

    // Output the details of 'rahim' using 'cout'
    // 'cout' is used here to display the values of the object's attributes
    // The attributes are separated by spaces for readability
    cout << rahim.roll << " " << rahim.cls << " " << rahim.gpa << endl; // prints: 21 7 3.8

    // Variables to store user input for a new student
    int r; // To store roll number
    int c; // To store class/grade
    double g; // To store GPA

    // Read input from the user using 'cin'
    // 'cin' reads multiple values separated by spaces or newlines
    // It is suitable for this scenario where the input values are simple tokens
    cin >> r >> c >> g; // input "5 9 4.2" -> r=5, c=9, g=4.2

    // Create another instance of the Student class named 'karim' using the user input
    // The constructor runs again, this time with the values the user typed.
    Student karim(r, c, g);

    // Output the details of 'karim' using 'cout'
    cout << karim.roll << " " << karim.cls << " " << karim.gpa << endl; // prints: 5 9 4.2

    return 0; // Return 0 indicates successful program execution
}
