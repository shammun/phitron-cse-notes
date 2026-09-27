/*

A priority queue of your own objects: the compare class

`priority_queue<int>` knows how to order numbers. It cannot know how to order
Students, so you hand it a small class with one job: given two Students, say
which of them is the lesser. That class goes in as the third template
argument:

    priority_queue<Student, vector<Student>, cmp> pq;
      (what it stores) (how it stores it) (how it compares)

Why the comparison reads backwards compared with sort
-----------------------------------------------------
Both `sort` and `priority_queue` take a "less than" test, but they use the
answer for different things.

  sort  puts the LESSER element FIRST. So `l.marks < r.marks` sorts from low
        marks to high marks -- ascending, exactly as it reads.

  priority_queue is a heap, and a heap always shows the GREATEST element at
        top(). So the element your test calls lesser is the one that sinks
        and comes out LAST. With the same line `l.marks < r.marks`, low marks
        sink and the highest marks come out first -- descending.

Same line of code, opposite-looking result. Nothing is reversed inside the
container; it is simply that sort reports from the small end while a priority
queue reports from the big end. The habit that helps: read
`operator()(l, r) == true` as "l loses to r, so l comes out after r".

Tie-break
---------
When the marks are equal the test falls through to the rolls, and there the
same reasoning applies: `l.roll > r.roll` says the bigger roll loses, so among
students with equal marks the smaller roll comes out first.

Cost: push and pop are O(log n), top is O(1), so printing everyone in order
is O(n log n).

*/

#include<iostream>      // cin and cout
#include <vector>       // vector (the container inside the priority queue)
#include <queue>        // priority_queue
#include <algorithm>    // not used here
#include <string>       // string, for the names

using namespace std;    // write cout, string, priority_queue ... without std::

// One student: a name, a roll number and marks.
class Student{
    public:                 // usable from outside the class
        string name;
        int roll;
        int marks;

        // Constructor: `Student obj(name, roll, marks);` runs this.
        // this->name is the member; plain name is the parameter.
        Student(string name, int roll, int marks){
            this->name = name;
            this->roll = roll;
            this->marks = marks;
        }
};


/* The compare class. A class with an `operator()` can be called like a
   function -- `cmp()(a, b)` -- which is what the priority queue does every
   time it moves an element. It returns true when `l` should sit lower in the
   heap than `r`, i.e. when l comes out after r. */
class cmp{
    public:
        // l and r are two students the heap wants to compare.
        bool operator()(Student l, Student r){
            if(l.marks < r.marks){ // Higher marks come out of the priority queue first (descending by marks)
                return true;       // l has fewer marks -> l loses -> l sinks
            } else if(l.marks > r.marks){
                return false;      // l has more marks -> l wins -> l rises
            } else {
                return l.roll > r.roll; // Ascending order, smaller rolls will come first
                                        // equal marks: the bigger roll loses
            }
        }
};
int main(){
    // The three template arguments: the type stored, the container that
    // holds the heap, and the comparison class above.
    priority_queue<Student, vector<Student>, cmp> pq;
    int n;
    cin >> n;               // number of students

    // Read n students and push them in any order -- the heap sorts itself
    // out as they arrive, O(log n) per push.
    for(int i=0; i<n; i++){
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;       // e.g. "rahim 3 90"
        Student obj(name, roll, marks);     // build the Student with the constructor
        pq.push(obj);                       // a copy goes into the heap
    }

    // top() is the winner by the rule above: highest marks, and on a tie the
    // smaller roll. Pop it and the next winner surfaces, so this prints the
    // whole class in order. `!pq.empty()` is the usual guard -- top() and
    // pop() on an empty priority queue are undefined.
    while(!pq.empty()){
        cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        pq.pop();           // remove the student just printed
    }

    // No `return 0;`: main may leave it out and then returns 0 automatically.
}
