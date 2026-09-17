/*
There will be N number of students in the class.
Please sort the array of objects according to the marks. So, the student with the highest 
marks will be in the first index, and student with the lowest marks will be the the last index of the array.
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

// Comparator function to sort students in descending order based on marks
bool dsc(Student l, Student r){
    return l.marks > r.marks;
}

// Comparator function to sort students in ascending order based on marks
bool asc(Student l, Student r){
    return l.marks < r.marks;
}

int main(){
    // Name without space
    int n;
    cin >> n;
    Student a[n];

    for(int i=0; i<n; i++){
        cin >> a[i].name >> a[i].roll >> a[i].marks;
    }
    
    // Descending order
    sort(a, a+n, dsc);
    
    for(int i=0; i<n; i++){
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }

    // Ascending order
    sort(a, a+n, asc);
    for(int i=0; i<n; i++){
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }

    return 0; // Indicate that the program ended successfully
}

/*

Input:
6
Rakib 3 76
Sakib 2 80
Maruf 1 99
Nakib 4 60
Nakib 5 50
Ropon 6 45
*/