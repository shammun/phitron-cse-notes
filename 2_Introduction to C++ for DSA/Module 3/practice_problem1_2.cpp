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
#include <string.h> // Include string.h for character array operations (not used in this code)
using namespace std; // Use the standard namespace to avoid prefixing 'std::'

// Define a class named 'Student' to encapsulate the properties of a student
class Student {
    public:
    char name[100]; // Character array to store the student's name
    int roll; // Integer to store the student's roll number
    char section; // Character to store the student's section
    int math_marks; // Integer to store the student's math marks
    int cls; // Integer to store the student's class

    Student(char* name, int roll, char section, int math_marks, int cls){
        strcpy(this->name, name);
        this->roll = roll;
        this->section = section;
        this->math_marks = math_marks;
        this->cls = cls;
    }
};

int main() {
    // Create three static objects of the 'Student' class
    Student rahim("Rahim", 1, 'A', 99, 7);
    Student karim("Karim", 2, 'A', 98, 7);
    Student rafiq("Rafiq", 3, 'A', 96, 7);


    // Compare the math marks of the objects and print the name of the student with the highest math marks
    if(rahim.math_marks > karim.math_marks && rahim.math_marks > rafiq.math_marks) {
        cout << rahim.name << endl; // Print the name of 'rahim' if he has the highest math marks
    } else if(karim.math_marks > rahim.math_marks && karim.math_marks > rafiq.math_marks){
        cout << karim.name << endl; // Print the name of 'karim' if he has the highest math marks
    } else {
        cout << rafiq.name << endl; // Print the name of 'rafiq' if he has the highest math marks
    }

    return 0; // Return 0 indicates successful program execution

}