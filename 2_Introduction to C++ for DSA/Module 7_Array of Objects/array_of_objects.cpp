/*
Array of objects
----------------
A class lets us bundle several facts about one thing (here: a student's name,
roll and marks) into ONE variable, called an object. An array of objects is
simply many such objects in a row: a[0], a[1], ..., a[n-1], where every box
holds a whole Student.

Part 1 reads n students whose names have NO spaces (cin >> is enough).
Part 2 reads n2 students whose names MAY have spaces (needs getline + cin.ignore()).

Sample input (both parts, one after the other)
2
Rahim 1 80
Karim 2 90
2
Abdul Karim
3 70
Md Rahim
4 60

Sample output
Rahim 1 80
Karim 2 90
Abdul Karim 370
Md Rahim 460
(Part 2 prints roll and marks with no space between them - see the note there.)
*/

#include <iostream> // Include the input/output stream library for using cin, cout and getline
#include <string> // Include the string library for std::string (a text variable that can grow to any length)

using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

// A class is a user-made type: a blueprint that says what every Student object contains.
// It does not create any student yet - it only describes one.
class Student{
    public: // "public:" means the members below can be read/written from outside the class, e.g. from main()
    string name; // member 1: the student's name
    int roll; // member 2: the roll number
    int marks; // member 3: the marks
}; // Define a class named Student (a class definition must end with a semicolon)

int main(){ // Program execution starts here
    // ---------- Part 1: names without spaces ----------
    int n; // how many students there are
    cin >> n; // Take input from the user (cin >> skips spaces/newlines and reads one number)
    // Create an array of objects of class Student: n boxes, each a full Student with name, roll, marks.
    // Note: an array whose size is a variable (n) is a "variable length array"; standard C++
    // does not allow it, but the g++ compiler accepts it as an extension, so it works on Codeforces.
    Student a[n];
    // Fill the array: one pass of the loop reads one student into box i (i goes 0,1,...,n-1)
    for(int i=0; i<n; i++){
        // a[i] is one whole object; the dot "." reaches inside it to one member.
        // cin >> reads one word at a time, so a name like "Rahim" (no space) is read completely.
        cin >> a[i].name >> a[i].roll >> a[i].marks; // Take input for the array of objects
    }

    // Print every student on its own line, in the order they were read
    for(int i=0; i<n; i++){
        // endl prints a newline and flushes the output
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl; // Print the array of objects
    }

    // ---------- Part 2: object's name with space ----------
    // Objec's name with space
    // cin >> stops at the first space, so "Abdul Karim" would be read as just "Abdul".
    // getline(cin, s) reads the WHOLE line (spaces included) up to the Enter key.
    int n2; // how many students in part 2
    cin >> n2; // read the count; the Enter key after it ('\n') is still waiting in the input
    Student a2[n2]; // a second array of n2 Student objects
    // One pass reads one student: a name line, then a line with roll and marks
    for(int i=0; i<n2; i++){
        // cin >> leaves the '\n' (Enter) after the last number it read in the input.
        // If we called getline now, it would see that '\n' at once and return an EMPTY name.
        // cin.ignore() throws away exactly one character - that leftover '\n'.
        // Pass 1: it removes the '\n' after n2. Later passes: the '\n' after the previous marks.
        cin.ignore();
        getline(cin, a2[i].name); // read the full name line, e.g. "Abdul Karim"
        cin >> a2[i].roll >> a2[i].marks; // roll and marks have no spaces, so cin >> is fine
    }

    // Print the part 2 students
    for(int i=0; i<n2; i++){
        // Note: there is no " " between roll and marks here, so roll 3 and marks 70 print as "370".
        // Add << " " between them if you want them separated.
        cout << a2[i].name << " " << a2[i].roll << a2[i].marks << endl;
    }

    return 0; // Indicate that the program ended successfully
}
