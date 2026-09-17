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
};

int main() {
    // Create three static objects of the 'Student' class
    Student rahim;
    Student karim;
    Student rafiq;

    // Assign values to the attributes of the objects
    strcpy(rahim.name, "Rahim"); // Copy the name "Rahim" to the 'name' attribute of 'rahim'
    rahim.roll = 1; // Assign the roll number 1 to 'rahim'
    rahim.section = 'A'; // Assign the section 'A' to 'rahim'
    rahim.math_marks = 96; // Assign the math marks 96 to 'rahim'
    rahim.cls = 7; // Assign the class 7 to 'rahim'

    // Assign values to the attributes of the objects
    strcpy(karim.name, "Karim"); // Copy the name "Rahim" to the 'name' attribute of 'rahim'
    karim.roll = 2; // Assign the roll number 2 to 'karim'
    karim.section = 'A'; // Assign the section 'A' to 'karim'
    karim.math_marks = 94; // Assign the math marks 94 to 'karim'
    karim.cls = 7; // Assign the class 7 to 'karim'

    // Assign values to the attributes of the objects
    strcpy(rafiq.name, "Rafiq"); // Copy the name "Rahim" to the 'name' attribute of 'rahim'
    rafiq.roll = 3; // Assign the roll number 2 to 'rafiq'
    rafiq.section = 'A'; // Assign the section 'A' to 'rafiq'
    rafiq.math_marks = 90; // Assign the math marks 94 to 'rafiq'
    rafiq.cls = 7; // Assign the class 7 to 'rafiq'

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