/*

Counting Elements

time limit per test: 1 second
memory limit per test: 256 megabytes

You are given an array a of n integers, count the number of element ai in the array 
such that ai+1 is also exists in the array a.

If there're duplicates in a, count them separately.

Input
The first line contains an integer n(1≤n≤10^3) the number of elements in the array a

The second line contains n integers ai(0≤Xi≤10^3) the elements of the array a.

Output
output the number of elements as descriped above.

Examples
Input
3
4 4 5
Output
2

Input
3
1 2 3
Output
2

Input
8
1 1 3 3 5 5 7 7
Output
0

Input
6
1 3 2 3 5 0
Output
3

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    /*
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[j] == a[i] + 1){
                count++;
            }
        }
    }

    cout << count << endl;
    */
    

    // Use count function
    int count2 = 0;
    for(int i=0; i<n; i++){
        if(find(a.begin(), a.end(), a[i] + 1) != a.end()){
            count2++;
        }
    }
    cout << count2 << endl;

    return 0;
}