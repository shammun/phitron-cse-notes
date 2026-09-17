/*
There will be N number of students in the class.
Please sort the array of objects according to the marks. If there are same marks for some students,
then sort them according to the roll number.
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
    if(l.marks > r.marks){
        return true;
    } else if(l.marks < r.marks){
        return false;
    } else{
        return l.roll < r.roll;
    }
}

// efficient way to write the above function
bool dsc2(Student l, Student r){
    if(l.marks == r.marks){
        return l.roll < r.roll;
    } else{
        return l.marks > r.marks;
    }
}

// even more efficient implementation using ternary operator
bool dsc3(Student l, Student r){
    return (l.marks == r.marks) ? l.roll < r.roll : l.marks > r.marks;
}

// Comparator function to sort students in ascending order based on marks
bool dsc(Student l, Student r){
    if(l.marks < r.marks){
        return true;
    } else if(l.marks > r.marks){
        return false;
    } else{
        return l.roll > r.roll;
    }
}

int main(){
    // Name without space
    int n;
    cin >> n;
    Student a[n];

    for(int i=0; i<n; i++){
        cin >> a[i].name >> a[i].roll >> a[i].marks;
    }

    for(int i=0; i<n; i++){
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl;
    }

    return 0;
}