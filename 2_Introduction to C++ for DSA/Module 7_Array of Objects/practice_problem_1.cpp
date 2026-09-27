/*

Question: Make a class named Student. Write a program to take a positive integer N as input and make an Student array of size N. 
Student 
{
	name;
	roll;
	marks;
}
Your task is to sort the Students data according to the marks in descending order. If multiple students have the same marks 
then sort them according to the roll in ascending order as the roll will be unique.
Note: name will not contain any spaces.

Input:
5
Asif 29 95
Sakib 55 89
Zubair 57 93
Ahsan 39 86
Joy 12 99

Output:
Joy 12 99
Asif 29 95
Zubair 57 93
Sakib 55 89
Ahsan 39 86

Input:
5
Asif 29 95
Sakib 55 86
Zubair 57 86
Ahsan 39 86
Joy 12 99

Output:
Joy 12 99
Asif 29 95
Ahsan 39 86
Sakib 55 86
Zubair 57 86

*/

#include <iostream> // Include the input/output stream library for using cout
#include <string> // Include the string library for std::string
#include <climits> // Include the climits library for INT_MAX and INT_MIN
#include <algorithm> // Include the algorithm library for sort function
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

class Student{
    public:
    string name;
    int roll;
    int marks;
}; // Define a class named Student

// Comparator for sort(): it is handed two students, l (left) and r (right),
// and returns true when l should come BEFORE r in the sorted array.
// - Different marks: the higher mark goes first (descending), so l.marks > r.marks.
// - Same marks: the smaller roll goes first (ascending), so l.roll < r.roll.
// sort() cannot compare two Student objects by itself, which is why this function is needed.
bool dsc(Student l, Student r){
    if(l.marks == r.marks){
        return l.roll < r.roll;
    } else{
        return l.marks > r.marks;
    }
}

int main(){
    int n;
    cin >> n;
    Student a[n]; // an array of n Student objects

    for(int i=0; i<n; i++){
        cin >> a[i].name >> a[i].roll >> a[i].marks; // names have no spaces, so cin >> is enough
    }

    // Sort the whole array; the third argument is the comparator's name, and
    // sort() calls it whenever it needs to know which of two students goes first
    sort(a, a+n, dsc);

    for(int i=0; i<n; i++){
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }

    return 0;

}