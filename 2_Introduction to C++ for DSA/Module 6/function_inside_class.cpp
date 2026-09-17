#include<iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
#include <sstream> // Include the stringstream library for string stream operations
#include <algorithm> // Include the algorithm library for sort function
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

class Student{
    public:
    string name;
    int roll;
    int math;
    int english;
    Student(string name, int roll, int math, int english){
        this->name = name;
        this->roll = roll;
        this->math = math;
        this->english = english;
    }
    void hello(){
        cout << "Hello from " << name << endl;
        cout << "Total marks of " << name << " is " << math + english << endl;
    }
};

int main() {
    Student shammunul("Shammunul Islam", 1, 99, 85);
    cout << shammunul.name << " " << shammunul.roll << endl;
    shammunul.hello();
    Student milon("Milon Miah", 10, 85, 71);
    cout << milon.name << " " << milon.roll << endl;
    milon.hello();
    return 0;
}