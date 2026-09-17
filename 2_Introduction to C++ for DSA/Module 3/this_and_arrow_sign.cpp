#include <iostream> // Include the iostream library to enable input/output operations
#include <string.h> // Include string.h for character array operations (not used in this code)
using namespace std; // Use the standard namespace to simplify code (avoids prefixing 'std::')

// Define a class named 'Student' to encapsulate the properties of a student
class Student {
    public:
    int roll; // Integer to store the student's roll number
    int cls; // Integer to store the student's class/grade level
    double gpa; // Double to store the student's GPA (Grade Point Average)

    // Constructor for the 'Student' class
    // A constructor is a special function that initializes object attributes when an object is created
    // Here, the constructor takes three parameters: roll, cls, and gpa
    Student(int roll, int cls, double gpa) {
        // 'this->' is a pointer to the current object.
        // It differentiates between the constructor parameter 'roll' and the class attribute 'roll'.
        this->roll = roll; // Assign the parameter 'roll' to the class attribute 'roll'
        // We can also use the equivalent notation *(this).roll instead of 'this->roll'
        this->cls = cls;   // Assign the parameter 'cls' to the class attribute 'cls'
        // We can also use the equivalent notation *(this).cls instead of 'this->cls'
        this->gpa = gpa;   // Assign the parameter 'gpa' to the class attribute 'gpa'
        // We can also use the equivalent notation *(this).gpa instead of 'this->gpa'

        // Note: Instead of 'this->roll', we could also use the equivalent notation '*(this).roll',
        // but 'this->' is more commonly used for clarity and simplicity.
    }
};

int main() {
    // Create an object of the 'Student' class named 'rahim' with roll=45, cls=8, and gpa=3.3
    Student rahim(45, 8, 3.3);

    // Create another object of the 'Student' class named 'karim' with roll=1, cls=8, and gpa=5.0
    Student karim(1, 8, 5.0);

    // Output the details of 'karim' using 'cout'
    // 'cout' prints the values in a readable format with fields separated by spaces
    cout << karim.roll << " " << karim.cls << " " << karim.gpa << endl;

    // Output the details of 'rahim' using 'cout'
    cout << rahim.roll << " " << rahim.cls << " " << rahim.gpa << endl;

    // Return 0 indicates that the program executed successfully
    return 0;
}
