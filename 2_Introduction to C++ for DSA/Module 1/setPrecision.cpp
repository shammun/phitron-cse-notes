#include <iostream> // This header file is used to perform input and output operations
#include <iomanip> // This header file is used to manipulate the output format of floating-point numbers
using namespace std; // This line allows us to use names for objects and variables from the standard library without the 'std::' prefix

int main(){
    double d = 23.45676;
    // In C, to print all 5 decimal places, printf("%.5f", d);
    // In C++, to print all 5 decimal places, cout << setprecision(5) << d;
    cout << fixed <<setprecision(5) << d << endl;
    // cout << fixed << setprecision(5) << d << endl;

    return 0;
}