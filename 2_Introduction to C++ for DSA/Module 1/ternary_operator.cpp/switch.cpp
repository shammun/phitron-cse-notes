#include <iostream> // This header file is used to perform input and output operations
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

// The idea: turn a day number into a day name.
// You could write this as `if (day == 1) ... else if (day == 2) ...` seven times over.
// When one variable is compared against a list of fixed values, `switch` says the same
// thing in a flatter shape: name the variable once, then list the values.
// Example input: 3   ->  output: Wednesday
// Example input: 9   ->  output: Invalid day

// main() is where the program starts running.
int main(){
    int day; // The day number typed by the user (1 = Monday ... 7 = Sunday)
    cin >> day; // Read it from the keyboard

    // switch(day) evaluates `day` once and jumps straight to the `case` label that equals
    // it. The cases must be constants known at compile time, and the value must be an
    // integer-like type (int, char, enum) - a switch on a string will not compile.
    switch(day){
        case 1: // day == 1
            cout << "Monday\n"; // "\n" is the newline character
            // The trap of switch: a case is a jump target, not a closed block. Without
            // this `break` the program would keep running into case 2 and print Tuesday
            // as well, then Wednesday, and so on until it met a break. Every case here
            // ends with break because each day name should be printed on its own.
            break;
        case 2: // day == 2
            cout << "Tuesday\n";
            break; // leave the switch
        case 3: // day == 3
            cout << "Wednesday\n";
            break; // leave the switch
        case 4: // day == 4
            cout << "Thursday\n";
            break; // leave the switch
        case 5: // day == 5
            cout << "Friday\n";
            break; // leave the switch
        case 6: // day == 6
            cout << "Saturday\n";
            break; // leave the switch
        case 7: // day == 7
            cout << "Sunday\n";
            break; // leave the switch
        // `default` is the else of a switch: it runs when no case matched, so 0, 8 or -3
        // land here. It needs no break only because it is the last thing in the switch.
        default:
            cout << "Invalid day\n";
    }

    return 0; // Program ended successfully
}
