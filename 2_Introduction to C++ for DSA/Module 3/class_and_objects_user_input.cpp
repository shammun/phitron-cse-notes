#include<iostream>
#include<string.h>
using namespace std;
class Student{
    public:
    char name[100]; // 100 bytes
    int roll; // 4 bytes
    double gpa; // 8 bytes
};

int main(){
    Student a, b;

    cin >> a.name >> a.roll >> a.gpa;
    cin >> b.name >> b.roll >> b.gpa;

    cout << a.name << " " << a.roll << " " << a.gpa << endl;
    cout << b.name << " " << b.roll << " " << b.gpa << endl;

    return 0;
}