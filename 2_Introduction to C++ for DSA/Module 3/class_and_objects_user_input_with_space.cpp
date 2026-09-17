#include<iostream>
#include<string.h>
using namespace std;
class Student{
    public:
    char name[100]; // 100 bytes
    int roll; // 4 bytes
    double gpa; // 8 bytes
};

int main(){
    Student a, b; // Create two instances of the 'Student' class named 'a' and 'b'

    // Now, name will have spaces between the words
    // use getline() to read a line of text from the input stream
    // getline() even takes new line as input
    // cin.ignore() is used to ignore the newline character left in the input 
    // stream after reading the string
    
    // Reading input for student 'a'

    // Use 'cin.getline()' to read a full line of input into 'a.name'
    // This allows us to read names with spaces, as 'cin' alone stops at spaces
    cin.getline(a.name, 100); // Read up to 99 characters into the 'name' array

    // Read the roll number and GPA for student 'a' using 'cin'
    // 'cin' is used here because roll numbers and GPAs are single tokens and don't require special handling for spaces
    cin >> a.roll >> a.gpa;

    // Use 'cin.ignore()' to skip the newline character left in the input buffer
    // After reading the roll and GPA, a newline remains, which would otherwise interfere with the next 'cin.getline()'
    cin.ignore(); // We can also use getchar() to skip the newline character

    /*

    Following is the input format:

    Sakib Ahmed
    10 4.56
    Nabil Ahmed
    12 4.54
    Sakib Ahmed 10 4.56
    Nabil Ahmed 12 4.54
    */

    // Reading input for student 'b'

    // Again, use 'cin.getline()' to read a full line of input into 'b.name'
    cin.getline(b.name, 100);

    // Read the roll number and GPA for student 'b'
    cin >> b.roll >> b.gpa;

    // Output the information for both students using 'cout'
    // 'cout' is used here for formatted output, printing each field separated by spaces
    cout << a.name << " " << a.roll << " " << a.gpa << endl;
    cout << b.name << " " << b.roll << " " << b.gpa << endl;

    return 0; // Return 0 indicates successful program execution
}