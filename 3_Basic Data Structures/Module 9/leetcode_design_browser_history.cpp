/*

Design Browser History   (LeetCode 1472)
https://leetcode.com/problems/design-browser-history/

Build the history of one browser tab. The tab starts on a home page. Then:

  visit(url)      go to `url` from the page you are on now. Every page that
                  was ahead of you (the ones you could have reached with
                  forward) is thrown away, exactly like a real browser.
  back(steps)     move back up to `steps` pages. If there are fewer pages
                  behind you, stop at the oldest one. Return the page you
                  end up on.
  forward(steps)  the same in the other direction. Return the page you end
                  up on.

A doubly linked list is the natural shape here: `prev` is the page behind,
`next` is the page ahead, and one pointer (`current`) says where you are.

Input (for this program, so it can be run here)
First line: the home page.
Second line: q, the number of commands.
Then q lines, one command each:

  visit <url>
  back <steps>
  forward <steps>

Output
One line for every `back` and `forward`: the page you are on after the move.
`visit` prints nothing, just like the real method returns nothing.

Constraints
A url is one word (no spaces). `steps` is at least 1.

Example

input
leetcode.com
10
visit google.com
visit facebook.com
visit youtube.com
back 1
back 1
forward 1
visit linkedin.com
forward 2
back 2
back 7

output
facebook.com
google.com
facebook.com
linkedin.com
google.com
leetcode.com

The last two lines show the two rules: `forward 2` after a visit has nothing
ahead of it, so it stays put, and `back 7` runs out of history and stops on
the home page.

*/

#include <iostream>
#include <string>
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Node of a doubly linked list, but holding a url instead of a number.
class Node {
    public:
        string url;
        Node* next;  // the page ahead of this one
        Node* prev;  // the page behind this one

    Node(string url) {
        this->url = url;
        this->next = NULL;
        this->prev = NULL;
    }
};

class BrowserHistory {
public:
    Node* current; // the page on screen right now

    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }

    void visit(string url) {
        Node* newNode = new Node(url);

        /* Linking the new page after `current` is also what throws the
           forward history away: nothing points at the old `current->next`
           any more, so those pages can never be reached again. */
        current->next = newNode;
        newNode->prev = current;

        current = newNode;
    }

    string back(int steps) {
        /* Two ways to stop: the steps run out, or there is no page behind.
           The second test is what makes `back(7)` on a 3-page history safe. */
        while(steps > 0 && current->prev != NULL){
            current = current->prev;
            steps--;
        }
        return current->url;
    }

    string forward(int steps) {
        while(steps > 0 && current->next != NULL){
            current = current->next;
            steps--;
        }
        return current->url;
    }
};

// Main function: Entry point of the program.
int main(){
    string homepage;
    cin >> homepage;

    BrowserHistory browser(homepage);

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
        string command;
        cin >> command;

        if(command == "visit"){
            string url;
            cin >> url;
            browser.visit(url);
        } else if(command == "back"){
            int steps;
            cin >> steps;
            cout << browser.back(steps) << endl;
        } else if(command == "forward"){
            int steps;
            cin >> steps;
            cout << browser.forward(steps) << endl;
        }
    }

    return 0;
}
