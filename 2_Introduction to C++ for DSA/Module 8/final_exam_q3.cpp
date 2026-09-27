/*

Final exam question 3 - reverse the sections

(The statement was not saved with this file; this is what the code solves.)
Read N students, each with a name (nm), a class (cls), a section letter (s)
and an id. Everything stays where it is except the sections: the section
column is reversed, so the first student gets the last student's section,
the second gets the second-last one's, and so on. Print the students in the
original order with their new sections.

Example (made up to show the idea)
Input
3
rahim 5 A 11
karim 6 B 12
jodu 7 C 13
Output
rahim 5 C 11
karim 6 B 12
jodu 7 A 13

*/

#include <iostream> // cin and cout
#include <string>   // std::string
using namespace std; // write cin/cout/string instead of std::cin/...

// One object holds one student's data.
// A class is a blueprint; "public:" lets main() read and change these members directly.
class Student{
    public:
    string nm; // name (no spaces)
    int cls; // class number
    char s; // section: a single letter like 'A' (char holds one character)
    int id; // student id
}; // a class definition ends with a semicolon

int main(){ // Program execution starts here
    int n; // number of students
    cin >> n; // read n

    Student a[n]; // an array of n Student objects (size from a variable: a g++ extension)

    // One pass reads one student into box i; the dot "." picks a member of the object a[i]
    for(int i=0; i<n; i++){
        cin >> a[i].nm; // name
        cin >> a[i].cls; // class
        cin >> a[i].s; // section: cin >> into a char reads one non-space character
        cin >> a[i].id; // id
    }

    // reverse section by swapping the first half with the second half.
    // Only the member .s moves; names, classes and ids stay in place.
    // Student i pairs with student n-1-i; stop at the middle, or each pair
    // would be swapped twice and nothing would change.
    // With n = 3: i = 0 swaps sections of a[0] and a[2] (A <-> C); a[1] keeps B.
    for(int i=0; i<n/2; i++){
        char temp = a[i].s; // keep a copy of the left section, or it would be lost
        a[i].s = a[n-i-1].s; // left gets the right one's section
        a[n-i-1].s = temp; // right gets the saved left section
    }

    // Print every student in the original order, now with the new section
    for(int i=0; i<n; i++){
        cout << a[i].nm << " " << a[i].cls << " " << a[i].s << " " << a[i].id << endl;
    }

    return 0; // the program ended successfully
}
