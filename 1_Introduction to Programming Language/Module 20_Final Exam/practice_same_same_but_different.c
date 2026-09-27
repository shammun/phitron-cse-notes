#include <stdio.h>  // standard input/output library: scanf and printf
#include <string.h> // string library: strlen

/* Re-typed practice copy of same_same_but_different.c: three equal-length
   strings; one operation changes one letter; find the fewest operations to
   make all three strings the same.
   At each position: all three letters different -> 2 changes,
   exactly two the same -> 1 change, all the same -> 0.
   Example: train / candy / bread -> 2 + 1 + 2 + 2 + 2 = 9. */

int main(){ // program execution starts here
    char str1[105], str2[105], str3[105]; // up to 100 letters + '\0', with spare room

    scanf("%s", str1); // array names are addresses, so no &
    scanf("%s", str2);
    scanf("%s", str3);

    int len = strlen(str1); // all three strings have this length
    int total_changes = 0; // the answer, built up position by position

    for(int i=0; i<len; i++){ // one pass = one position i in all three strings
        if(str1[i] != str2[i] && str1[i] != str3[i] && str2[i] != str3[i]){ // all three differ
            total_changes += 2; // change two letters to match the third
        }

        else if(str1[i] == str2[i] && str2[i] != str3[i]){ // 1 and 2 agree, 3 differs
            total_changes += 1;
        } else if(str1[i] == str3[i] && str1[i] != str2[i]){ // 1 and 3 agree, 2 differs
            total_changes += 1;
        } else if(str2[i] == str3[i] && str2[i] != str1[i]){ // 2 and 3 agree, 1 differs
            total_changes += 1;
        } else { // all three are the same
            total_changes += 0; // nothing to change (kept to show the case)
        }
    }

    printf("%d\n", total_changes); // print the answer
    return 0; // program ended successfully
}
