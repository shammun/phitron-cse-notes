#include <iostream> // Include the iostream library for input/output operations
#include <string.h> // Include string.h for operations on character arrays (not used in this example but generally for strings)
using namespace std; // Use the standard namespace to avoid prefixing 'std::' before cin, cout, etc.

// Define a class named 'Student' to represent a student's information
class Student {
    public:
    int roll; // Integer to store the roll number of the student
    int cls; // Integer to store the class/grade of the student
    double gpa; // Double to store the GPA (Grade Point Average) of the student

    // Constructor for the 'Student' class to initialize the attributes
    Student(int r, int c, double g) {
        roll = r; // Initialize the 'roll' attribute with the value passed in 'r'
        cls = c;  // Initialize the 'cls' attribute with the value passed in 'c'
        gpa = g;  // Initialize the 'gpa' attribute with the value passed in 'g'
    }
};

int main() {
    // Create an instance of the Student class named 'rahim' and initialize it using the constructor
    Student rahim(21, 7, 3.8); // 'rahim' has roll=21, cls=7, gpa=3.8

    // Output the details of 'rahim' using 'cout'
    // 'cout' is used here to display the values of the object's attributes
    // The attributes are separated by spaces for readability
    cout << rahim.roll << " " << rahim.cls << " " << rahim.gpa << endl;

    // Variables to store user input for a new student
    int r; // To store roll number
    int c; // To store class/grade
    double g; // To store GPA

    // Read input from the user using 'cin'
    // 'cin' reads multiple values separated by spaces or newlines
    // It is suitable for this scenario where the input values are simple tokens
    cin >> r >> c >> g;

    // Create another instance of the Student class named 'karim' using the user input
    Student karim(r, c, g);

    // Output the details of 'karim' using 'cout'
    cout << karim.roll << " " << karim.cls << " " << karim.gpa << endl;

    return 0; // Return 0 indicates successful program execution
}
