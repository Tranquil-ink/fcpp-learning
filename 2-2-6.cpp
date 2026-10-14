#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int addbin (string s1, string s2){
    // string s1 = to_string(a);
    // string s2 = to_string(b);
    int a_dec = stoi(s1, nullptr, 2);
    int b_dec = stoi(s2, nullptr, 2);
    int sum = a_dec+b_dec;
    return sum;
}
void dectobin (int n){
    if (n==0) return;
    dectobin(n/2);
    cout << n%2;
}

int main(){
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i ++){
        string s1, s2;
        getline(cin, s1);
        getline(cin, s2);
        dectobin(addbin(s1, s2));
        cout << '\n';


    }
    cout << '\n';
}
