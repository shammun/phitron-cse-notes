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
    char current_line[200010];
    int line_starting_position[1000000];
    int total_number_of_chars_in_a_line[1000000];
    char all_lines_content[3000001];
    int total_number_of_characters = 0;
    int line_number = 0;

    while(cin.getline(current_line, 100000)){
        line_starting_position[line_number] = total_number_of_characters;
        int number_of_chars_in_present_line = 0;

        for(int i=0; current_line[i] != '\0'; i++){
            if(current_line[i] != ' '){
                all_lines_content[total_number_of_characters] = current_line[i];
                total_number_of_characters++;
                number_of_chars_in_present_line++;
            }
        }

        sort(all_lines_content + line_starting_position[line_number], all_lines_content + total_number_of_characters);
        total_number_of_chars_in_a_line[line_number] = number_of_chars_in_present_line;
        line_number++;
        

    }

    for(int i=0; i<line_number; i++){
        for(int j=0; j<total_number_of_chars_in_a_line[i]; j++){
            cout << all_lines_content[line_starting_position[i] + j];
        }
        cout << endl;
    }

    return 0;
}