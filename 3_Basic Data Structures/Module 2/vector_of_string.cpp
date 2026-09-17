/*

In this tutorial, we will learn about vector of string.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    // We can create a vector of string also and also of any data type

    // A string vector with values initialized
    vector<string> v = {"Rahim", "Karim", "Sohan", "Mohan", "Lipon", "Sakib"};

    
    // A string vector without values initialized
    // A string vector with the size declared only
    // We will take the size of the vector from the user and then input the elements
    int n;
    cin >> n;
    vector<string> v2(n); // vector of size n with all elements initialized to empty string
    for(int i=0; i<n; i++){
        cin >> v2[i];
    }

    for(int i=0; i<n; i++){
        cout << v2[i] << " ";
    }
    cout << endl;

    // Another way to print the vector
    for(string s: v2){
        cout << s << " ";
    }
    cout << endl;

    // Now, we will learn about inserting strings with spaces into the vector
    // We will use getline() function to input the strings with spaces

    cin.ignore(); // ignore the newline character
    int n2;
    cin >> n2;
    cin.ignore(); // ignore the newline character
    vector<string> v3(n);
    
    for(int i=0; i<n2; i++){
        getline(cin, v[i]);
    }

    for(string s: v3){
        cout << s << endl;
    }

    return 0;
}

/*

Input:
5
Rahim
Karim
Sohan
Mohan
Lipon
5
Sakib Khan
Rakib Hasan
Rafi Khan
Shakib Al Hasan
Tamim Iqbal

Output:
Rahim Karim Sohan Mohan Lipon 
Rahim Karim Sohan Mohan Lipon 
Sakib Khan 
Rakib Hasan 
Rafi Khan 
Shakib Al Hasan 
Tamim Iqbal
*/