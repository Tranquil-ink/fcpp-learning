#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int ran2dec (int base, string number){
    return stoi(number, nullptr, base);
}

string dec2ran (int base, int n){
    string digits = "0123456789abcdef";
    string newnum {};
    while(n>0){
        newnum += digits[n%base];
        n = n / base;
    }
    reverse(newnum.begin(), newnum.end());
    return newnum;
}

int main() {
    int b1,b2,b3;
    string n1, n2;
    cin >> b1 >> n1 >> b2 >> n2 >> b3;

    cout << dec2ran (b3, (ran2dec(b1, n1)+ran2dec(b2, n2)));
    return 0;
}