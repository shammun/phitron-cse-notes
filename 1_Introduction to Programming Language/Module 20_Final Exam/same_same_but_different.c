/*
You will be given 3 strings each of same length consisting of only small case letters. In one operation you can change a letter to any other letter of one of the strings.

You have to find out the minimum number of operations to make all 3 strings same.

Input Format

The input will contain 3 Strings.

Constraints

1 <= Length of each string <= 100

Output Format

Print an integer, the minimum number of operations to make the strings same.

Sample Input 0

train
candy
bread
Sample Output 0

9

*/

#include <stdio.h>
#include <string.h>

int main() {
    // Declare three character arrays of size 105 to store the input strings
    // Size is 105 to accommodate strings up to length 100 plus null terminator
    char str1[105], str2[105], str3[105];
    
    // Read the three input strings
    scanf("%s", str1);
    scanf("%s", str2); 
    scanf("%s", str3);

    // Get length of first string - all strings have same length as per problem
    int len = strlen(str1);
    // Variable to keep track of minimum changes needed
    int total_changes = 0;

    // Iterate through each position of the strings
    for (int i = 0; i < len; i++) {
        // Case 1: All characters are different at position i
        // Example: str1[i] = 'a', str2[i] = 'b', str3[i] = 'c'
        // We need 2 changes to make them same - change two chars to match the third
        if(str1[i] != str2[i] && str1[i] != str3[i] && str2[i] != str3[i]){
            total_changes += 2;
        }
        // Case 2: str1 and str2 have same char, but str3 is different
        // Example: str1[i] = 'a', str2[i] = 'a', str3[i] = 'b'
        // Need 1 change - change str3 to match others
        else if(str1[i] == str2[i] && str2[i] != str3[i]){
            total_changes += 1;
        }
        // Case 3: str1 and str3 have same char, but str2 is different
        // Example: str1[i] = 'a', str2[i] = 'b', str3[i] = 'a'
        // Need 1 change - change str2 to match others
        else if(str1[i] == str3[i] && str1[i] != str2[i]){
            total_changes += 1;
        }
        // Case 4: str2 and str3 have same char, but str1 is different
        // Example: str1[i] = 'b', str2[i] = 'a', str3[i] = 'a'
        // Need 1 change - change str1 to match others
        else if(str2[i] == str3[i] && str1[i] != str2[i]){
            total_changes += 1;
        }
        // Case 5: All characters are same at position i
        // Example: str1[i] = 'a', str2[i] = 'a', str3[i] = 'a'
        // Need 0 changes as they already match
        else {
            total_changes += 0;
        }
    }

    // Print the minimum number of changes needed
    printf("%d\n", total_changes);
    return 0;
}
