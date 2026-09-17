#include<iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <sstream>
#include <map>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;
    /*
    while(ss >> word){
        cout << word << endl;
    }
    */

    map<string, int> mp;
    while(ss >> word){
        mp[word]++;
    }

    for(auto it = mp.begin(); it!=mp.end(); it++){
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}