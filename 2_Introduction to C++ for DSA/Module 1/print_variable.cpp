#include <iostream>

int main(){
    int x = 10;
    // In C, printf("%d", x) is used to print a variable
    // In C++, cout << x is used to print a variable
    std::cout << x; // printf("%d", x) is equivalent to cout << x

    char c = 'A';
    double d = 34.56;
    std::cout << x << " " << c << " " << d << std::endl; // endl is used to print a new line
    // In C, printf("My favorite number is %d\n", x) is used to print a variable
    // In C++, cout << "My favorite number is " << x << std::endl; is used to print a variable
    std::cout << "My favorite number is " << x << std::endl;
    return 0;
}