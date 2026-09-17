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

/*************  ✨ Codeium Command ⭐  *************/
// Comparator function to sort students in descending order based on marks.
// If two students have the same marks, it sorts them in ascending order based on roll number.

/******  3ca5df36-1515-457c-9670-8e79119c0330  *******/
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
    Student a[n];

    for(int i=0; i<n; i++){
        cin >> a[i].name >> a[i].roll >> a[i].marks;
    }

    sort(a, a+n, dsc);

    for(int i=0; i<n; i++){
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }

    return 0;

}