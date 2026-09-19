#include <stdio.h>
#include <stdbool.h>

// Given a number N. Print all even numbers between 1 and N inclusive in separate lines
//
// <stdbool.h> is the header that gives C the words bool, true and false.
// Without it you would use an int holding 0 or 1; the meaning is the same,
// the names just read better.
//
// The shape of the program is "do the work, and remember whether it ever
// happened". You cannot print -1 while the loop is running, because an even
// number might still turn up later; only once the loop is over do you know
// there was none.
//
// This main has no `return 0;` at the end. Since C99 that is allowed for
// main alone: it returns 0 by itself.

int main() {

    int n;
    scanf("%d", &n);
    // The "did it ever happen?" marker. It starts off false and is switched
    // on the first time something is printed.
    bool flag = false;
    // i <= n, not i < n: the problem says N itself counts too.
    // i % 2 == 0 is the test for even - dividing by 2 leaves no remainder.
    // (Looping `i = 2; i <= n; i += 2` would visit only the even numbers and
    // skip the test, but this form is closer to how the task is worded.)
    for(int i = 1; i <= n; i++){
        if(i % 2 == 0){
            flag=true;
            printf("%d\n", i);
        }
    }
    // Nothing was printed, so n was 1 or smaller and there is no even number
    // in range. The problem asks for -1 in that case.
    if(flag==false){
        printf("-1");
    }
}