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

#include <iostream>     // cin, cout, endl, getline
#include <string>       // std::string, a text value that can grow
#include <list>         // std::list, the STL doubly linked list
#include <sstream>      // std::stringstream, reads words out of a string like cin does
using namespace std;    // write string/list/cout without std::

// Handles ONE query line. Web = the list of addresses (by reference &, so it is not
// copied every call). curr = ADDRESS of main's `curr` string: writing *curr = ...
// changes main's variable, so the new position is remembered between queries.
void browse_history(list<string> &Web, string* curr){
    // Read the whole command line, then split it into words.
    string line;
    getline(cin, line);         // reads everything up to (and removes) the newline
    stringstream ss(line);      // treat the line as a small input stream
    string command;
    ss >> command;              // first word: "visit", "next" or "prev"

    if(command == "visit"){     // == on strings compares the text
        string address;
        ss >> address;          // second word: the address to go to
        bool found = false;   // stays false if the address is not in the list

        // Range-for: s takes a copy of each address, front to back.
        for(string s: Web){
            if(s == address){
                found = true;
                *curr = s;      // move there: update main's curr through the pointer
                break;          // addresses are unique, stop searching
            }
        }

        // Print the new position, or refuse and stay where we were.
        if(found){
            cout << *curr << endl;      // *curr = the string the pointer points to
        } else{
            cout << "Not Available" << endl;
        }

    } else if(command == "next"){

        // Becomes true once we have walked past our current address.
        bool previous_word_found = false;

        for(string s: Web){
            if(previous_word_found){
                *curr = s; // set the current pointer to this new next word after the previous current word
                cout << *curr << endl;
                return;     // done with this query
            }
            // s is our current address, so the element in the NEXT round is the answer.
            if(s == *curr){
                previous_word_found = true;
            }
        }
        // The loop ended without returning: curr was the last address.
        cout << "Not Available" << endl;

    } else if(command == "prev"){

        // Already on the first address: there is no previous one.
        string prev = Web.front();  // front() = the first element's value
        if(*curr == prev){
            cout << "Not Available" << endl;
            return;                 // stay where we are
        }

        // Walk with `prev` always holding the element seen just before s.
        for(string s: Web){
            if(s != *curr){
                // Not our position yet: remember s as the candidate `prev`.
                prev = s;
            } else{
                // We reached our current address, so move BACK: the current
                // position becomes `prev`, the address seen just before it.
                *curr = prev;
                cout << *curr << endl;
                return;
            }
        }
        // Trace list facebook google phitron, curr = phitron: prev = facebook, google,
        // then s == phitron -> curr = google, print google.
    }
}

int main(){
    list<string> Web;       // the addresses, in order
    string s;

    // Read addresses until the word "end".
    // `while(cin >> s)` reads one word per pass (words are split at spaces) and
    // stops if input runs out.
    while(cin >> s){
        if(s=="end"){       // the terminator, not an address
            break;
        }
        Web.push_back(s);   // append at the end
    }

    int Q;
    cin >> Q;               // number of queries
    // Skip the newline after Q, or the first getline would read an empty line.
    // (cin >> leaves the '\n' in the input; getline stops at the first '\n' it sees.)
    cin.ignore();

    // We start on the first address (the head).
    string curr = Web.front();

    // Q-- tests Q then decreases it, so the loop runs Q times.
    while(Q--){
        browse_history(Web, &curr);     // &curr = address of curr, so the function can change it
    }

    return 0;               // normal exit

}