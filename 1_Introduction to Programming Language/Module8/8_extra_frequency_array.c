/*

Frequency Array  (extra practice problem)
https://codeforces.com/group/MWSDmqGsZm/contest/219774/problem/V

You get N numbers, each one between 1 and M. For every value from 1 to M,
say how many times it turns up among the N numbers.

Input
First line: N and M (both up to 10^5).
Second line: the N numbers (each between 1 and M).

Output
M lines. Line v holds how many times the value v appeared.

Example

input
10 5
1 2 3 4 5 3 2 1 5 3

output
2
2
3
1
2

Note
1 appears twice, 2 twice, 3 three times, 4 once and 5 twice.

*/

/* stdio.h ("standard input output") declares scanf and printf. The
   space in "# include" is allowed; it means the same as #include. */
# include <stdio.h>

int main() {                /* the program starts running here */
    int n, m;               /* n = how many numbers, m = largest possible value */
    scanf("%d %d", &n, &m); /* read both; & gives each variable's address */

    /* The slow way would be: for each v from 1 to M, walk all N numbers and
       count the ones equal to v. That is M * N steps - with both up to
       10^5, ten billion steps, far too slow.

       The fast way uses one array of counters, one box per possible value:
           cnt[1] counts the 1s, cnt[2] counts the 2s, ..., cnt[m] the ms.
       The value we read tells us WHICH box to add 1 to, so every number is
       handled in a single step and there is no searching at all.

       m + 1 boxes, because the values go up to m and the last box of an
       array of size m + 1 is cnt[m]. Box 0 is simply never used. */
    int cnt[m + 1];

    /* An array declared inside main starts with rubbish, so every counter
       is set to 0 first. (int cnt[m + 1] = {0}; is not allowed when the size
       is only known at run time, so the loop does it.) */
    for(int v = 0; v <= m; v++){
        cnt[v] = 0;         /* box v starts empty */
    }

    /* Read each number and add 1 to its box. The numbers themselves are not
       needed afterwards, so they are not stored. */
    for(int i = 0; i < n; i++){
        int x;              /* the number just read */
        scanf("%d", &x);
        cnt[x]++;           /* one more x: add 1 to box x. e.g. x = 3 -> cnt[3]++ */
    }

    /* One line per value from 1 to m, in order. A value that never came
       still has 0 in its box, and 0 is printed for it. */
    for(int v = 1; v <= m; v++){
        printf("%d\n", cnt[v]);    /* how many times v appeared */
    }

    return 0;   /* 0 = the program finished normally */
}
