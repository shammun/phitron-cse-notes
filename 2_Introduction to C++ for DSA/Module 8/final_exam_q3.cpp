/*

Final exam question 3 - reverse the sections

(The statement was not saved with this file; this is what the code solves.)
Read N students, each with a name (nm), a class (cls), a section letter (s)
and an id. Everything stays where it is except the sections: the section
column is reversed, so the first student gets the last student's section,
the second gets the second-last one's, and so on. Print the students in the
original order with their new sections.

Example (made up to show the idea)
Input
3
rahim 5 A 11
karim 6 B 12
jodu 7 C 13
Output
rahim 5 C 11
karim 6 B 12
jodu 7 A 13

*/

#include <iostream> // cin and cout
#include <string>   // std::string
using namespace std; // write cin/cout/string instead of std::cin/...

// One object holds one student's data
class Student{
    public:
    string nm;
    int cls;
    char s;
    int id;
};

int main(){
    int n;
    cin >> n;

    Student a[n]; // an array of n Student objects

    for(int i=0; i<n; i++){
        cin >> a[i].nm;
        cin >> a[i].cls;
        cin >> a[i].s;
        cin >> a[i].id;
    }

    // reverse section by swapping the first half with the second half.
    // Only the member .s moves; names, classes and ids stay in place.
    // Student i pairs with student n-1-i; stop at the middle, or each pair
    // would be swapped twice and nothing would change.
    for(int i=0; i<n/2; i++){
        char temp = a[i].s;
        a[i].s = a[n-i-1].s;
        a[n-i-1].s = temp;
    }

    for(int i=0; i<n; i++){
        cout << a[i].nm << " " << a[i].cls << " " << a[i].s << " " << a[i].id << endl;
    }

    return 0;
}