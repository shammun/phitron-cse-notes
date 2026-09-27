// Topic: printing variables with std::cout (the C++ replacement for printf).
// Output:
//   1010 A 34.56
//   My favorite number is 10
// (The first line starts with "1010" because the first cout prints 10 with no newline,
//  and the second cout prints 10 again right after it.)

#include <iostream> // Header that gives us std::cout (screen output) and std::endl

// main() is where the program starts running.
int main(){
    int x = 10; // An integer variable holding 10
    // In C, printf("%d", x) is used to print a variable
    // In C++, cout << x is used to print a variable
    // (cout looks at the type of x itself, so no %d is needed.
    //  std:: is needed because this file has no "using namespace std;".)
    std::cout << x; // printf("%d", x) is equivalent to cout << x

    char c = 'A'; // A character variable holding the letter A
    double d = 34.56; // A double (decimal number) variable
    // Several values can be chained with <<; they are printed left to right.
    // " " prints a space between them.
    std::cout << x << " " << c << " " << d << std::endl; // endl is used to print a new line
    // In C, printf("My favorite number is %d\n", x) is used to print a variable
    // In C++, cout << "My favorite number is " << x << std::endl; is used to print a variable
    // i.e. print the fixed text first, then the value of x, then a newline.
    std::cout << "My favorite number is " << x << std::endl;
    return 0; // Program ended successfully
}