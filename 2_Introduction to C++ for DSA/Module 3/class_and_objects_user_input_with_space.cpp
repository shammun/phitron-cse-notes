/*
 * Class objects whose name contains SPACES ("Sakib Ahmed").
 *
 * Problem: cin >> a.name stops at the first space, so it would read only "Sakib".
 * Fix: cin.getline(array, size) reads the WHOLE line, spaces included.
 * New problem: mixing cin >> and getline. After cin >> a.gpa, the Enter key
 * ('\n') the user pressed is still waiting in the input. The next getline would
 * read that empty rest-of-line and give b an empty name. cin.ignore() throws
 * that one leftover '\n' away first.
 *
 * Sample input:          Sample output:
 *   Sakib Ahmed            Sakib Ahmed 10 4.56
 *   10 4.56                Nabil Ahmed 12 4.54
 *   Nabil Ahmed
 *   12 4.54
 */

#include<iostream> // gives cin, cout, and the member functions cin.getline() and cin.ignore()
#include<string.h> // C string functions for char arrays (not actually used in this file)
using namespace std; // lets us write cin/cout/endl without the std:: prefix

// Blueprint: what every Student object contains.
class Student{
    public: // members may be used from outside the class (from main)
    char name[100]; // 100 bytes - up to 99 characters of the name + '\0'
    int roll; // 4 bytes - roll number
    double gpa; // 8 bytes - GPA
}; // semicolon ends the class definition

int main(){
    Student a, b; // Create two instances of the 'Student' class named 'a' and 'b'

    // Now, name will have spaces between the words.
    // cin.getline() reads a whole line of text from the input stream, spaces included.
    // It reads up to and including the newline, but it does NOT store the newline:
    // the '\n' is taken out of the input and thrown away, the array gets only the text.
    // cin.ignore() is used to throw away the newline character left in the input
    // stream after reading the numbers with cin >> (cin >> never removes that '\n').

    // Reading input for student 'a'

    // Use 'cin.getline()' to read a full line of input into 'a.name'
    // This allows us to read names with spaces, as 'cin' alone stops at spaces
    // 100 = size of the array; getline stores at most 99 characters and then adds '\0'.
    cin.getline(a.name, 100); // Read up to 99 characters into the 'name' array -> "Sakib Ahmed"

    // Read the roll number and GPA for student 'a' using 'cin'
    // 'cin' is used here because roll numbers and GPAs are single tokens and don't require special handling for spaces
    // After this line the input still holds the '\n' typed after "4.56".
    cin >> a.roll >> a.gpa; // a.roll = 10, a.gpa = 4.56

    // Use 'cin.ignore()' to skip the newline character left in the input buffer
    // After reading the roll and GPA, a newline remains, which would otherwise interfere with the next 'cin.getline()'
    // cin.ignore() with no arguments removes exactly ONE character (here that '\n').
    cin.ignore(); // We can also use getchar() to skip the newline character

    /*

    Following is the input format (name on its own line, then roll and gpa):

    Sakib Ahmed
    10 4.56
    Nabil Ahmed
    12 4.54

    The expected output is one line per student:

    Sakib Ahmed 10 4.56
    Nabil Ahmed 12 4.54
    */

    // Reading input for student 'b'

    // Again, use 'cin.getline()' to read a full line of input into 'b.name'
    // Because cin.ignore() already removed the old '\n', this reads "Nabil Ahmed".
    // (Without cin.ignore(), b.name would become "" and the numbers would go wrong.)
    cin.getline(b.name, 100);

    // Read the roll number and GPA for student 'b'
    cin >> b.roll >> b.gpa; // b.roll = 12, b.gpa = 4.54 (no getline follows, so no ignore needed)

    // Output the information for both students using 'cout'
    // 'cout' is used here for formatted output, printing each field separated by spaces
    // endl ends the line.
    cout << a.name << " " << a.roll << " " << a.gpa << endl;
    cout << b.name << " " << b.roll << " " << b.gpa << endl;

    return 0; // Return 0 indicates successful program execution
}