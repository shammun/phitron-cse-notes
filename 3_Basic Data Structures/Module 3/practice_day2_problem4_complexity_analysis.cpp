/*
 * Practice Day, Problem 4: complexity analysis.
 *
 * The sheet gives five short loop pieces and asks for the time complexity of
 * each. This program runs every piece with a counter `steps` (one step = one
 * run of the innermost line) for n and for 2n, then prints how many times
 * bigger the count became. That growth factor confirms the answer:
 *   x2 -> O(n)   x4 -> O(n^2)   x8 -> O(n^3)
 *   barely grows (+1 step) -> O(log n)   a bit over x2 -> O(n log n)
 *
 * Example: input 64 runs the pieces for n = 64 and n = 128. Piece A takes
 * 7 steps, then 8: doubling n only added ONE step, the sign of O(log n).
 */

#include <iostream> // cin and cout
#include <iomanip>  // fixed and setprecision (control how decimals are printed)
#include <string>   // string, for the answer labels
using namespace std; // lets us drop the std:: prefix

// Global (outside every function) so every piece can add to the same counter.
// long long because piece C at big n can pass the int limit (about 2.1 * 10^9).
long long steps;   // how many times the innermost line ran

// Piece A: k starts at 1 and doubles until it passes n.
// 1, 2, 4, 8, ... reaches n after about log2(n) doublings -> O(log n).
// void = the function returns nothing; it only changes `steps`.
void pieceA(int n){
    int k = 1; // start value
    while(k <= n){ // stops once k is bigger than n
        steps++; // count one run
        k = k * 2; // double k
    }
}

// Piece B: the inner loop runs i times for each i (0 + 1 + 2 + ... + n-1).
// That total is n(n-1)/2, about n^2/2 -> O(n^2).
void pieceB(int n){
    for(int i = 0; i < n; i++){ // n rounds
        for(int j = i; j > 0; j--){ // i rounds (j = i, i-1, ..., 1)
            steps++; // count one run
        }
    }
}

// Piece C: three loops, each one counting down from the one outside it.
// The total is about n^3/6: a smaller constant, but still O(n^3).
void pieceC(int n){
    for(int i = 0; i < n; i++){ // n rounds
        for(int j = i; j > 0; j--){ // i rounds
            for(int k = j; k > 0; k--){ // j rounds
                steps++; // count one run
            }
        }
    }
}

// Piece D: the outer loop runs from n/2 to n (about n/2 rounds), the inner
// loop doubles j (about log n rounds). (n/2) * log n -> O(n log n).
void pieceD(int n){
    for(int i = n / 2; i <= n; i++){ // about n/2 + 1 rounds
        for(int j = 1; j <= n; j = j * 2){ // j = 1, 2, 4, ... <= n: about log2(n) + 1 rounds
            steps++; // count one run
        }
    }
}

// Piece E: same outer loop, but the inner loop now walks j = 1..n one at a
// time. (n/2) * n -> O(n^2).
// (The sheet writes the step as `j = j++`. Assigning j to itself while also
// increasing it is undefined in C++14, so we write the intended j++.)
void pieceE(int n){
    for(int i = n / 2; i <= n; i++){ // about n/2 rounds
        for(int j = 1; j <= n; j++){ // n rounds
            steps++; // count one run
        }
    }
}

// Run one piece for size n and return how many steps it took.
// piece is a single character 'A'..'E' choosing which function to call.
long long run(char piece, int n){
    steps = 0; // reset the counter before every run
    if(piece == 'A') pieceA(n); // a one-line if needs no { }
    if(piece == 'B') pieceB(n);
    if(piece == 'C') pieceC(n);
    if(piece == 'D') pieceD(n);
    if(piece == 'E') pieceE(n);
    return steps; // the count for this run
}

int main(){ // the program starts running here
    int n; // base size
    cin >> n; // read it, e.g. 64

    char pieces[5] = {'A', 'B', 'C', 'D', 'E'}; // the piece names, in order
    string answers[5] = {"O(log n)", "O(n^2)", "O(n^3)", "O(n log n)", "O(n^2)"}; // expected Big-O for each

    // One pass per piece: run it for n and 2n and print the growth factor.
    for(int p = 0; p < 5; p++){
        long long a = run(pieces[p], n);       // size n
        long long b = run(pieces[p], 2 * n);   // size 2n
        // (double)b / a: turn b into a decimal first so the division keeps the
        // fraction; fixed << setprecision(2) prints it with 2 decimals, e.g. x4.03.
        cout << "Piece " << pieces[p] << ": " << a << " -> " << b
             << " steps, x" << fixed << setprecision(2) << (double)b / a
             << "  => " << answers[p] << endl;
    }

    return 0; // program finished successfully
}
