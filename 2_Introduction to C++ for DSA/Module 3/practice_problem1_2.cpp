/*

Question: Create three static objects with the help of the constructor of the following class.
Student
{
	name;
	roll;
	section;
	math_marks;
	cls;
}
Then compare those 3 objects and print who got the highest math_marks and print his/her name.


*/

#include <iostream> // Include the iostream library for input/output operations
#include <string.h> // Include string.h for strcpy(), used inside the constructor
using namespace std; // Use the standard namespace to avoid prefixing 'std::'

// Define a class named 'Student' to encapsulate the properties of a student
class Student {
    public:
    char name[100]; // Character array to store the student's name
    int roll; // Integer to store the student's roll number
    char section; // Character to store the student's section
    int math_marks; // Integer to store the student's math marks
    int cls; // Integer to store the student's class

    // Constructor: runs automatically when an object is created and fills its
    // data from the values given in brackets, e.g. Student rahim("Rahim", 1, ...).
    // `const char*` because a quoted name like "Rahim" is read-only text.
    // The parameters have the same names as the members, so `this->name` means
    // "the object's own name" and plain `name` means the parameter.
    Student(const char* name, int roll, char section, int math_marks, int cls){
        strcpy(this->name, name); // a char array can't be assigned with =, so copy it
        this->roll = roll;
        this->section = section;
        this->math_marks = math_marks;
        this->cls = cls;
    }
};

int main() {
    // Create three static objects of the 'Student' class; the constructor fills each one in a single line
    Student rahim("Rahim", 1, 'A', 99, 7);
    Student karim("Karim", 2, 'A', 98, 7);
    Student rafiq("Rafiq", 3, 'A', 96, 7);


    // Compare the math marks of the objects and print the name of the student with the highest math marks.
    // >= (not >) so that a tie at the top still picks one of the tied students.
    if(rahim.math_marks >= karim.math_marks && rahim.math_marks >= rafiq.math_marks) {
        cout << rahim.name << endl; // Print the name of 'rahim' if he has the highest math marks
    } else if(karim.math_marks >= rafiq.math_marks){ // rahim is not the top, so only karim vs rafiq is left
        cout << karim.name << endl; // Print the name of 'karim' if he has the highest math marks
    } else {
        cout << rafiq.name << endl; // Print the name of 'rafiq' if he has the highest math marks
    }

    return 0; // Return 0 indicates successful program execution

}