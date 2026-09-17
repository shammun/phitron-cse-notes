#include <iostream>
#include <vector>
#include <algorithm>    
#include <string>

using namespace std;

int sum_from_1_to_5(int n){
    if(n > 5){
        return 0;
    }
    return n + sum_from_1_to_5(n + 1);
}

// Print 1 to 5

void print_one_to_five(int n){
    if(n > 5){
        return;
    }
    cout << n << endl;
    print_one_to_five(n + 1);
}

void print_five_to_one(int n){
    if(n > 5){
        return;
    }
    print_five_to_one(n + 1);
    cout << n << endl;
}

int main(){
    print_one_to_five(1);
    print_five_to_one(5);

    int sum = sum_from_1_to_5(1);
    cout << "Sum from 1 to 5 is " << sum << endl;
    return 0;
}