/*
A function inside a class (a "member function" or "method").

Besides data, a class can hold functions. A member function is called on one
object with a dot: shammunul.hello(). Inside it, the names name, math, english
automatically mean the members of THAT object, so the same function prints
different things for different objects.
*/

#include<iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string>   // Gives us std::string, used for the student's name
#include <sstream> // stringstream library; not actually used in this file
#include <algorithm> // algorithm library (sort, reverse, ...); not actually used in this file
using namespace std; // Lets us write cout, string instead of std::cout, std::string

// Student: a blueprint that bundles one student's data and a function that uses it.
class Student{
    public: // public: everything below can be used from main
    string name; // member variable: the student's name
    int roll; // member variable: roll number
    int math; // member variable: marks in math
    int english; // member variable: marks in English
    // Constructor: same name as the class, no return type; runs when an object is created.
    // this is a pointer to the object being created; this->name is its member,
    // while plain name here is the parameter (the parameter hides the member).
    Student(string name, int roll, int math, int english){
        this->name = name; // store the parameter in the member
        this->roll = roll;
        this->math = math;
        this->english = english;
    } // end of the constructor
    // Member function: void means it returns nothing, it just prints.
    // Here name, math, english are the members of the object it was called on.
    void hello(){
        cout << "Hello from " << name << endl; // e.g. "Hello from Shammunul Islam"
        cout << "Total marks of " << name << " is " << math + english << endl; // e.g. 99 + 85 = 184
    } // end of hello
}; // a class definition ends with a semicolon

int main() {
    // Create an object on the stack (no new): the constructor gets the 4 values in order.
    Student shammunul("Shammunul Islam", 1, 99, 85);
    cout << shammunul.name << " " << shammunul.roll << endl; // . reads a member of an object: prints "Shammunul Islam 1"
    shammunul.hello(); // call the member function for this object: prints its greeting and total 184
    Student milon("Milon Miah", 10, 85, 71); // a second, independent object
    cout << milon.name << " " << milon.roll << endl; // prints "Milon Miah 10"
    milon.hello(); // same function, different object: total is 85 + 71 = 156
    return 0; // the program ended successfully
} // end of main
