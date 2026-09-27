// clear(): removes every element from a vector, so size() becomes 0.
// It does NOT give the memory back (capacity() stays the same), and for plain
// ints it does not wipe the old numbers either. That is why this demo can still
// "see" old values with v[i]. Reading v[i] when i >= size() is undefined
// behaviour: the language makes no promise about what you get. It only happens
// to show the old numbers here with g++. Never rely on it in real code.

#include <iostream> // cout
#include <vector>   // vector
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    vector<int> v = {10, 20, 30}; // a vector made from a list of values: size 3
    cout << v.size() << endl; // 3

    // clear() removes all the elements, so the size becomes 0.
    // The reserved memory is kept (capacity stays 3) and, for plain ints, the old
    // numbers are not wiped - but they are no longer part of the vector. The lines
    // below peek at them only as a demo (undefined behaviour, see the top of the file).
    // If we insert a value now, it goes in at index 0.
    v.clear(); // size becomes 0, capacity stays 3
    cout << v.size() << endl; // 0
    cout << v[0] << endl; // 10  (out of range: undefined behaviour, g++ shows the leftover 10)
    cout << v[1] << endl; // 20  (same: leftover value)
    cout << v[2] << endl; // 30  (same: leftover value)

    v.push_back(40); // size 1: 40 goes into slot 0, overwriting the leftover 10
    cout << v[0] << endl; // 40
    cout << v[1] << endl; // 20  (still a leftover, not a real element)
    cout << v[2] << endl; // 30  (leftover)

    v.push_back(50); // size 2: 50 goes into slot 1
    cout << v[0] << endl; // 40
    cout << v[1] << endl; // 50
    cout << v[2] << endl; // 30  (leftover)

    v.push_back(60); // size 3: 60 goes into slot 2; now all three are real elements again
    cout << v[0] << endl; // 40
    cout << v[1] << endl; // 50
    cout << v[2] << endl; // 60

    return 0; // program finished successfully
}
