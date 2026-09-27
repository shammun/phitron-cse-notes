/*

Problem Statement

You are given a doubly linked list of unique string values. These strings refer to web 
addresses without any spaces. You will be given Q queries. In each query you will be given 
some commands. Type of commands are -

visit address - You need to go to that address from where you are in that list and print 
that address if it is in the list. Otherwise print "Not Available".
next - You need to go to the next address from where you are in that list and print that 
address if it is in the list. Otherwise print "Not Available".
prev - You need to go to the previous address from where you are in that list and print that 
address if it is in the list. Otherwise print "Not Available".
One more thing, if the address isn't available make sure you don't move from your current 
position. You are at the head initially.

Note: You can use Singly/Doubly Linked List or STL List to solve this problem.

Input Format

First line will contain the values of the doubly linked list, and will terminate with the 
string "end".
Second line will contain Q.
Next Q lines will contain the commands. It is guranteed that you will get "visit address" 
command at first which will contain a valid address. It will not contain valid address 
everytime!

Constraints
- 1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
- 1 <= Q <= 1000;
- 1 <= |Address| <= 100; Here |Address| is the length of the string address.

Output Format
For each query output as asked.

Sample Input 0
facebook google phitron youtube twitter end
12
visit phitron
prev
prev
prev
prev
next
visit twitter
next
next
prev
visit django
prev

Sample Output 0
phitron
google
facebook
Not Available
Not Available
google
twitter
Not Available
Not Available
youtube
Not Available
phitron

Sample Input 1
a b c d e f g h i j k l m n o p q r s t u v w x y z end
7
visit s
next
visit zz
next
visit z
next
prev

Sample Output 1
s
t
Not Available
u
z
Not Available
y

*/

/*
 * The idea: keep the addresses in a `list<string>` and remember where we are
 * with `curr`, the address we are on now. `curr` is passed as a pointer
 * (`string* curr`) so that the function can change the caller's variable.
 *
 * Each query is one whole line, so it is read with getline and then split
 * with a stringstream: the first word is the command, and for `visit` the
 * second word is the address.
 *
 *   visit A : walk the list looking for A. Found -> it becomes `curr`.
 *             Not found -> print Not Available and stay put.
 *   next    : walk until we pass `curr`; the element after it is the answer.
 *             If `curr` was the last element, the loop ends: Not Available.
 *   prev    : if `curr` is the first element there is nothing before it.
 *             Otherwise walk while remembering the element just seen in
 *             `prev`; when we reach `curr`, `prev` is the one before it.
 *
 * The addresses are unique, so "find the element equal to curr" always finds
 * our own position. Every command walks the list: O(n) per query.
 */

#include <iostream>
#include <string>
#include <list>
#include <sstream>
using namespace std;

void browse_history(list<string> &Web, string* curr){
    // Read the whole command line, then split it into words.
    string line;
    getline(cin, line);
    stringstream ss(line);
    string command;
    ss >> command;

    if(command == "visit"){
        string address;
        ss >> address;
        bool found = false;   // stays false if the address is not in the list
        
        for(string s: Web){
            if(s == address){
                found = true;
                *curr = s;
                break;
            }
        }

        // Print the new position, or refuse and stay where we were.
        if(found){
            cout << *curr << endl;
        } else{
            cout << "Not Available" << endl;
        }
    
    } else if(command == "next"){
        
        bool previous_word_found = false;

        for(string s: Web){
            if(previous_word_found){
                *curr = s; // set the current pointer to this new next word after the previous current word
                cout << *curr << endl;
                return;
            }
            // current word is the same as the previous word and so set the previous word found to be true
            if(s == *curr){
                previous_word_found = true;
            }
        }
        cout << "Not Available" << endl;
    
    } else if(command == "prev"){
        
        // Already on the first address: there is no previous one.
        string prev = Web.front();
        if(*curr == prev){
            cout << "Not Available" << endl;
            return;
        }

        for(string s: Web){
            if(s != *curr){
                // update the previous word to the next word as it has not matched the current word yet
                prev = s;
            } else{
                // if the current word is found, then set the previous word to the current word
                *curr = prev;
                cout << *curr << endl;
                return;
            }
        }
    }
}

int main(){
    list<string> Web;
    string s;

    // Read addresses until the word "end".
    while(cin >> s){
        if(s=="end"){
            break;
        }
        Web.push_back(s);
    }

    int Q;
    cin >> Q;
    // Skip the newline after Q, or the first getline would read an empty line.
    cin.ignore();

    // We start on the first address (the head).
    string curr = Web.front();

    while(Q--){
        browse_history(Web, &curr);
    }

    return 0;

}