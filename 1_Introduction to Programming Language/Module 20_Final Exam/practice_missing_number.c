#include <stdio.h> // standard input/output library: scanf and printf

/* Re-typed practice copy of missing_number.c: M is the product of four
   numbers, three of them (A, B, C) are given; print the fourth, or -1 if no
   whole number fits. Example: 20 1 2 2 -> 5, 10 2 2 1 -> -1. */

int main(){ // program execution starts here
    int T; // number of test cases
    scanf("%d", &T); // &T = address where scanf stores T

    long long results[100005]; // one answer per test case, printed at the end

    for(int i=0; i<T; i++){ // one pass = one test case
        long long M, A,B,C; // long long: M goes up to 10^18 and so can A*B*C
        scanf("%lld %lld %lld %lld", &M, &A, &B, &C); // %lld = read a long long

        long long remainder = M % (A * B * C); // 0 means M divides exactly by A*B*C

        if(remainder == 0){
            results[i] = M / (A * B * C); // the missing fourth number
        }else{
            results[i] = -1; // no whole number works
        }
    }

    for(int i=0; i<T; i++){ // print all answers, one per line
        printf("%lld\n", results[i]);
    }
} // end of main; in C99 and later, reaching here means return 0
