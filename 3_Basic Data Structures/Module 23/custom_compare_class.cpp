#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

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
        bool operator()(Student l, Student r){
            if(l.marks < r.marks){ // Descending order here not ascending order -- higher marks will come first
                return true;
            } else if(l.marks > r.marks){
                return false;
            } else {
                return l.roll > r.roll; // Ascending order, smaller rolls will come first
            } 
        }
};
int main(){
    priority_queue<Student, vector<Student>, cmp> pq;
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }

    while(!pq.empty()){
        cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        pq.pop();
    }

}