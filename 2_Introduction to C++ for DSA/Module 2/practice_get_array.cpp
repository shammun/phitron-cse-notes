/*

Practice Day 01 (Module 2.5) - Question 1: get_array()

main reads a number N and passes it to a function called get_array(N).
That function makes an int array of N elements, reads the N values into it
and returns the array. main receives it and prints the values.

Sample input
5
1 2 3 4 5

Sample output
1 2 3 4 5

*/

#include <iostream> // cin and cout
using namespace std; // write cin/cout instead of std::cin/std::cout

// get_array() must hand an array back to main, so the array has to outlive the
// function. A local `int a[n];` lives on the stack and dies when the function
// returns (that is the trap shown in return_dynamic_array.cpp). An array made
// with `new` lives on the heap and stays until someone calls delete[].
// The return type int* means "the address of an int" - here, of the first box.
int* get_array(int n){
    int *a = new int[n]; // ask the heap for n int boxes; n is only known now, at run time

    // A pointer to a heap array is used exactly like an array: a[i] is box number i
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    return a; // hand back the address; the boxes themselves stay alive on the heap
}

int main(){
    int n;
    cin >> n; // N is read in main, as the question asks

    // arr receives the address that get_array() returned, so arr[i] reads
    // the same heap boxes the function filled
    int *arr = get_array(n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    // The array was made in get_array() but main is the last one to use it,
    // so main gives the memory back. Use delete[] (with brackets) for arrays.
    delete[] arr;

    return 0; // the program ended fine
}
