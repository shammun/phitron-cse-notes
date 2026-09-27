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

// Idea: same task as practice_problem1.cpp, but a constructor fills every object
// in one line. Then three comparisons decide who has the highest math_marks.
// Output here: Rahim

// Define a class named 'Student' to encapsulate the properties of a student
// A class is a blueprint for a new data type; each object made from it has its own copy of every member.
class Student {
    public: // members and the constructor can be used from main
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
    // A constructor has the same name as the class and no return type.
    // `this` is a pointer holding the address of the object being built, and
    // this->x (same as (*this).x) reaches that object's member x.
    Student(const char* name, int roll, char section, int math_marks, int cls){
        strcpy(this->name, name); // a char array can't be assigned with =, so copy it (letters + '\0')
        this->roll = roll; // object's roll = the roll parameter
        this->section = section; // object's section = parameter (a single char like 'A')
        this->math_marks = math_marks; // object's math_marks = parameter
        this->cls = cls; // object's cls = parameter
    }
};

int main() {
    // Create three static objects of the 'Student' class; the constructor fills each one in a single line
    // Values in brackets go to the constructor parameters in order: name, roll, section, math_marks, cls.
    Student rahim("Rahim", 1, 'A', 99, 7); // math_marks 99
    Student karim("Karim", 2, 'A', 98, 7); // math_marks 98
    Student rafiq("Rafiq", 3, 'A', 96, 7); // math_marks 96


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