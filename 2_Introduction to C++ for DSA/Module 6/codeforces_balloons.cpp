/*

ICPC Balloons

time limit per test: 1 second
memory limit per test: 256 megabytes

In an ICPC contest, balloons are distributed as follows:

    Whenever a team solves a problem, that team gets a balloon.
    The first team to solve a problem gets an additional balloon.

A contest has 26 problems, labelled A, B, C, ..., Z. You are given the order of solved problems in the 
contest, denoted as a string s,  where the i
-th character indicates that the problem si
 has been solved by some team. No team will solve the same problem twice.
Determine the total number of balloons that the teams received. Note that some problems may be solved by none of the teams.

Input
The first line of the input contains an integer t (1≤t≤100) - the number of testcases.

The first line of each test case contains an integer n (1≤n≤50) — the length of the string.

The second line of each test case contains a string s of length n consisting of uppercase English letters, 
denoting the order of solved problems.

Output
For each test case, output a single integer — the total number of balloons that the teams received.

Example

Input
6
3
ABA
1
A
3
ORZ
5
BAAAA
4
BKPT
10
CODEFORCES

Output
5
2
6
7
8
17

Note: In the first test case, 5 balloons are given out:

Problem A is solved. That team receives 2 balloons: one because they solved the problem, an an additional 
one because they are the first team to solve problem A.

Problem B is solved. That team receives 2 balloons: one because they solved the problem, an an additional 
one because they are the first team to solve problem B.

Problem A  is solved. That team receives only 1 balloon, because they solved the problem. Note that they 
don't get an additional balloon because they are not the first team to solve problem A. The total number of 
balloons given out is 2+2+1=5.

In the second test case, there is only one problem solved. The team who solved it receives 2 balloons: one 
because they solved the problem, an an additional one because they are the first team to solve problem A.

*/

/*
IDEA
Every letter in s is one solve, and every solve earns exactly 1 balloon.
On top of that, the FIRST time a letter appears, that team gets 1 bonus balloon.
So: answer = n (one per letter) + (number of DIFFERENT letters in s).
We remember which letters we have already seen with 26 true/false flags.

Trace for s = "ABA":
  'A' -> +1, A not seen before -> +1 bonus, mark A   (total 2)
  'B' -> +1, B not seen before -> +1 bonus, mark B   (total 4)
  'A' -> +1, A already seen    -> no bonus           (total 5)
*/

#include <iostream> // Gives us cin (read from keyboard) and cout (print to screen)
#include <string> // Gives us std::string, a text type that knows its own length and can grow
using namespace std; // Lets us write cin, cout, string instead of std::cin, std::cout, std::string

// Works out the balloons for one test case. Every letter of s is one solve,
// worth 1 balloon, plus 1 extra the first time that letter appears.
// Parameters: n = length of s, s = the order in which problems were solved.
// Returns: the total number of balloons handed out in this test case.
int calculate_balloons(int n, string s){
    // One flag per problem A..Z: has anyone solved it yet?
    // In the name first_time, true means "its first solve has already happened".
    // first_time[0] is problem A, first_time[1] is B, ..., first_time[25] is Z.
    bool first_time[26] = {false}; // = {false} starts all 26 flags as false (missing values in a {...} list become 0/false)
    int total_balloons = 0; // running total, starts at zero

    // count the number of balloons
    // One pass of the loop handles one solve: the letter s[i].
    // i runs over positions 0, 1, ..., n-1 and the loop stops when i reaches n.
    for(int i=0; i<n; i++){
        // Turn the letter into 0..25: 'A' - 'A' = 0, 'B' - 'A' = 1, ... (ASCII codes are consecutive)
        // e.g. 'C' is 67 and 'A' is 65, so 'C' - 'A' = 2 -> the flag for problem C.
        int problem_index = s[i] - 'A';

        total_balloons += 1; // the balloon every solve earns (+= 1 means "add 1 to it")

        // !first_time[...] is true when the flag is still false, i.e. nobody solved this problem before
        if(!first_time[problem_index]){
            total_balloons += 1; // bonus: the first team to solve this problem
            first_time[problem_index] = true; // later solves of it get no bonus
        } // end of the "first solve" check

    } // end of the loop over the letters

    return total_balloons; // hand the answer back to whoever called the function
} // end of calculate_balloons

// main: read all test cases, solve each one, then print the answers.
int main(){
    int t; // number of test cases
    cin >> t; // read t from the input

    int results[100]; // t is at most 100: store all answers, print them at the end

    // One pass = one test case. i counts the test cases 0..t-1.
    for(int i=0; i<t; i++){
        int n; // length of the string for this test case
        string s; // the solved problems in order, e.g. "ABA"
        cin >> n >> s; // cin >> reads the whole word of letters into the string (it stops at a space or newline)
        results[i] = calculate_balloons(n, s); // solve this test and remember the answer
    } // end of the reading loop

    // Print every stored answer, one per line.
    for(int i=0; i<t; i++){
        cout << results[i] << endl; // endl prints a newline (and flushes the output)
    } // end of the printing loop

    return 0;  // Indicate that the program ended successfully
} // end of main
