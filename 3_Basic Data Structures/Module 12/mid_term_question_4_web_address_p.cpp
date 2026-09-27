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

// Practice copy of mid_term_question_4_web_address.cpp; the list is called
// `web` here. One line is missing in the `prev` branch (see the note there).

#include <iostream>     // cin, cout, endl, getline
#include <string>       // std::string
#include <list>         // std::list, the STL doubly linked list
#include <sstream>      // std::stringstream, splits a string into words like cin

using namespace std;    // write string/list/cout without std::

// Handles ONE query line. web is passed by reference (&) so it is not copied;
// curr is a POINTER to main's current-address string, so *curr = ... updates main.
void browse_history(list<string> &web, string* curr){
    // Read the whole command line, then split it into words.
    string line;
    getline(cin, line);         // the full line, newline removed
    stringstream ss(line);      // a stream over that line
    string command;
    ss >> command;              // first word of the line

    if(command == "visit"){
        string address;
        ss >> address;          // second word: where to go
        bool found = false;   // stays false if the address is not in the list

        // Range-for: s is a copy of each address, front to back.
        for(string s : web){
            if(s == address){
                found = true;
                *curr = s;      // move there (writes main's curr)
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
        bool previous_word_found = false;   // true once we pass our position

        for(string s : web){
            // The element right after `curr` is the next address.
            if(previous_word_found){
                *curr = s;
                cout << *curr << endl;
                return;         // query done
            }

            // Found our position: the element in the next round is the answer.
            if(s == *curr){
                previous_word_found = true;
            }
        }
        cout << "Not Available" << endl;    // curr was the last address
    } else if(command == "prev"){
        // Already on the first address: there is no previous one.
        string prev = web.front();          // value of the first element
        if(*curr == prev){
            cout << "Not Available" << endl;
            // BUG: a `return;` is missing here, so the loop below
            // still runs. Its first s equals *curr, so it prints the first address
            // as well: the output is "Not Available" AND e.g. "facebook".
            // Fix: add `return;` on this line.
        }

        // Walk with prev = the element seen just before s.
        for(string s : web){
            // Not our position yet: remember it as the candidate `prev`.
            if(s != *curr){
                prev = s;
            } else {
                *curr = prev;   // reached our position: step back to prev
                cout << *curr << endl;
                return;
            }
        }
    }
}

int main(){
    list<string> web;       // the addresses in order
    string s;

    // Read addresses until the word "end".
    // cin >> s reads one space-separated word per pass.
    while(cin >> s){
        if(s == "end"){
            break;
        }
        web.push_back(s);   // append at the end
    }

    int Q;
    cin >> Q;               // number of queries
    // Skip the newline after Q, or the first getline would read an empty line.
    cin.ignore();           // throws away one leftover character (the newline)

    // We start on the first address (the head).
    string curr = web.front();

    // Runs Q times.
    while(Q--){
        browse_history(web, &curr);     // pass curr's address so it can be changed
    }

    return 0;               // normal exit
}