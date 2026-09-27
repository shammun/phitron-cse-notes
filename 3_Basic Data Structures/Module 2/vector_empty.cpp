// empty(): asks a vector "do you have zero elements?" and answers true/false.

#include <iostream> // cout
#include <vector>   // vector
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    // Start from a vector with no elements, then grow it with push_back, so that
    // empty() has something to answer about. Size is 3 by the time the check runs.
    vector<int> v; // empty vector of ints, size 0
    v.push_back(10); // add 10 at the end -> {10}
    v.push_back(20); // -> {10, 20}
    v.push_back(30); // -> {10, 20, 30}

    // The name is the first trap: empty() is a question, not an order. It asks "are you
    // empty?" and returns true or false; it does not remove anything. The function that
    // empties a vector is clear(), from the previous file.
    // empty() is exactly `size() == 0`, written in a way that reads better and is O(1).
    // Why bother with it at all: it is the guard you put before v[0], v.back() or
    // v.pop_back(), because on an empty vector those touch memory that is not yours.
    // Writing `== true` is not needed - `if(v.empty())` says the same thing - but it is
    // harmless and it makes the test easy to read the first few times.

    // empty() function returns true if the vector is empty
    if(v.empty() == true){ // size is 3 here, so this is false
        cout << "Vector is empty" << endl; // would run only for size 0
    }
    else{ // taken in this program
        cout << "Vector is not empty" << endl; // this is what gets printed
    }

    return 0; // program finished successfully
}
