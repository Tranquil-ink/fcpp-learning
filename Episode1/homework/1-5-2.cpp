#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int sum_digit(int l){
    string s = to_string (l);
    int count = 0;
    for (char& c : s){
        //while (c != ',') 
        count += static_cast<int>(c - '0'); 
    }
    return count;
}

int main() {
    for (int i = 100; i <= 333; i++){
        if ((sum_digit(i) + sum_digit(2*i) + sum_digit(3*i)) != 45) continue;
        vector<int> v{};
        // string s1 = to_string(i);
        // string s2 = to_string(2*i);
        // string s3 = to_string(3*i);
        string s = to_string(i) + to_string(2*i) + to_string(3*i);
        for (char&c : s){
            v.push_back(int(c - '0'));
        }
        // for (char&c : s1){
        //     v.push_back(int(c - '0'));
        // }
        // for (char&c : s2){
        //     v.push_back(int(c - '0'));
        // }
        // for (char&c : s3){
        //     v.push_back(int(c - '0'));
        // }
        // for (auto token : v){
        //     cout << token << ' ';
        // } 
        bool a = true;
        for (int j = 1; j < 10; j++)
        {
            if(find(v.begin(), v.end(), j) == v.end()){
                a = false;
                break;
            }
        }
        if (a == true) cout << i << ' ' << 2*i << ' ' << 3*i << '\n'; 
        

    }
    return 0;
}