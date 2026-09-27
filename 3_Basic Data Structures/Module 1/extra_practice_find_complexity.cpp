/*
 * Extra practice: find the time complexity of seven code shapes.
 *
 * The practice sheet shows seven small loop snippets and asks for the Big-O of
 * each one. Instead of only guessing, this program RUNS every shape with a
 * counter `steps` that goes up by one each time the innermost body runs.
 *
 * The trick to check an answer: run the shape for n and again for 2n and look
 * at how many times bigger the count got.
 *   O(n)        -> about 2 times        O(n^2)       -> about 4 times
 *   O(n^3)      -> about 8 times        O(sqrt n)    -> about 1.41 times
 *   O(n sqrt n) -> about 2.83 times     O(n log n)   -> a bit more than 2 times
 *   O(n^2 log n)-> a bit more than 4 times
 *
 * Example: input 100 runs every shape for n = 100 and n = 200.
 * Shape 1 does 5000 steps, then 20000: 4 times more, so it is O(n^2).
 */

#include <bits/stdc++.h> // g++ shortcut header: pulls in the whole standard library (iostream, vector, algorithm, iomanip, ...)
using namespace std; // so we can write cout, vector, sort instead of std::cout, std::vector, std::sort

// A global variable (declared outside every function), so every shape function
// and cmp() below can add to the same counter. long long holds up to about
// 9 * 10^18; a plain int (about 2 * 10^9) could overflow for the big shapes.
long long steps; // counts how many times the innermost work ran

// Shape 1: an outer loop over i, an inner loop over j that jumps by 2.
// Inner loop: n/2 rounds. Outer loop: n rounds. n * n/2 = n^2/2 -> O(n^2).
// Takes n (the input size), returns how many steps it counted.
long long shape1(int n){
    steps = 0; // start counting from zero for this run
    int i = 0; // outer loop variable
    while(i < n){ // outer loop: i = 0 .. n-1 -> n rounds
        int j = 0; // inner loop variable, restarts at 0 on every outer round
        while(j < n){ // inner loop: j = 0, 2, 4, ... < n -> about n/2 rounds
            steps++;     // stands for "sum += j"
            j += 2; // jump j by 2
        }
        i++; // move the outer loop forward by 1
    }
    return steps; // hand back the count
}

// Shape 2: outer loop jumps by 10 (n/10 rounds), inner loop walks from n down
// to 0 (n+1 rounds), then a separate single loop of n rounds.
// (n/10)*(n+1) + n: the biggest term is n^2/10 -> O(n^2).
long long shape2(int n){
    steps = 0; // reset the counter
    for(int i = 0; i < n; i += 10){ // i = 0, 10, 20, ... -> about n/10 rounds
        for(int j = n; j >= 0; j--){ // j = n, n-1, ..., 0 -> n+1 rounds
            steps++;     // stands for printing "Hello"
        }
    }
    for(int i = 0; i < n; i++){ // a separate (not nested) loop: n rounds
        steps++;         // stands for printing "Hi"
    }
    return steps; // hand back the count
}

// Shape 3: for each i (n rounds), j climbs while j*j < n, which is about
// sqrt(n) rounds. n * sqrt(n) -> O(n sqrt n).
long long shape3(int n){
    steps = 0; // reset the counter
    for(int i = 0; i < n; i++){ // n rounds
        int j = 0; // restart j for each i
        while(j * j < n){ // stops once j reaches sqrt(n): e.g. n = 100 -> j = 0..9
            steps++; // one unit of work
            j++; // next j
        }
    }
    return steps; // hand back the count
}

// Shape 4: three nested loops of about n rounds each (n^3), followed by two
// nested loops (n^2). n^3 + n^2: keep the biggest term -> O(n^3).
long long shape4(int n){
    steps = 0; // reset the counter
    for(int i = 0; i < n; i++){ // n rounds
        for(int j = n; j >= 0; j--){ // n+1 rounds (counting down does not matter)
            for(int k = 1; k <= n; k++){ // n rounds
                steps++; // runs n * (n+1) * n times
            }
        }
    }
    for(int i = 0; i < n; i++){ // n rounds
        for(int j = 1; j <= n; j++){ // n rounds
            steps++; // runs n * n times
        }
    }
    return steps; // hand back the count
}

