#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<long long> nums(n);

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    vector<long long>runningSum(n);
    runningSum[0] = nums[0];

    for(int i=1; i<n; i++){
        runningSum[i] = runningSum[i-1] + nums[i];
    }

    for(int i=n-1; i>=0; i--){
        cout << runningSum[i] << " ";
    }

    cout << endl;

    return 0;

}