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
#include <cstring> // Include string for character array operations (not used in this code)
using namespace std; // Use the standard namespace to avoid prefixing 'std::'

// Define a class named 'Cricketer' to encapsulate the properties of a cricketer
class Cricketer {
    public:
    int jersey_no;
    char country[100];
};

int main(){
    // Create a dynamic object named 'dhoni' of the 'Cricketer' class
    Cricketer* dhoni = new Cricketer;
    dhoni->jersey_no = 7; // Assign the jersey number 7 to 'dhoni'
    strcpy(dhoni->country, "India"); // Copy the country name "India" to the 'country' attribute of 'dhoni'

    // Create a dynamic object named 'kohli' of the 'Cricketer' class
    Cricketer* kohli = new Cricketer;
    kohli->jersey_no = dhoni->jersey_no; // Copy the jersey number of 'dhoni' to 'kohli'
    strcpy(kohli->country, dhoni->country); // Copy the country of 'dhoni' to 'kohli'

    // Delete the dynamic object 'dhoni' to free the allocated memory
    delete dhoni;

    // Print the jersey number and country of 'kohli'
    cout << "The jersey number of Kohli is " << kohli->jersey_no << " and he is from " << kohli->country << endl;

    // Delete the dynamic object 'kohli' to free the allocated memory
    delete kohli;

    return 0;

}