// Shape 5: a loop that stops at i*i < n (sqrt n rounds), then a loop whose i
// is multiplied by k every round (here k = 2), so it reaches n in about
// log(n) rounds. sqrt(n) + log(n): sqrt grows faster -> O(sqrt n).
long long shape5(int n){
    steps = 0; // reset the counter
    for(int i = 0; i * i < n; i++){ // i = 0 .. about sqrt(n)
        steps++; // one unit of work
    }
    int k = 2; // the multiply factor
    for(int i = 0; i < n; i++){ // header adds 1 after the body multiplies
        steps++; // one unit of work
        i *= k;          // 0, 1, 3, 7, 15, ... roughly doubles each round
    }
    return steps; // hand back the count
}

// For shapes 6 and 7 we need to count the work that sort() does. We give
// sort() our own compare function and count every comparison it asks for.
// sort() calls cmp(a, b) whenever it needs to know "should a come before b?";
// returning a < b gives normal smallest-to-biggest order.
bool cmp(int a, int b){
    steps++; // one comparison = one step
    return a < b; // true means a goes first
}

// Shape 6: read n numbers (n steps), then sort them once (about n log n
// comparisons). n + n log n -> O(n log n).
long long shape6(int n){
    steps = 0; // reset the counter
    vector<int> a(n); // a vector (resizable array) of n ints, all starting at 0
    for(int i = 0; i < n; i++){ // fill every slot: n rounds
        a[i] = (i * 37) % n;   // some mixed-up numbers instead of cin
        steps++; // count the "read"
    }
    // sort(first, last, cmp): a.begin() points at the first element, a.end()
    // just past the last, so this sorts the whole vector using cmp to compare.
    sort(a.begin(), a.end(), cmp);
    return steps; // n reads + all comparisons sort made
}

// Shape 7: sort() is called inside a loop that runs n times.
// n times (n log n) -> O(n^2 log n).
long long shape7(int n){
    steps = 0; // reset the counter
    vector<int> a(n); // n ints
    for(int i = 0; i < n; i++){ // fill with mixed-up numbers (not counted here)
        a[i] = (i * 37) % n; // (i * 37) % n scrambles the order 0..n-1
    }
    for(int i = 0; i < n; i++){ // n rounds
        sort(a.begin(), a.end(), cmp); // each sort counts its comparisons via cmp
    }
    return steps; // total comparisons over all n sorts
}

int main(){ // the program starts running here
    int n; // the base input size
    cin >> n; // read it, e.g. 100

    // The expected answer for shape s is answer[s]. Index 0 is an unused
    // empty string so that the shape numbers 1..7 match the array positions.
    string answer[8] = {"", "O(n^2)", "O(n^2)", "O(n sqrt n)", "O(n^3)",
                        "O(sqrt n)", "O(n log n)", "O(n^2 log n)"};

    // One pass per shape: s = 1..7. Run it for n and 2n and print the growth.
    for(int s = 1; s <= 7; s++){
        long long a, b; // a = steps for n, b = steps for 2n
        // Run the same shape for n and for 2n.
        if(s == 1){ a = shape1(n); b = shape1(2 * n); }
        if(s == 2){ a = shape2(n); b = shape2(2 * n); }
        if(s == 3){ a = shape3(n); b = shape3(2 * n); }
        if(s == 4){ a = shape4(n); b = shape4(2 * n); }
        if(s == 5){ a = shape5(n); b = shape5(2 * n); }
        if(s == 6){ a = shape6(n); b = shape6(2 * n); }
        if(s == 7){ a = shape7(n); b = shape7(2 * n); }

        // How many times more work did doubling n cause?
        // (double)b turns b into a decimal number first, so the division keeps
        // the fraction (20000/5000 = 4.00) instead of cutting it off like int division.
        double growth = (double)b / a;
        // fixed << setprecision(2) prints decimals with exactly 2 digits after the
        // point (4.00). setprecision comes from <iomanip>, included by bits/stdc++.h.
        cout << "Shape " << s << ": " << a << " -> " << b
             << " steps, x" << fixed << setprecision(2) << growth
             << "  => " << answer[s] << endl; // endl = new line + flush
    }

    return 0; // program finished successfully
}
