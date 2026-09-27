// Topic: string "modifier" functions - functions that change a C++ string:
// +=, append, insert, push_back, pop_back, =, assign, erase, replace.
// The "(prints: ...)" notes below were checked by running this program.

#include<iostream> // Include the input/output stream library for using cout
#include<string.h>  // C-style string functions (strlen, strcpy...); not actually used in this file
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() { // program starts here
    string s = "Hello world,"; // Declare and initialize a std::string with "Hello world,"
    string s2 = " Hi";         // a second string (note the space in front)
    s += s2; // Append the string s2 to s (+= glues s2 onto the end of s)
    cout << s << endl; // Output the concatenated string (prints: Hello world, Hi)

    s.append(" there"); // Append " there" to the string s (same job as +=)
    cout << s << endl; // Output the modified string (prints: Hello world, Hi there)

    // insert(pos, text): put text in front of the character at index pos; nothing is removed.
    // Index 5 is the space after "Hello", so " C++ " goes before " world":
    s.insert(5, " C++ "); // Insert " C++ " at index 5 in the string s
    cout << s << endl; // Output the modified string (prints: Hello C++  world, Hi there - two spaces before "world")

    // S.PUSH_BACK() -- adds a single character to the end of the string
    s.push_back('!'); // Append '!' to the end of the string s (push_back takes ONE char, in single quotes)
    cout << "Using push_back(): s.push_back('!'), the result is: " << s << endl; // Output the modified string (prints: Hello C++  world, Hi there!)
    // We can also use += instead of push_back() to append a single character

    s2 = "Rahim"; // give s2 a new value
    cout << "The value of s2 is: " << s2 << endl; // prints: Rahim
    // BUG: this line changes s, not s2 - s becomes "Kello C++  world, Hi there!".
    // So the next line still prints "Rahim". To show K replacing R the line should be
    // s2[0] = 'K'; (then s2 would print "Kahim").
    // s[i] = 'c' overwrites the character at index i (the index must be inside the string).
    s[0] = 'K';
    cout << "The value of s2 after using s[0] = 'K' is: " << s2 << endl; // prints: Rahim (s2 was not touched)

    // We can't add at the end of a string using s[s.size()] = 'a' or s[i] = 'a' where i >= s.size()
    // (s[i] only overwrites existing characters; use push_back, += or append to grow the string)

    // s.pop_back() -- removes the last character from the string
    s.pop_back(); // Remove the last character from the string s (the '!')
    cout << "Using pop_back(): s.pop_back(), the result is: " << s << endl; // Output the modified string (prints: Kello C++  world, Hi there - 'K' because of s[0] = 'K' above)

    // Using equal sign operator or = we can assign new value to a string
    string s3 = "Hello";
    cout << "The value of s3 initially is: " << s3 << endl; // prints: Hello
    s3 = "Gello"; // the old text is replaced completely
    // \" inside a string literal prints a double-quote character
    cout << "The value of s3 after using s3 = \"Gello\" is: " << s3 << endl; // prints: Gello

    // We can also assign this new value to a string declared before
    s2 = s3; // s2 gets its own COPY of s3's text; changing one later does not change the other
    cout << "The value of s2 after using s2 = s3 is: " << s2 << endl; // prints: Gello

    // We can also assign a new value to a string using assign() function (same job as =)
    s3.assign("Mellon");
    cout << "The value of s3 after using s3.assign(\"Mellon\") is: " << s3 << endl; // prints: Mellon

    // We can also assign one string to another string using assign() function
    s2.assign(s3); // same as s2 = s3
    cout << "The value of s2 after using s2.assign(s3) is: " << s2 << endl; // prints: Mellon

    // erase() function is used to remove a substring from a string
    s.erase(5); // Remove all characters starting from index 5 to the end of the string
    // This is equivalent to s.resize(5)
    // s was "Kello C++  world, Hi there", so 5 characters are left:
    cout << "The value of s after using s.erase(5) is: " << s << endl; // Output the modified string (prints: Kello)

    // We can also use s.erase(1, 2) to remove 2 characters starting from index 1
    s.erase(1, 2); // Remove 2 characters starting from index 1 ("Kello" loses "el")
    cout << "The value of s after using s.erase(1, 2) is: " << s << endl; // Output the modified string (prints: Klo)

    // Fixed: there is NO s.erase(1, 2, 'x') - erase only removes. To remove 2 characters
    // from index 1 and put something in their place, use s.replace(1, 2, "x") (below).

    // s.replace() function is used to replace a substring with another substring
    // replace(pos, count, text): remove count characters starting at pos, then put text there.
    string s4 = "Hello World";
    // Go to index 6 and starting from there replace 5 characters corresponding to "World" with "Bangladesh"
    s4.replace(6, 5, "Bangladesh");
    cout << "The value of s4 after using s4.replace(6, 5, \"Bangladesh\") is: " << s4 << endl; // Output the modified string (prints: Hello Bangladesh)

    // If we don't want to delete from character 6, rather add Bangladesh at position 6, use 0 as the second argument
    cout << "The value of s4 is: " << s4 << endl; // Output the string before the change (prints: Hello Bangladesh)
    s4.replace(6, 0, "Bangladesh"); // removes 0 characters, so it only inserts - same as s4.insert(6, "Bangladesh")
    cout << "The value of s4 after using s4.replace(6, 0, \"Bangladesh\") is: " << s4 << endl; // Output the modified string (prints: Hello BangladeshBangladesh)

    // s.insert() function is used to insert a substring at a specific position in a string
    string s5 = "Hello World";
    cout << "The value of s5 is: " << s5 << endl; // Output the original string (prints: Hello World)
    s5.insert(6, "Bangladesh"); // Insert "Bangladesh" at index 6 in the string s5 (in front of 'W')
    cout << "The value of s5 after using s5.insert(6, \"Bangladesh\") is: " << s5 << endl; // Output the modified string (prints: Hello BangladeshWorld - no space is added)

    // We can use s.empty() to check if a string is empty or not
    if (s.empty()) { // true only when s has 0 characters
        cout << "The string is empty." << endl;
    } else {
        cout << "The string is not empty." << endl; // this prints: s is "Klo"
    }

    return 0; // Indicate that the program ended successfully
}
