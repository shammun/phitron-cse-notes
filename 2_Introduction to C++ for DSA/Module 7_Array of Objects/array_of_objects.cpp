#include <iostream> // Include the input/output stream library for using cout
#include <string> // Include the string library for std::string

using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

class Student{
    public:
    string name;
    int roll;
    int marks;
}; // Define a class named Student

int main(){
    int n;
    cin >> n; // Take input from the user
    Student a[n]; // Create an array of objects of class Student
    for(int i=0; i<n; i++){
        cin >> a[i].name >> a[i].roll >> a[i].marks; // Take input for the array of objects
    }

    for(int i=0; i<n; i++){
        cout << a[i].name << " " << a[i].roll << " " << a[i].marks << endl; // Print the array of objects
    }

    // Objec's name with space
    int n2;
    cin >> n2;
    Student a2[n2];
    for(int i=0; i<n2; i++){
        cin.ignore();
        getline(cin, a2[i].name);
        cin >> a2[i].roll >> a2[i].marks;
    }

    for(int i=0; i<n2; i++){
        cout << a2[i].name << " " << a2[i].roll << a2[i].marks << endl;
    }

    return 0; // Indicate that the program ended successfully
}