/*
 * Static (normal) object vs dynamic object.
 *
 * "Static" object (the course's word; C++ books call it an automatic or local object):
 *     Student rahim(45, 8, 3.3);
 *   lives on the STACK, inside main's own memory. It is destroyed automatically
 *   when the function it was made in ends. Members are reached with a dot: rahim.roll
 *
 * Dynamic object:
 *     Student* karim = new Student(1, 8, 5.0);
 *   `new` builds the object on the HEAP (a separate, long-lived memory area), runs its
 *   constructor, and gives back the object's ADDRESS. karim is a POINTER that stores
 *   that address. The object stays alive until we destroy it with `delete karim;`,
 *   even after the function that made it returns.
 *   Members are reached with the arrow: karim->roll
 *   (karim->roll is short for (*karim).roll: "go to the object karim points at, take its roll").
 *
 * Output:
 *   45 8 3.3
 *   1 8 5
 */

#include <iostream> // Include the iostream library for input/output operations
#include <string.h> // Include string.h for operations on character arrays (not used in this code)
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before cin, cout, etc.

// Define a class named 'Student' to encapsulate the properties of a student
class Student {
    public: // everything below can be used from main
    int roll; // Integer to store the student's roll number
    int cls;  // Integer to store the student's class/grade level
    double gpa; // Double to store the student's GPA (Grade Point Average)

    // Constructor for the 'Student' class
    // A constructor is a special function that initializes object attributes when an object is created
    // (same name as the class, no return type, runs automatically).
    // The constructor here takes three parameters: roll, cls, and gpa
    // The parameters have the SAME names as the members. Inside this function a plain
    // "roll" means the parameter (the nearer name hides the member), so we need 'this'.
    Student(int roll, int cls, double gpa) {
        // 'this' is a pointer, automatically available inside every member function,
        // that holds the address of the current object (the one being built right now).
        // this->roll means "the roll member of the current object".
        // It is used to distinguish between constructor parameters and class attributes
        this->roll = roll; // Assign the parameter 'roll' to the class attribute 'roll'
        this->cls = cls;   // Assign the parameter 'cls' to the class attribute 'cls'
        this->gpa = gpa;   // Assign the parameter 'gpa' to the class attribute 'gpa'
    }
};

int main() {
    // Create a static object of the 'Student' class
    // Static objects are created on the stack and are automatically destroyed when their scope ends
    // (here: when main ends). The constructor runs with roll=45, cls=8, gpa=3.3.
    Student rahim(45, 8, 3.3); // 'rahim' is a static object with roll=45, cls=8, gpa=3.3

    // Create a dynamic object of the 'Student' class using the 'new' keyword
    // Dynamic objects are created on the heap and persist until explicitly deleted using 'delete'
    // Reading the line right to left:
    //   new Student(1, 8, 5.0)  -> make a Student on the heap, run the constructor, return its address
    //   Student* karim          -> karim is a "pointer to Student", a variable that stores that address
    Student* karim = new Student(1, 8, 5.0); // 'karim' is a pointer to a dynamically allocated object

    // Print the details of the static object 'rahim' using 'cout'
    // The attributes of 'rahim' are accessed directly using the dot operator (.)
    cout << rahim.roll << " " << rahim.cls << " " << rahim.gpa << endl; // 45 8 3.3

    // Print the details of the dynamic object 'karim' using 'cout'
    // Since 'karim' is a pointer, we use the arrow operator (->) to access its attributes
    // karim->roll is the same as (*karim).roll. (karim.roll would not compile: karim is an address, not an object.)
    cout << karim->roll << " " << karim->cls << " " << karim->gpa << endl; // 1 8 5 (cout prints 5.0 as 5)

    // NOTE: The dynamically allocated object is not deleted in this code
    // Ideally, we should free the memory to avoid memory leaks using:
    // delete karim;
    // (Here it does no harm because the program ends right after and the OS reclaims
    //  all its memory, but in longer programs every new should have a matching delete.)

    return 0; // Return 0 indicates successful program execution
}
