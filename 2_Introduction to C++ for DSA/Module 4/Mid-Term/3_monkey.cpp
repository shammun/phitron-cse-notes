/*

Problem Statement:

Amena has just learned alphabets. She can read write from a to z only in lowercase. But, Amena always writes in alphabetic order (alphabetic order means from a to z in sorted order) what she saw. Also she writes a line as a word. For example, she writes monkey as ekmnoy. Her mother wants to test her reading and writing skills. Her mother gave her some lines, can you tell what she will write?

Note: Input will be given by EOF.

Input Format

Input consist of a line S. The line will contain lowercase letters and spaces. It is possible that there are multiple spaces together and the line end with spaces.
Constraints

1 <= |S| <= 10^5
Output Format

Output what Amena will write.
Sample Input 0

monkey
i love flower
Sample Output 0

ekmnoy
eefilloorvw

*/

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Plan: for each line, drop the spaces, sort the letters, print them.
    // This solution first stores every line's letters one after another in one
    // big char array, remembers where each line starts and how long it is,
    // and prints everything at the end.
    char current_line[200010];                    // the line being read right now
    int line_starting_position[1000000];          // where line k starts inside all_lines_content
    int total_number_of_chars_in_a_line[1000000]; // how many letters line k kept
    char all_lines_content[3000001];              // the letters of all lines, back to back
    int total_number_of_characters = 0;           // letters stored so far = next free position
    int line_number = 0;                          // how many lines have been read

    // Input ends at EOF, so keep reading while getline succeeds.
    // cin.getline reads the whole line, spaces included (plain cin >> would stop
    // at the first space). The limit is the buffer size, so a line of 10^5
    // letters plus its '\0' still fits.
    while(cin.getline(current_line, 200010)){
        line_starting_position[line_number] = total_number_of_characters; // this line starts here
        int number_of_chars_in_present_line = 0;

        // Copy the letters, skipping every space (there may be several in a row,
        // and spaces at the end of the line too)
        for(int i=0; current_line[i] != '\0'; i++){
            if(current_line[i] != ' '){
                all_lines_content[total_number_of_characters] = current_line[i];
                total_number_of_characters++;
                number_of_chars_in_present_line++;
            }
        }

        // Sort only this line's part of the big array: from where it starts up to
        // the end of what has been stored. Letters are chars, and chars compare
        // by ASCII code, so 'a' < 'b' < ... < 'z' - exactly alphabetical order.
        sort(all_lines_content + line_starting_position[line_number], all_lines_content + total_number_of_characters);
        total_number_of_chars_in_a_line[line_number] = number_of_chars_in_present_line;
        line_number++;
        

    }

    // Print each line's sorted letters on its own line
    for(int i=0; i<line_number; i++){
        for(int j=0; j<total_number_of_chars_in_a_line[i]; j++){
            cout << all_lines_content[line_starting_position[i] + j];
        }
        cout << endl;
    }

    return 0;
}