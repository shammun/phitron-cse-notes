/*

K. I Love strings
time limit per test: 2 seconds
memory limit per test: 64 megabytes

Given two strings S and T. Print a new string that contains the following:

- The first letter of the string S followed by the first letter of the string T.
- The second letter of the string S followed by the second letter of the string T.
- and so on...

In other words, the new string should be ( S0 + T0 + S1 + T1 + .... ).

Note: If the length of S is greater than the length of T then you have to add the rest of
S letters at the end of the new string and vice versa.

Input
The first line contains a number N (1 <= N <= 50) the number of test cases.

Each of the N following lines contains two string S, T (1 <= |S|, |T| <= 50) consists of
lower and upper English letters.

Output
For each test case, print the required string.

Example

input
2
ipAsu ccsit
ey gpt

output
icpcAssiut
egypt

*/

# include <stdio.h>
# include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    for(int k = 0; k < n; k++){
        /* Each string has at most 50 letters, so 55 slots are enough. */
        char s[55];
        char t[55];
        scanf("%s %s", s, t);

        int length_s = strlen(s);
        int length_t = strlen(t);

        /* Run i up to the longer length. On each step print S's letter at i
           and then T's letter at i, but only if that string still has a letter there.
           When the shorter string runs out, the longer one simply keeps printing,
           which adds "the rest of the letters" at the end. */
        int longer = length_s;
        if(length_t > longer){
            longer = length_t;
        }

        for(int i = 0; i < longer; i++){
            if(i < length_s){
                printf("%c", s[i]);
            }
            if(i < length_t){
                printf("%c", t[i]);
            }
        }

        /* Each test case goes on its own line. */
        printf("\n");
    }

    return 0;
}
