#include <iostream> // This header file is used to perform input and output operations
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

// The idea: turn a day number into a day name.
// You could write this as `if (day == 1) ... else if (day == 2) ...` seven times over.
// When one variable is compared against a list of fixed values, `switch` says the same
// thing in a flatter shape: name the variable once, then list the values.

int main(){
    int day;
    cin >> day;

    // switch(day) evaluates `day` once and jumps straight to the `case` label that equals
    // it. The cases must be constants known at compile time, and the value must be an
    // integer-like type (int, char, enum) - a switch on a string will not compile.
    switch(day){
        case 1:
            cout << "Monday\n";
            // The trap of switch: a case is a jump target, not a closed block. Without
            // this `break` the program would keep running into case 2 and print Tuesday
            // as well, then Wednesday, and so on until it met a break. Every case here
            // ends with break because each day name should be printed on its own.
            break;
        case 2:
            cout << "Tuesday\n";
            break;
        case 3:
            cout << "Wednesday\n";
            break;
        case 4:
            cout << "Thursday\n";
            break;
        case 5:
            cout << "Friday\n";
            break;
        case 6:
            cout << "Saturday\n";
            break;
        case 7:
            cout << "Sunday\n";
            break;
        // `default` is the else of a switch: it runs when no case matched, so 0, 8 or -3
        // land here. It needs no break only because it is the last thing in the switch.
        default:
            cout << "Invalid day\n";
    }

    return 0;    
}
