/*

Babul likes to read books. He has N books and they take different times to finish each. He has arranged all the books in a order of finishing time to read them. So the first book will need the least time to finish and the last book will take the most time. He as T time to read.

He has given how a list of N number in increasing order. The numbers are the times to finish the books.

You have to tell him how many books he can finish reading at most in T time.

Input Format

The first line of input will contain two integers N and T, the number of books and the time he has in total. The next line will contain N numbers in increasing order.

Constraints

1 <= N <= 10^5
0 <= T <= 10^9
Output Format

Print a single integer, the maximum number of books babul can finish reading in T time.

Sample Input 0

10 33
1 3 4 6 8 10 12 15 23 36
Sample Output 0

6

*/



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    /* T can be 10^9 and the running total of reading times can pass what an
       int holds, so both totals are long long. */
    long long T;
    /* A fixed array big enough for the largest N (10^5). */
    int times[100000];
    long long total_time = 0;
    int number_of_books = 0;
    
    scanf("%d %lld", &N, &T);
    
    for(int i=0; i < N; i++){
        scanf("%d", &times[i]);
    }
    
    /* The times come sorted from shortest to longest, so the best plan is
       greedy: read the shortest books first. Add the books one by one to a
       running total; as long as the total still fits into T, that book is
       finished and counted. The first book that does not fit ends the
       search - every later book is at least as long, so none of them could
       fit either. */
    for(int i=0; i < N; i++){
        total_time += times[i];
        if(total_time <= T){
            number_of_books = number_of_books + 1;
        } else{
            break;
        }
    }
    
    printf("%d", number_of_books);
    
    return 0;
}
