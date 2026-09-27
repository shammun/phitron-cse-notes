/*

Problem Statement

You will be given a list  of size . The list will contain data of some students
where each student have Name, Roll and Marks. Then you will be given Q queries, for
each query there will be some commands. Commands are given below -

1. 0 X -> Insert X into the list where X is the data of a student which contain
 Name, Roll, and Marks. Then print the current student's data who has the maximum
 Marks from the list.
2. 1 -> Print the current student's data who has the maximum  from the list.
3. 2 -> Delete the student who has the maximum  from the list and print the current
student who has the maximum  from the list.

Note: If there are multiple students with same  then we will select whose  is smaller. If the list is empty and you can't print anything then you should print "Empty".

Input Format
- First line will contain N.
- Next  lines will contain Name, Roll and Marks of student A[i].
- Third line will contain Q.
- Next  lines will contain the commands.

Constraints
1. 1 <= N + Q <= 10^5
2. 1 <= |Name| <= 1000, Name will contain only English lowercase letters and will
not contain any spaces.
3. 0 <= Roll <= 10^5
4. 0 <= Marks <= 100

Output Format
- For each command, print as asked from the list.

Sample Input 0
3
akib 23 95
jobbar 24 99
ali 25 100
8
1
2
2
2
0 kabir 15 65
0 asif 55 65
2
0 tamim 35 65

Sample Output 0
ali 25 100
jobbar 24 99
akib 23 95
Empty
kabir 15 65
kabir 15 65
asif 55 65
tamim 35 65

*/

#include <bits/stdc++.h>

using namespace std;



/*
 * Idea: the same three commands as Question 4, but the heap holds students
 * and "the best" is decided by our own compare class:
 *   - more marks first (a max-heap on marks);
 *   - on equal marks, the smaller roll first.
 *
 * Reading cmp: operator()(l, r) returns true when l should come out AFTER r.
 *   l.marks < r.marks -> true : fewer marks waits.
 *   l.roll  > r.roll  -> true : on a marks tie, the bigger roll waits.
 */

// One student's record.
class Student{
    public:
        string name;
        int roll;
        int marks;

        Student(string name, int roll, int marks){
            this->name = name;
            this->roll = roll;
            this->marks = marks;
        }
};


class cmp{
    public:
        bool operator()(Student &l, Student &r){
            // Different marks: the lower mark has lower priority.
            if(l.marks < r.marks){
                return true;
            } else if(l.marks > r.marks){
                return false;
            } else {
                // Same marks: the bigger roll has lower priority.
                return l.roll > r.roll;
            }
        }
};

int main(){
    // The top of pq is always the student the question wants printed.
    priority_queue<Student, vector<Student>, cmp> pq;
    int N;
    cin >> N;

    // Read the starting list of students into the heap.
    for(int i=0; i<N; i++){
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }

    int Q;
    cin >> Q;

    for(int i=0; i<Q; i++){
        // The command number: 0, 1 or 2.
        int x;
        cin >> x;

        // 0 name roll marks: add the student, then show the top student.
        if(x == 0){
            string name2;
            int roll2, marks2;
            cin >> name2 >> roll2 >> marks2;
            Student obj2(name2, roll2, marks2);
            pq.push(obj2);
            cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        }
        // 1: show the top student, or Empty.
        if(x == 1){
            if(!pq.empty()){
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
            } else {
                cout << "Empty" << endl;
            }

        }
        // 2: remove the top student, then show the new top (check for an
        // empty heap both before popping and after it).
        if(x == 2){
            if(pq.empty()){
                cout << "Empty" << endl;
                continue;
            }

            pq.pop();
            if(pq.empty()){
                cout << "Empty" << endl;
            } else {
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
            }
        }
    }


    return 0;
}
