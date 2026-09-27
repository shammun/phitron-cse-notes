/*

Problem Statement

A student has several pieces of information, such as a unique ID, name, section, and total marks. You will be given the information of three students. Your task is to determine and print the details of the student who achieved the highest total marks. In the case of a tie (i.e., two or more students having the same total marks), print the information of the student with the smaller ID.

Input Format

First line will contain T, the number of test cases.
For each test case there will be 3 lines. Each line will contain - ID, Name, Section, Total Marks of a student. The name will contain lowercase English alphabets only.
Constraints

1 <= T <= 1000
1 <= ID <= 3
1 <= |Name| <= 100
'A' <= Section <= 'Z'
0 <= Total Marks <= 100
Output Format

Ouptut the information as asked in the question.
Sample Input 0

3
1 sakib A 50
2 rakib D 96
3 akib C 90
1 sakib A 50
2 rakib D 96
3 akib C 96
1 sakib A 50
2 rakib D 50
3 akib C 40
Sample Output 0

2 rakib D 96
2 rakib D 96
1 sakib A 50

*/

#include <iostream> // cin and cout
#include <string.h> // strcpy(), to copy a name into a char array
using namespace std; // write cin/cout instead of std::cin/std::cout

// One object holds everything about one student
class Student{
    public:
    int id;
    char name[100];
    char section;
    int marks;

    // Constructor: fills a new object in one line, e.g. Student s1(1, "sakib", 'A', 50).
    // this->id is the object's member; plain id is the parameter with the same name.
    Student(int id, char* name, char section, int marks){
        this->id = id;
        strcpy(this->name, name);
        this->section = section;
        this->marks = marks;
    }
};

int main(){
    int T;
    cin >> T;
    // One answer per test case is stored here and printed at the end.
    // T can be up to 1000, so the array needs 1000 slots.
    Student* students[1000];
    for(int i=0; i<T; i++){
        int id1, marks1;
        char name1[100], section1;
        cin >> id1 >> name1 >> section1 >> marks1;

        int id2, marks2;
        char name2[100], section2;
        cin >> id2 >> name2 >> section2 >> marks2;

        int id3, marks3;
        char name3[100], section3;
        cin >> id3 >> name3 >> section3 >> marks3;

        // Build three objects from what was read
        Student s1(id1, name1, section1, marks1);
        Student s2(id2, name2, section2, marks2);
        Student s3(id3, name3, section3, marks3);
        
        // Start with s1 as the best and let s2 and s3 challenge it.
        // A challenger wins with more marks, or with equal marks and a smaller ID
        // (the tie rule from the question). `best = s2` copies the whole object.
        Student best = s1;

        if(s2.marks > best.marks || (s2.marks == best.marks && s2.id < best.id)){
            best = s2;
        }
        if(s3.marks > best.marks || (s3.marks == best.marks && s3.id < best.id)){
            best = s3;
        }

        // Keep a heap copy of the winner so it is still there after this loop step
        students[i] = new Student(best.id, best.name, best.section, best.marks); 
    }

    // Print every stored winner; -> reaches a member through a pointer
    for(int i=0; i<T; i++){
        cout << students[i]->id << " " << students[i]->name << " " << students[i]->section << " " << students[i]->marks << endl;
        delete students[i]; // each new needs its delete
    }

    return 0;
}