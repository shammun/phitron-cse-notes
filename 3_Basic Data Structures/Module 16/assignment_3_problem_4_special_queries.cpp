/*

Problem Statement

You will be given  queries. In each query you will get a command. The command is of two types -

You will be given  and  of a person who stood in a line of a ticket counter.
You will be given only  which means the person in front of the line got the ticket and will be removed from the line. You need to print the name of that person who got that ticket. If there are no one in the line, print .
Note: There can be multiple person in the line with same name. You need to solve it using STL Stack or Queue only.

Input Format

First line will contain .
Next  lines will contain the commands.
Constraints

. Here |Name| means the length of the string and it will not contain any space. The string will contain only small English alphabets.
Output Format

For each time someone get out of the line, print his/her name. Print a new line after that.
Sample Input 0

5
0 rahim
0 karim
1
0 sakib
1
Sample Output 0

rahim
karim
Sample Input 1

8
1
0 embappe
0 neymar
1 
1
0 messi
1
1
Sample Output 1

Invalid
embappe
neymar
messi
Invalid
Sample Input 2

6
0 embappe
0 embappe
1 
1
0 messi
1
Sample Output 2

embappe
embappe
messi

*/

/*
 * Idea
 *
 * This is a ticket line: people join at the back (command 0 name) and the
 * person at the front is served and leaves (command 1). First come, first
 * served is exactly a queue. Duplicate names are no problem, because the
 * queue stores each arrival separately.
 *
 * For command 1 on an empty line, print "Invalid" instead of popping
 * (front() or pop() on an empty queue would crash).
 */

#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    queue<string> q;   // the line: front = next to be served

    while(n--){
        int x;;
        cin >> x;
        if(x == 0){
            // Command 0: a person joins the back of the line.
            string s;
            cin >> s;
            q.push(s);
        } else if(x == 1){
            // Command 1: serve the front person, if there is one.
            if(q.empty()){
                cout << "Invalid" << endl;
            } else{
                cout << q.front() << endl;
                q.pop();
            }
        }
    }

    return 0;
}