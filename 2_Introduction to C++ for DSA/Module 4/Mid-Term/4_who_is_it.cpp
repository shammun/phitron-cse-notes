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

// One object holds everything about one student.
// A class is a blueprint for a new type: it lists the data (members) every
// object of that type will have. Each Student object gets its own copy of them.
class Student{
    public: // "public:" = the members below can be used from outside the class (e.g. from main)
    int id;         // the student's ID (1..3)
    // BUG (edge case): a name can be 100 letters and needs one more slot for the
    // '\0' end mark, so a 100-letter name would write past the end of name[100]
    // (same for name1/name2/name3 in main). Fix: make these arrays size 101.
    // Names up to 99 letters, like the sample ones, fit fine.
    char name[100]; // the name as a C-style string (letters followed by '\0')
    char section;   // one capital letter, 'A'..'Z'
    int marks;      // total marks, 0..100

    // Constructor: fills a new object in one line, e.g. Student s1(1, "sakib", 'A', 50).
    // this->id is the object's member; plain id is the parameter with the same name.
    // A constructor has the same name as the class and no return type; it runs
    // automatically whenever an object is created.
    // `this` is a pointer to the object being built, and -> reaches a member through a pointer.
    Student(int id, char* name, char section, int marks){
        this->id = id; // copy the parameter id into the object's id
        // Arrays cannot be copied with =, so strcpy(destination, source) copies the
        // characters of name (including the final '\0') into this object's name array.
        strcpy(this->name, name);
        this->section = section; // copy the section letter
        this->marks = marks;     // copy the marks
    }
};

int main(){ // program starts here
    int T;     // number of test cases
    cin >> T;  // read T
    // One answer per test case is stored here and printed at the end.
    // T can be up to 1000, so the array needs 1000 slots.
    // Each slot is a Student* (a pointer to a Student), not a Student itself:
    // Student has no "empty" constructor, so an array of plain Student objects
    // could not be created without values.
    Student* students[1000];
    // One pass = one test case = three students read, best one saved in students[i]
    for(int i=0; i<T; i++){
        int id1, marks1;           // first student's ID and marks
        char name1[100], section1; // first student's name and section
        // cin >> reads one space-separated piece at a time: a number, a word (into
        // the char array), a single char, then a number.
        cin >> id1 >> name1 >> section1 >> marks1;

        int id2, marks2;           // second student's ID and marks
        char name2[100], section2; // second student's name and section
        cin >> id2 >> name2 >> section2 >> marks2; // read the second line

        int id3, marks3;           // third student's ID and marks
        char name3[100], section3; // third student's name and section
        cin >> id3 >> name3 >> section3 >> marks3; // read the third line

        // Build three objects from what was read (each call runs the constructor)
        Student s1(id1, name1, section1, marks1);
        Student s2(id2, name2, section2, marks2);
        Student s3(id3, name3, section3, marks3);

        // Start with s1 as the best and let s2 and s3 challenge it.
        // A challenger wins with more marks, or with equal marks and a smaller ID
        // (the tie rule from the question). `best = s2` copies the whole object.
        // Trace for test 2: best=sakib(50); rakib 96>50 -> best=rakib;
        // akib 96==96 but id 3 is not < 2 -> rakib stays.
        Student best = s1;

        // || means "or", && means "and"
        if(s2.marks > best.marks || (s2.marks == best.marks && s2.id < best.id)){
            best = s2; // s2 beats the current best
        }
        if(s3.marks > best.marks || (s3.marks == best.marks && s3.id < best.id)){
            best = s3; // s3 beats the current best
        }

        // Keep a heap copy of the winner so it is still there after this loop step.
        // new Student(...) creates an object on the heap, runs the constructor,
        // and returns its address; the address is stored in students[i].
        // (best, s1, s2, s3 are destroyed at the end of every loop pass.)
        students[i] = new Student(best.id, best.name, best.section, best.marks);
    }

    // Print every stored winner; -> reaches a member through a pointer
    // (students[i]->id means (*students[i]).id: go to the object, take its id).
    for(int i=0; i<T; i++){
        cout << students[i]->id << " " << students[i]->name << " " << students[i]->section << " " << students[i]->marks << endl;
        delete students[i]; // each new needs its delete
    }

    return 0; // program ended normally
}