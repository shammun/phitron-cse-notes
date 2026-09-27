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

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

long long steps;   // how many times the innermost line ran

// Piece A: k starts at 1 and doubles until it passes n.
// 1, 2, 4, 8, ... reaches n after about log2(n) doublings -> O(log n).
void pieceA(int n){
    int k = 1;
    while(k <= n){
        steps++;
        k = k * 2;
    }
}

// Piece B: the inner loop runs i times for each i (0 + 1 + 2 + ... + n-1).
// That total is n(n-1)/2, about n^2/2 -> O(n^2).
void pieceB(int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j > 0; j--){
            steps++;
        }
    }
}

// Piece C: three loops, each one counting down from the one outside it.
// The total is about n^3/6: a smaller constant, but still O(n^3).
void pieceC(int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j > 0; j--){
            for(int k = j; k > 0; k--){
                steps++;
            }
        }
    }
}

// Piece D: the outer loop runs from n/2 to n (about n/2 rounds), the inner
// loop doubles j (about log n rounds). (n/2) * log n -> O(n log n).
void pieceD(int n){
    for(int i = n / 2; i <= n; i++){
        for(int j = 1; j <= n; j = j * 2){
            steps++;
        }
    }
}

// Piece E: same outer loop, but the inner loop now walks j = 1..n one at a
// time. (n/2) * n -> O(n^2).
// (The sheet writes the step as `j = j++`. Assigning j to itself while also
// increasing it is undefined in C++14, so we write the intended j++.)
void pieceE(int n){
    for(int i = n / 2; i <= n; i++){
        for(int j = 1; j <= n; j++){
            steps++;
        }
    }
}

// Run one piece for size n and return how many steps it took.
long long run(char piece, int n){
    steps = 0;
    if(piece == 'A') pieceA(n);
    if(piece == 'B') pieceB(n);
    if(piece == 'C') pieceC(n);
    if(piece == 'D') pieceD(n);
    if(piece == 'E') pieceE(n);
    return steps;
}

int main(){
    int n;
    cin >> n;

    char pieces[5] = {'A', 'B', 'C', 'D', 'E'};
    string answers[5] = {"O(log n)", "O(n^2)", "O(n^3)", "O(n log n)", "O(n^2)"};

    for(int p = 0; p < 5; p++){
        long long a = run(pieces[p], n);       // size n
        long long b = run(pieces[p], 2 * n);   // size 2n
        cout << "Piece " << pieces[p] << ": " << a << " -> " << b
             << " steps, x" << fixed << setprecision(2) << (double)b / a
             << "  => " << answers[p] << endl;
    }

    return 0;
}
