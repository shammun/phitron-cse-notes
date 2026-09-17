#include <iostream> // Include the input/output stream library for using cout
#include <string> // Include the string library for std::string
#include <climits> // Include the climits library for INT_MAX and INT_MIN
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

class Student{
    public:
    string name;
    int roll;
    int marks;
}; // Define a class named Student

int main(){
    // Name without space
    int n;
    cin >> n;
    Student a[n];

    // Getting the minimum marks

    for(int i=0; i<n; i++){
        cin >> a[i].name >> a[i].roll >> a[i].marks;
    }

    int min_marks = INT_MAX;
    for(int i=0; i<n; i++){
        min_marks = min(min_marks, a[i].name);
    }

    // Now, we want the object with the minimum marks
    Student min_obj;
    min_obj.marks = INT_MAX;

    for(int i=0; i<n; i++){
        if(a[i].marks < min_obj.marks){
            min_obj = a[i];
        }
    }
    cout << min_obj.name << " " << min_obj.roll << " " << min_obj.marks << endl;

    // Now, we want the object with the maximum marks
    Student max_obj;
    max_obj.marks = INT_MIN;

    for(int i=0; i<n; i++){
        if(a[i].marks > max_obj.marks){
            max_obj = a[i];
        }
    }
    cout << max_obj.name << " " << max_obj.roll << " " << max_obj.marks << endl;

    return 0; // Indicate that the program ended successfully
}