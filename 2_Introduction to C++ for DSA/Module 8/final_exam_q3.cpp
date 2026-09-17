/*

Replace Word

Problem Statement

You will be given two strings S and X. You need to replace all X from string S with a '#' sign.

Input Format

First line will contain T, the number of test cases.
Next T lines will contain a line with S and X.
Constraints

1 <= T <= 1000
1 <= |S|, |X| <= 1000
|X| <= |S|
Output Format

For each test cases output the modified string S.
Sample Input 0

2
rahimisagoodguy good
canyoutellmewhereicanfindheriwillbegreatefultoyouifyoutellmetheanswer you
Sample Output 0

rahimisa#guy
can#tellmewhereicanfindheriwillbegreatefulto#if#tellmetheanswer

*/

#include <iostream>
#include <string>
using namespace std;

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

    Student a[n];

    for(int i=0; i<n; i++){
        cin >> a[i].nm;
        cin >> a[i].cls;
        cin >> a[i].s;
        cin >> a[i].id;
    }

    // reverse section by swapping the first half with the second half
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