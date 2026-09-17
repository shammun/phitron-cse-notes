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
    Student(int roll, int cls, double gpa) {
        this->roll = roll; // Assign the parameter 'roll' to the class attribute 'roll'
        this->cls = cls;   // Assign the parameter 'cls' to the class attribute 'cls'
        this->gpa = gpa;   // Assign the parameter 'gpa' to the class attribute 'gpa'

        // 'this->' is used to clearly distinguish between class attributes and function parameters
    }
};

// Function that dynamically creates and returns a pointer to a 'Student' object
Student* fun() {
    // Dynamically allocate memory for the 'Student' object on the heap
    Student* karim = new Student(2, 5, 4.95);
    
    // Return the pointer to the dynamically allocated object
    return karim;
}

int main() {
    // Call the 'fun' function and store the returned pointer in 'p'
    // 'p' points to a dynamically allocated object created in the 'fun' function
    Student* p = fun();

    // Access and print the attributes of the dynamically allocated object using the arrow operator (->)
    // The arrow operator is used because 'p' is a pointer to the object
    cout << p->roll << " " << p->cls << " " << p->gpa << endl;

    // Free the dynamically allocated memory to prevent memory leaks
    delete p;

    return 0; // Return 0 indicates successful program execution
}
