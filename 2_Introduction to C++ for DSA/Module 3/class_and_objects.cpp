/*
 * Class and object - the very first example.
 *
 * A CLASS is a blueprint for a new, user-made data type. It groups several
 * related variables (called MEMBERS or attributes) under one name.
 * Here the blueprint "Student" says: every student has a name, a roll and a gpa.
 *
 * An OBJECT is one real thing built from that blueprint. `Student a;` makes one
 * student called a, with its own name, roll and gpa boxes inside it.
 * We reach a member of an object with the dot: a.roll, a.gpa, a.name.
 *
 * Sample output: Sakib 13 4.5
 */

#include<iostream> // gives cin (keyboard input) and cout (screen output)
#include<string.h> // C string functions for char arrays; we need strcpy() from here
using namespace std; // lets us write cout instead of std::cout (cin, cout, endl live in the "std" namespace)

// Blueprint of a student. Making a class does NOT create any student yet;
// it only describes what every Student object will contain.
class Student{
    public: // "public:" means code outside the class (like main) may read and change these members.
            // Without it, class members are private by default and a.roll in main would not compile.
    char name[100]; // 100 bytes - a char array that can hold a name of up to 99 letters + the '\0' end mark
    int roll; // 4 bytes - the roll number
    double gpa; // 8 bytes - the GPA, double because it has a fractional part (4.5)
}; // a class definition must end with a semicolon after the closing brace

int main(){
    Student a; // create ONE object named a of type Student; its members hold garbage until we fill them
    a.roll = 13; // put 13 into the roll member of object a (dot = "member of")
    a.gpa = 4.5; // put 4.5 into the gpa member of a
    char temp[100] = "Sakib"; // a normal char array holding the text "Sakib" followed by '\0'

    // Arrays cannot be assigned with = in C/C++ (a.name = temp; is a compile error),
    // so we copy the letters one by one with strcpy(destination, source).
    // strcpy copies "Sakib" and its ending '\0' into a.name.
    strcpy(a.name, temp);

    // Print the three members separated by spaces; endl ends the line (and flushes the output).
    // cout prints a char array as text up to its '\0', so a.name prints "Sakib".
    cout << a.name << " " << a.roll << " " << a.gpa << endl;
    return 0; // 0 tells the operating system the program finished normally
}