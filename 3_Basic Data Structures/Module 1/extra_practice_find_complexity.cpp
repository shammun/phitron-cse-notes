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

#include <bits/stdc++.h>
using namespace std;

long long steps; // counts how many times the innermost work ran

// Shape 1: an outer loop over i, an inner loop over j that jumps by 2.
// Inner loop: n/2 rounds. Outer loop: n rounds. n * n/2 = n^2/2 -> O(n^2).
long long shape1(int n){
    steps = 0;
    int i = 0;
    while(i < n){
        int j = 0;
        while(j < n){
            steps++;     // stands for "sum += j"
            j += 2;
        }
        i++;
    }
    return steps;
}

// Shape 2: outer loop jumps by 10 (n/10 rounds), inner loop walks from n down
// to 0 (n+1 rounds), then a separate single loop of n rounds.
// (n/10)*(n+1) + n: the biggest term is n^2/10 -> O(n^2).
long long shape2(int n){
    steps = 0;
    for(int i = 0; i < n; i += 10){
        for(int j = n; j >= 0; j--){
            steps++;     // stands for printing "Hello"
        }
    }
    for(int i = 0; i < n; i++){
        steps++;         // stands for printing "Hi"
    }
    return steps;
}

// Shape 3: for each i (n rounds), j climbs while j*j < n, which is about
// sqrt(n) rounds. n * sqrt(n) -> O(n sqrt n).
long long shape3(int n){
    steps = 0;
    for(int i = 0; i < n; i++){
        int j = 0;
        while(j * j < n){
            steps++;
            j++;
        }
    }
    return steps;
}

// Shape 4: three nested loops of about n rounds each (n^3), followed by two
// nested loops (n^2). n^3 + n^2: keep the biggest term -> O(n^3).
long long shape4(int n){
    steps = 0;
    for(int i = 0; i < n; i++){
        for(int j = n; j >= 0; j--){
            for(int k = 1; k <= n; k++){
                steps++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= n; j++){
            steps++;
        }
    }
    return steps;
}

// Shape 5: a loop that stops at i*i < n (sqrt n rounds), then a loop whose i
// is multiplied by k every round (here k = 2), so it reaches n in about
// log(n) rounds. sqrt(n) + log(n): sqrt grows faster -> O(sqrt n).
long long shape5(int n){
    steps = 0;
    for(int i = 0; i * i < n; i++){
        steps++;
    }
    int k = 2;
    for(int i = 0; i < n; i++){
        steps++;
        i *= k;          // 0, 1, 3, 7, 15, ... roughly doubles each round
    }
    return steps;
}

// For shapes 6 and 7 we need to count the work that sort() does. We give
// sort() our own compare function and count every comparison it asks for.
bool cmp(int a, int b){
    steps++;
    return a < b;
}

// Shape 6: read n numbers (n steps), then sort them once (about n log n
// comparisons). n + n log n -> O(n log n).
long long shape6(int n){
    steps = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        a[i] = (i * 37) % n;   // some mixed-up numbers instead of cin
        steps++;
    }
    sort(a.begin(), a.end(), cmp);
    return steps;
}

// Shape 7: sort() is called inside a loop that runs n times.
// n times (n log n) -> O(n^2 log n).
long long shape7(int n){
    steps = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        a[i] = (i * 37) % n;
    }
    for(int i = 0; i < n; i++){
        sort(a.begin(), a.end(), cmp);
    }
    return steps;
}

int main(){
    int n;
    cin >> n;

    string answer[8] = {"", "O(n^2)", "O(n^2)", "O(n sqrt n)", "O(n^3)",
                        "O(sqrt n)", "O(n log n)", "O(n^2 log n)"};

    for(int s = 1; s <= 7; s++){
        long long a, b;
        // Run the same shape for n and for 2n.
        if(s == 1){ a = shape1(n); b = shape1(2 * n); }
        if(s == 2){ a = shape2(n); b = shape2(2 * n); }
        if(s == 3){ a = shape3(n); b = shape3(2 * n); }
        if(s == 4){ a = shape4(n); b = shape4(2 * n); }
        if(s == 5){ a = shape5(n); b = shape5(2 * n); }
        if(s == 6){ a = shape6(n); b = shape6(2 * n); }
        if(s == 7){ a = shape7(n); b = shape7(2 * n); }

        // How many times more work did doubling n cause?
        double growth = (double)b / a;
        cout << "Shape " << s << ": " << a << " -> " << b
             << " steps, x" << fixed << setprecision(2) << growth
             << "  => " << answer[s] << endl;
    }

    return 0;
}
