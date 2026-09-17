/*
This program will ask users for a number and will sum all the numbers from 1 to that number.
*/

#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;
    cout << "Enter a number: ";
    cin >> num;
    /*
    for(int i=1; i<=num; i++){
        sum += i;
    }
    */

    // Using the formula for sum of n numbers
    sum = (num * (num + 1)) / 2;
    
    cout << "Sum of numbers from 1 to " << num << " is " << sum << endl;

    return 0;
}