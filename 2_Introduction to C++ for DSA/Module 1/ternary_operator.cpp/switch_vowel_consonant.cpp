#include <iostream> // This header file is used to perform input and output operations
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

int main(){
    char ch;
    cin >> ch;

    /*
    In C, we can use if-else to check if a character is a vowel or consonant
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
        cout << "Vowel\n";
    } else {
        cout << "Consonant\n";
    }
    */
    switch(ch){
        case 'a':
            cout << "Vowel\n";
            break;
        case 'e':
            cout << "Vowel\n";
            break;
        case 'i':
            cout << "Vowel\n";
            break;
        case 'o':
            cout << "Vowel\n";
            break;
        case 'u':
            cout << "Vowel\n";
            break;
        case 'A':
            cout << "Vowel\n";
            break;
        case 'E':
            cout << "Vowel\n";
            break;
        case 'I':
            cout << "Vowel\n";
            break;
        case 'O':
            cout << "Vowel\n";
            break;
        case 'U':
            cout << "Vowel\n";
            break;
        default:
            cout << "Consonant\n";
    }

    return 0;
}
