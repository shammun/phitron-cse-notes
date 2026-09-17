#include<iostream> // Include the input/output stream library for using cout
#include<string.h>  // Include C-style string manipulation functions (used in the commented-out section)
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

int main() {
    string s = "Hello world,"; // Declare and initialize a std::string with "Hello world,"
    string s2 = " Hi";
    s += s2; // Append the string s2 to s
    cout << s << endl; // Output the concatenated string (prints: Hello world, Hi)

    s.append(" there"); // Append " there" to the string s
    cout << s << endl; // Output the modified string (prints: Hello world, Hi there)

    s.insert(5, " C++ "); // Insert " C++ " at index 5 in the string s
    cout << s << endl; // Output the modified string (prints: Hello C++ world, Hi there)

    // S.PUSH_BACK() -- adds a single character to the end of the string
    s.push_back('!'); // Append '!' to the end of the string s
    cout << "Using push_back(): s.push_back('!'), the result is: " << s << endl; // Output the modified string (prints: Hello C++ world, Hi there!
    // We can also use += instead of push_back() to append a single character

    s2 = "Rahim";
    cout << "The value of s2 is: " << s2 << endl;
    s[0] = 'K';
    cout << "The value of s2 after using s[0] = 'K' is: " << s2 << endl;

    // We can't add at the end of a string using s[s.size()] = 'a' or s[i] = 'a' where i >= s.size()

    // s.pop_back() -- removes the last character from the string
    s.pop_back(); // Remove the last character from the string s
    cout << "Using pop_back(): s.pop_back(), the result is: " << s << endl; // Output the modified string (prints: Hello C++ world, Hi there)

    // Using equal sign operator or = we can assign new value to a string
    string s3 = "Hello";
    cout << "The value of s3 initially is: " << s3 << endl;
    s3 = "Gello";
    cout << "The value of s3 after using s3 = \"Gello\" is: " << s3 << endl;

    // We can also assign this new value to a string declared before
    s2 = s3;
    cout << "The value of s2 after using s2 = s3 is: " << s2 << endl;

    // We can also assign a new value to a string using assign() function
    s3.assign("Mellon");
    cout << "The value of s3 after using s3.assign(\"Mellon\") is: " << s3 << endl;

    // We can also assign one string to another string using assign() function
    s2.assign(s3);
    cout << "The value of s2 after using s2.assign(s3) is: " << s2 << endl;

    // erase() function is used to remove a substring from a string
    s.erase(5); // Remove all characters starting from index 5 to the end of the string
    // This is equivalent to s.resize(5)
    cout << "The value of s after using s.erase(5) is: " << s << endl; // Output the modified string (prints: Hello C++ )
    
    // We can also use s.erase(1, 2) to remove 2 characters starting from index 1
    s.erase(1, 2); // Remove 2 characters starting from index 1
    cout << "The value of s after using s.erase(1, 2) is: " << s << endl; // Output the modified string (prints: He C++ )

    // We can also use s.erase(1, 2, 'x') to remove 2 characters starting from index 1 and replace them with 'x'

    // s.replace() function is used to replace a substring with another substring
    string s4 = "Hello World";
    // Go to index 6 and starting from there replace 5 characters corresponding to "World" with "Bangladesh"
    s4.replace(6, 5, "Bangladesh");
    cout << "The value of s4 after using s4.replace(6, 5, \"Bangladesh\") is: " << s4 << endl; // Output the modified string (prints: Hello Bangladesh)

    // If we don't want to delete from character 6, rather add Bangladesh at position 6, use 0 as the second argument
    cout << "The value of s4 is: " << s4 << endl; // Output the modified string (prints: Hello Bangladesh)
    s4.replace(6, 0, "Bangladesh");
    cout << "The value of s4 after using s4.replace(6, 0, \"Bangladesh\") is: " << s4 << endl; // Output the modified string (prints: Hello Bangladesh)

    // s.insert() function is used to insert a substring at a specific position in a string
    string s5 = "Hello World";
    cout << "The value of s5 is: " << s5 << endl; // Output the original string (prints: Hello World)
    s5.insert(6, "Bangladesh"); // Insert "Bangladesh" at index 6 in the string s5
    cout << "The value of s5 after using s5.insert(6, \"Bangladesh\") is: " << s5 << endl; // Output the modified string (prints: Hello Bangladesh World)

    // We can use s.empty() to check if a string is empty or not
    if (s.empty()) {
        cout << "The string is empty." << endl;
    } else {
        cout << "The string is not empty." << endl;
    }
    
    return 0; // Indicate that the program ended successfully
}