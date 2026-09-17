#include <iostream> // Include the iostream library for input/output operations
#include <string.h> // Include string.h for character array operations (not used in this code)
using namespace std; // Use the standard namespace to avoid prefixing 'std::'

// Define a class named 'Student' to encapsulate the properties of a student
class Student {
    public:
    int roll; // Integer to store the student's roll number
    int cls;  // Integer to store the student's class/grade level
    double gpa; // Double to store the student's GPA (Grade Point Average)

    // Constructor for the 'Student' class
    // A constructor is a special function that initializes object attributes when an object is created
    Student(int roll, int cls, double gpa) {
        this->roll = roll; // Assign the parameter 'roll' to the class attribute 'roll'
        this->cls = cls;   // Assign the parameter 'cls' to the class attribute 'cls'
        this->gpa = gpa;   // Assign the parameter 'gpa' to the class attribute 'gpa'

        // 'this->' is used to clearly distinguish between class attributes and function parameters
    }
};

// Function that returns a pointer to a 'Student' object
Student* fun() {
    Student karim(2, 5, 4.95); // Create a static object 'karim' inside the function

    // A pointer 'p' is initialized to store the address of 'karim'
    Student* p = &karim;

    // Return the pointer 'p' which points to 'karim'
    // NOTE: 'karim' is a local object and exists only while this function executes
    return p; // The pointer becomes invalid after the function exits
}

int main() {
    Student* p = fun(); // Call the function and store the returned pointer in 'p'

    // Attempt to access the attributes of the object pointed to by 'p'
    // This prints garbage values because the object 'karim' no longer exists
    cout << p->roll << " " << p->cls << " " << p->gpa << endl;

    return 0; // Return 0 indicates successful program execution
}
