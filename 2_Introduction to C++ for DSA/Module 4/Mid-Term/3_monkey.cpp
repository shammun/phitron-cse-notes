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

#include <iostream>  // cin, cout, and cin.getline() for reading a whole line
#include <algorithm> // sort()
using namespace std; // write cin/cout/sort instead of std::cin/std::cout/std::sort

int main() { // program starts here
    // Plan: for each line, drop the spaces, sort the letters, print them.
    // This solution first stores every line's letters one after another in one
    // big char array, remembers where each line starts and how long it is,
    // and prints everything at the end.
    //
    // CAUTION (not a logic bug): these arrays are local variables, so they live on
    // the STACK: 200010 + 4*1000000 + 4*1000000 + 3000001 bytes = about 11 MB.
    // A normal stack is only 1 MB (Windows) or 8 MB (Linux), so this program can
    // crash with a stack overflow before reading anything. It works on this site's
    // runner because that compiles with a 256 MB stack. Fix: put `static` in front
    // of these array declarations (or move them above main) so they are not on the stack.
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
    // cin.getline(buffer, size) reads up to the '\n', throws the '\n' away, and ends
    // the text with '\0'. At end of input it fails, the while condition becomes
    // false, and the loop stops. One pass of the loop = one input line.
    while(cin.getline(current_line, 200010)){
        line_starting_position[line_number] = total_number_of_characters; // this line starts here
        int number_of_chars_in_present_line = 0; // letters kept from this line so far

        // Copy the letters, skipping every space (there may be several in a row,
        // and spaces at the end of the line too).
        // i walks the line until the '\0' that marks its end.
        for(int i=0; current_line[i] != '\0'; i++){
            if(current_line[i] != ' '){ // a letter, not a space
                all_lines_content[total_number_of_characters] = current_line[i]; // store it in the next free slot
                total_number_of_characters++;      // the next free slot moves one step right
                number_of_chars_in_present_line++; // one more letter for this line
            }
        }
        // e.g. line "i love flower": stored letters are i l o v e f l o w e r (11 of them)

        // Sort only this line's part of the big array: from where it starts up to
        // the end of what has been stored. Letters are chars, and chars compare
        // by ASCII code, so 'a' < 'b' < ... < 'z' - exactly alphabetical order.
        // sort(first, one-past-last): both are addresses inside all_lines_content.
        // "monkey" -> "ekmnoy"
        sort(all_lines_content + line_starting_position[line_number], all_lines_content + total_number_of_characters);
        total_number_of_chars_in_a_line[line_number] = number_of_chars_in_present_line; // remember this line's length
        line_number++; // one more line finished


    }

    // Print each line's sorted letters on its own line.
    // Outer loop: line i. Inner loop: the j-th letter of that line, which sits at
    // position (start of line i) + j in the big array.
    for(int i=0; i<line_number; i++){
        for(int j=0; j<total_number_of_chars_in_a_line[i]; j++){
            cout << all_lines_content[line_starting_position[i] + j]; // print one letter
        }
        cout << endl; // this line is done: move to a new line
    }

    return 0; // program ended normally
}