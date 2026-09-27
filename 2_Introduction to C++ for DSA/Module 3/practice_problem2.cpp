/*

Question: Create a dynamic object named dhoni of the following class. Don’t use a constructor here, that means you need to fill the data by yourself.
Cricketer
{
	jersey_no;
	country;
}
Then make another dynamic object named kohli and copy the data of the dhoni object to kohli and after that delete the dhoni object. Then print the jersey_no and country of kohli object.
Note: At first try to do this, kohli=dhoni and see if it gives the correct output. If not, then think deeply why it didn’t work and try to copy the data manually like kohli->jersey_no=dhoni->jersey_no; 


*/

#include <iostream> // Include the iostream library for input/output operations
#include <cstring> // Include cstring for strcpy(), used to copy the country name
using namespace std; // Use the standard namespace to avoid prefixing 'std::'

// Define a class named 'Cricketer' to encapsulate the properties of a cricketer
// A class is a blueprint for a new data type. It has no constructor, so the problem's
// "fill the data by yourself" means we assign each member after creating the object.
class Cricketer {
    public: // members usable from main
    int jersey_no; // shirt number, e.g. 7
    char country[100]; // country name as a char array (up to 99 letters + '\0')
}; // semicolon ends the class definition

// Output: The jersey number of Kohli is 7 and he is from India
int main(){
    // Create a dynamic object named 'dhoni' of the 'Cricketer' class
    // new Cricketer makes one Cricketer object on the HEAP and returns its address.
    // dhoni is a pointer (Cricketer*) that stores that address. The object lives until delete.
    // Because dhoni is a pointer, its members are reached with the arrow: dhoni->jersey_no
    // (same as (*dhoni).jersey_no).
    Cricketer* dhoni = new Cricketer;
    dhoni->jersey_no = 7; // Assign the jersey number 7 to 'dhoni'
    // A char array cannot be assigned with =, so strcpy(destination, source) copies the letters and '\0'.
    strcpy(dhoni->country, "India"); // Copy the country name "India" to the 'country' attribute of 'dhoni'

    // Create a dynamic object named 'kohli' of the 'Cricketer' class
    // Why not just write kohli = dhoni? Both are pointers, so that copies only the
    // address: kohli would point at dhoni's object, and after `delete dhoni` it would
    // point at freed memory. We need a second object and a copy of each field.
    Cricketer* kohli = new Cricketer;
    kohli->jersey_no = dhoni->jersey_no; // Copy the jersey number of 'dhoni' to 'kohli'
    strcpy(kohli->country, dhoni->country); // Copy the country of 'dhoni' to 'kohli'

    // Delete the dynamic object 'dhoni' to free the allocated memory
    // delete destroys the heap object dhoni points at. kohli is untouched because it
    // is a separate object that already holds its own copy of the data.
    delete dhoni;

    // Print the jersey number and country of 'kohli'
    cout << "The jersey number of Kohli is " << kohli->jersey_no << " and he is from " << kohli->country << endl;

    // Delete the dynamic object 'kohli' to free the allocated memory
    delete kohli;

    return 0; // program finished normally

}