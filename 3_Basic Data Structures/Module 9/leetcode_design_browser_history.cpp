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

#include <iostream>   // cin and cout
#include <string>     // std::string - a piece of text (used for the urls and commands)
using namespace std; // Allows us to avoid prefixing standard library objects with `std::`.

// Node of a doubly linked list, but holding a url instead of a number.
class Node {
    public:              // members below are usable from outside the class
        string url;      // the page this node stands for
        Node* next;  // the page ahead of this one
        Node* prev;  // the page behind this one

    // Constructor: runs on `new Node("x.com")`. `this->url` is the member,
    // plain `url` is the parameter with the same name.
    Node(string url) {
        this->url = url;     // store the page
        this->next = NULL;   // nothing ahead yet
        this->prev = NULL;   // nothing behind yet
    }
};

// The class LeetCode asks for. It only needs one pointer: the page we are on.
// The pages behind and ahead are reached through `prev` and `next`.
class BrowserHistory {
public:
    Node* current; // the page on screen right now

    // Constructor: the history starts with just the home page.
    BrowserHistory(string homepage) {
        current = new Node(homepage);   // `new` makes the node on the heap and returns its address
    }

    // Open `url` from the current page. O(1).
    void visit(string url) {
        Node* newNode = new Node(url);   // the new page, not linked yet

        /* Linking the new page after `current` is also what throws the
           forward history away: nothing points at the old `current->next`
           any more, so those pages can never be reached again. */
        // (Those old pages are never `delete`d - a small leak, fine here.)
        current->next = newNode;   // current page -> new page
        newNode->prev = current;   // current page <- new page

        current = newNode;         // we are now on the new page
    }

    // Move back up to `steps` pages; return the page we land on. O(steps).
    string back(int steps) {
        /* Two ways to stop: the steps run out, or there is no page behind.
           The second test is what makes `back(7)` on a 3-page history safe. */
        // `&&` = both must be true to keep going.
        while(steps > 0 && current->prev != NULL){
            current = current->prev;   // one page back
            steps--;                   // one step used
        }
        return current->url;           // the page we stopped on
    }

    // The mirror image of back: follow `next` instead of `prev`.
    string forward(int steps) {
        while(steps > 0 && current->next != NULL){   // steps left AND a page ahead
            current = current->next;   // one page forward
            steps--;                   // one step used
        }
        return current->url;           // the page we stopped on
    }
};

// Main function: Entry point of the program.
// Reads the home page and q commands, runs them, prints the result of every
// back/forward.
int main(){
    string homepage;
    cin >> homepage;   // `cin >>` into a string reads one word (stops at a space/newline)

    BrowserHistory browser(homepage);   // make the history object; its constructor runs here

    int q;
    cin >> q;          // number of commands

    // One command per round.
    for(int i = 0; i < q; i++){
        string command;
        cin >> command;   // "visit", "back" or "forward"

        if(command == "visit"){          // std::string can be compared with == directly
            string url;
            cin >> url;                  // the page to open
            browser.visit(url);          // prints nothing
        } else if(command == "back"){
            int steps;
            cin >> steps;
            cout << browser.back(steps) << endl;      // page after moving back; endl = newline + flush
        } else if(command == "forward"){
            int steps;
            cin >> steps;
            cout << browser.forward(steps) << endl;   // page after moving forward
        }
    }

    return 0;   // normal exit
}
