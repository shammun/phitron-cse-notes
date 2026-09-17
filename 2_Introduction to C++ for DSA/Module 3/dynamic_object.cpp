#include <iostream> // Include the iostream library for input/output operations
#include <string.h> // Include string.h for operations on character arrays (not used in this code)
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before cin, cout, etc.

// Define a class named 'Student' to encapsulate the properties of a student
class Student {
    public:
    int roll; // Integer to store the student's roll number
    int cls;  // Integer to store the student's class/grade level
    double gpa; // Double to store the student's GPA (Grade Point Average)

    // Constructor for the 'Student' class
    // A constructor is a special function that initializes object attributes when an object is created
    // The constructor here takes three parameters: roll, cls, and gpa
    Student(int roll, int cls, double gpa) {
        // 'this->' is a pointer to the current object.
        // It is used to distinguish between constructor parameters and class attributes
        this->roll = roll; // Assign the parameter 'roll' to the class attribute 'roll'
        this->cls = cls;   // Assign the parameter 'cls' to the class attribute 'cls'
        this->gpa = gpa;   // Assign the parameter 'gpa' to the class attribute 'gpa'
    }
};

int main() {
    // Create a static object of the 'Student' class
    // Static objects are created on the stack and are automatically destroyed when their scope ends
    Student rahim(45, 8, 3.3); // 'rahim' is a static object with roll=45, cls=8, gpa=3.3

    // Create a dynamic object of the 'Student' class using the 'new' keyword
    // Dynamic objects are created on the heap and persist until explicitly deleted using 'delete'
    Student* karim = new Student(1, 8, 5.0); // 'karim' is a pointer to a dynamically allocated object

    // Print the details of the static object 'rahim' using 'cout'
    // The attributes of 'rahim' are accessed directly using the dot operator (.)
    cout << rahim.roll << " " << rahim.cls << " " << rahim.gpa << endl;

    // Print the details of the dynamic object 'karim' using 'cout'
    // Since 'karim' is a pointer, we use the arrow operator (->) to access its attributes
    cout << karim->roll << " " << karim->cls << " " << karim->gpa << endl;

    // NOTE: The dynamically allocated object is not deleted in this code
    // Ideally, we should free the memory to avoid memory leaks using:
    // delete karim;

    return 0; // Return 0 indicates successful program execution
}
