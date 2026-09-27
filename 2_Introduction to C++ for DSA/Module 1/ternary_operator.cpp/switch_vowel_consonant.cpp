// Topic: switch on a char - print Vowel for a, e, i, o, u (either case), otherwise Consonant.
// Example input: E  -> Vowel
// Example input: k  -> Consonant
// (Any other character, e.g. 5 or #, also prints Consonant, because default catches everything else.)

#include <iostream> // This header file is used to perform input and output operations
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

// main() is where the program starts running.
int main(){
    char ch; // One character
    cin >> ch; // Read one non-space character from the input

    /*
    In C, we can use if-else to check if a character is a vowel or consonant
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
        cout << "Vowel\n";
    } else {
        cout << "Consonant\n";
    }
    (kept commented out to compare: || means "or", so the if is true when ch is any vowel)
    */
    // switch works on a char because a char is really an integer (its ASCII code),
    // and each 'x' in a case label is a constant. switch jumps to the matching case;
    // every case prints "Vowel" and then break leaves the switch.
    // (Shorter form: stack the labels  case 'a': case 'e': ... case 'U': cout << "Vowel\n"; break;
    //  - without a break between them, the empty cases "fall through" to the shared code.)
    switch(ch){
        case 'a': // lowercase a
            cout << "Vowel\n";
            break; // leave the switch
        case 'e': // lowercase e
            cout << "Vowel\n";
            break; // leave the switch
        case 'i': // lowercase i
            cout << "Vowel\n";
            break; // leave the switch
        case 'o': // lowercase o
            cout << "Vowel\n";
            break; // leave the switch
        case 'u': // lowercase u
            cout << "Vowel\n";
            break; // leave the switch
        case 'A': // uppercase A (a different ASCII code from 'a', so it needs its own case)
            cout << "Vowel\n";
            break; // leave the switch
        case 'E': // uppercase E
            cout << "Vowel\n";
            break; // leave the switch
        case 'I': // uppercase I
            cout << "Vowel\n";
            break; // leave the switch
        case 'O': // uppercase O
            cout << "Vowel\n";
            break; // leave the switch
        case 'U': // uppercase U
            cout << "Vowel\n";
            break; // leave the switch
        default: // no vowel matched -> everything else
            cout << "Consonant\n";
    }

    return 0; // Program ended successfully
}