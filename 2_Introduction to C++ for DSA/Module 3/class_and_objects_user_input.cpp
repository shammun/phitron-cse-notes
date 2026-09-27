/*
 * Class and objects with user input.
 *
 * Same Student blueprint as class_and_objects.cpp, but now we build TWO objects
 * (a and b) and fill their members from the keyboard with cin.
 * Each object has its own separate copy of name, roll and gpa, so changing
 * a.roll never changes b.roll.
 *
 * Sample input:          Sample output:
 *   Sakib 10 4.56          Sakib 10 4.56
 *   Nabil 12 4.54          Nabil 12 4.54
 *
 * Limitation: cin >> into a char array stops at the first space, so a name like
 * "Sakib Ahmed" would NOT work here (see class_and_objects_user_input_with_space.cpp).
 */

#include<iostream> // gives cin (keyboard input) and cout (screen output)
#include<string.h> // C string functions for char arrays (not actually used in this file)
using namespace std; // lets us write cin/cout/endl without the std:: prefix

// Blueprint: what every Student object contains.
class Student{
    public: // members below may be used from outside the class, e.g. a.name in main
    char name[100]; // 100 bytes - text of up to 99 letters + '\0'
    int roll; // 4 bytes - roll number
    double gpa; // 8 bytes - GPA with a fractional part
}; // semicolon ends the class definition

int main(){
    Student a, b; // two independent Student objects, like int x, y; makes two ints

    // cin >> reads one "word" (token) at a time and skips spaces/newlines before it.
    // For a.name it reads letters until a space; for a.roll it reads an int; for a.gpa a double.
    // Input "Sakib 10 4.56" -> a.name = "Sakib", a.roll = 10, a.gpa = 4.56
    cin >> a.name >> a.roll >> a.gpa;
    cin >> b.name >> b.roll >> b.gpa; // same thing for the second student

    // Print each student's members on its own line (endl = newline).
    cout << a.name << " " << a.roll << " " << a.gpa << endl;
    cout << b.name << " " << b.roll << " " << b.gpa << endl;

    return 0; // program finished normally
}