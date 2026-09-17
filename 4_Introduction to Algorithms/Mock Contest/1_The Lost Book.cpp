/*

The Lost Book

Problem Statement

The central library of the city has a unique method of organizing its books. The books are arranged in an array 
of integers, where each integer represents a unique book code.

You are the head librarian and have received a request to locate a specific book. Given the array of book codes 
and the target book code, your task is to determine if the book is available. If the book is found, return the 
index of the book in the array (0-based). Otherwise, return -1 to indicate the book is not in the collection.

Can you help to find the lost book?

Input Format

- The first line contains an integer n, the number of books.
- The second line contains n space-separated integers, representing the book codes.
- The third line contains a single integer target, the book code you are searching for.

Constraints
1 <= n <= 2*10^5
1 <= alpha_i <= 1X10^9
1 <= target <= 1X10^9 

Output Format
Output the index(0 based) of the book if found else output -1.

Sample Input 0
5
10 20 5 6 3
3

Sample Output 0
4

Sample Input 1
6
10 20 5 6 3 66
99

Sample Output 1
-1

*/

#include <iostream>

using namespace std;

int lostBook(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << lostBook(arr, n, target) << endl;

    return 0;
}