/*
Copying one dynamic object into another.

A "dynamic object" is an object made with new: it lives on the heap (memory we
manage ourselves) and we only hold a POINTER to it. That matters for copying:
  - pointer = pointer      copies only the ADDRESS (both names now share one object)
  - p->member = q->member  copies one member at a time into a separate object
  - *p = *q                copies ALL members of the object q points to into the object p points to
This file tries the three ways. It also shows why using an object after delete is wrong.
*/

#include<iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string>   // Gives us std::string, used for country and name
#include <sstream> // stringstream library; not actually used in this file
#include <algorithm> // algorithm library (sort, reverse, ...); not actually used in this file
using namespace std; // Lets us write cout, string instead of std::cout, std::string

// A class is a blueprint for our own type: it bundles related data together.
// Every Cricketer object will have its own country, name and jersey number.
class Cricketer{
    public: // public: the members below can be used from outside the class (e.g. from main)
    string country; // member variable: the player's country
    string name; // member variable: the player's name
    int jersy; // member variable: the jersey number (spelled "jersy" in this code)

    // Constructor: a special function with the same name as the class and no
    // return type. It runs automatically when an object is created and fills in its members.
    // The parameters have the same names as the members, so "this->" is used to
    // mean "the member of THIS object" (this is a pointer to the object being built).
    Cricketer(string country, string name, int jersy){
        this->country = country; // member country = parameter country
        this->name = name; // member name = parameter name
        this->jersy = jersy; // member jersy = parameter jersy
    } // end of the constructor
}; // a class definition ends with a semicolon
int main() {
    // new Cricketer(...) creates an object on the heap, runs the constructor,
    // and gives back its address. dhoni is a pointer (Cricketer*) holding that address.
    Cricketer* dhoni = new Cricketer("India", "Dhoni", 100);
    // -> reaches a member THROUGH a pointer: dhoni->name means (*dhoni).name
    cout << "Jersy number of cricketer " << dhoni->name << " is " << dhoni->jersy << endl; // prints: ... Dhoni is 100

    Cricketer* kohli = new Cricketer("India", "Kohli", 13); // a second, separate object on the heap
    cout << "Jersy number of cricketer " << kohli->name << " is " << kohli->jersy << endl; // prints: ... Kohli is 13

    // Copy the object dhoni to kohli
    // kohli = dhoni; // This compiles, but it copies only the ADDRESS, not the object:
    // kohli = dhoni basically points kohli to the object dhoni
    // (both pointers would then share Dhoni's object, and the Kohli object would be lost - a memory leak.)

    // Way 1: copy members one by one. kohli's object stays separate from dhoni's.
    // Note: name is NOT copied, so kohli->name is still "Kohli".
    kohli->country = dhoni->country; // copy the country
    kohli->jersy = dhoni->jersy; // copy the jersey number (kohli->jersy becomes 100)
    delete dhoni; // delete frees the heap memory of Dhoni's object; the pointer dhoni now points to freed memory

    // kohli owns its own copy, so it is still fine after dhoni was deleted.
    cout << "Jersy number of cricketer " << kohli->name << " is " << kohli->jersy << endl; // prints: ... Kohli is 100

    // Another way to copy the object dhoni to kohli
    // Way 2: build a brand-new object, passing the other object's members to the constructor.
    // BUG: dhoni was already deleted above, so dhoni->country, dhoni->name and dhoni->jersy
    // read freed memory (use-after-free, undefined behaviour: it may print garbage or crash).
    // Fix: create kohli2 BEFORE the line "delete dhoni;" (or move that delete below this line).
    Cricketer* kohli2 = new Cricketer(dhoni->country, dhoni->name, dhoni->jersy);
    cout << "Jersy number of cricketer " << kohli2->name << " is " << kohli2->jersy << endl; // meant to print: ... Dhoni is 100
    delete kohli2; // free kohli2's object; every new needs a matching delete

    delete kohli; // free kohli's object

    // Using deference to copy the object dhoni to kohli
    // Way 3: dereference both pointers. *dhoni3 is "the object dhoni3 points to".
    Cricketer* dhoni3 = new Cricketer("India", "Dhoni", 100); // fresh Dhoni object
    Cricketer* kohli3 = new Cricketer("India", "Kohli", 13); // fresh Kohli object
    *kohli3 = *dhoni3; // Using deference to copy the object dhoni to kohli: copies ALL members (country, name, jersy)
    cout << "Jersy number of cricketer " << kohli3->name << " is " << kohli3->jersy << endl; // prints: ... Dhoni is 100
    delete dhoni3; // free Dhoni's object; kohli3 is a separate object so it is unaffected
    cout << "Jersy number of cricketer " << kohli3->name << " is " << kohli3->jersy << endl; // still prints: ... Dhoni is 100
    // (kohli3 is never deleted; the memory is given back to the OS when the program ends,
    //  but a matching "delete kohli3;" would be the tidy thing to do.)

    return 0; // the program ended successfully
} // end of main
