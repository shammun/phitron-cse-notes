#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int val[1005], weight[1005];

int knapsack(int i, int max_weight){
    if(i < 0 || max_weight <= 0){
        return 0;
    }

    if(weight[i] <= max_weight){ // when we still have space in the bag, we can either take 
        // the current item or not
        int op1 = knapsack(i-1, max_weight - weight[i]) + val[i]; // taking the current item
        int op2 = knapsack(i-1, max_weight); // not taking the current item
        return max(op1, op2);
    } else{
        return knapsack(i-1, max_weight);
    }
}

int main(){
    int n, max_weight;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> val[i];
    }
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }
    cin >> max_weight;

    knapsack(n-1, max_weight);

    return 0;
}