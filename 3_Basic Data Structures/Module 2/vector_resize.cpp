// resize(k): make the vector have exactly k elements.
//   k smaller than size -> extra elements at the end are removed
//   k bigger than size  -> new elements are added at the end, set to 0
//                          (or to a value you give: resize(k, value))
// Output of this program (all on one line): 10 20 10 20 0 0 0 10 20 0 0 0 100 100

#include <iostream> // cout
#include <vector>   // vector
using namespace std; // lets us drop the std:: prefix

int main() { // the program starts running here
    vector<int> v; // empty vector
    v.push_back(10); // {10}
    v.push_back(20); // {10, 20}
    v.push_back(30); // {10, 20, 30}

    //  resize() function changes the size of the vector
    // size is decrreased
    v.resize(2); // {10, 20}: the 30 is dropped
    for(int i=0; i<v.size(); i++){ // print all current elements
        cout << v[i] << " "; // prints 10 20
    }

    // size is increased
    // new elements are initialized with 0
    v.resize(5); // {10, 20, 0, 0, 0}
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " "; // prints 10 20 0 0 0
    }

    // When increasing size, we can also set the value of the new elements
    // (only the NEW elements get 100; the old ones keep their values)
    v.resize(7, 100); // {10, 20, 0, 0, 0, 100, 100}
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " "; // prints 10 20 0 0 0 100 100
    }

    return 0; // program finished successfully
}
