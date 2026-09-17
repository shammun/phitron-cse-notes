#include<iostream> // Include the input/output stream library for using cout
#include <string>   // Include the string library for std::string
#include <sstream> // Include the stringstream library for string stream operations
#include <algorithm> // Include the algorithm library for sort function
using namespace std; // Use the standard namespace to avoid writing "std::" repeatedly

class Cricketer{
    public:
    string country;
    string name;
    int jersy;

    Cricketer(string country, string name, int jersy){
        this->country = country;
        this->name = name;
        this->jersy = jersy;
    }
};
int main() {
    Cricketer* dhoni = new Cricketer("India", "Dhoni", 100);
    cout << "Jersy number of cricketer " << dhoni->name << " is " << dhoni->jersy << endl;

    Cricketer* kohli = new Cricketer("India", "Kohli", 13);
    cout << "Jersy number of cricketer " << kohli->name << " is " << kohli->jersy << endl;

    // Copy the object dhoni to kohli
    // kohli = dhoni; // This will not work because kohli is a pointer and dhoni is a pointer
    // kohli = dhoni basically points kohli to the object dhoni

    kohli->country = dhoni->country;
    kohli->jersy = dhoni->jersy;
    delete dhoni;
    
    cout << "Jersy number of cricketer " << kohli->name << " is " << kohli->jersy << endl;

    // Another way to copy the object dhoni to kohli
    Cricketer* kohli2 = new Cricketer(dhoni->country, dhoni->name, dhoni->jersy);
    cout << "Jersy number of cricketer " << kohli2->name << " is " << kohli2->jersy << endl;
    delete kohli2;

    delete kohli;

    // Using deference to copy the object dhoni to kohli
    Cricketer* dhoni3 = new Cricketer("India", "Dhoni", 100);
    Cricketer* kohli3 = new Cricketer("India", "Kohli", 13);
    *kohli3 = *dhoni3; // Using deference to copy the object dhoni to kohli
    cout << "Jersy number of cricketer " << kohli3->name << " is " << kohli3->jersy << endl;
    delete dhoni3;
    cout << "Jersy number of cricketer " << kohli3->name << " is " << kohli3->jersy << endl;

    return 0;
}