#include <iostream>
#include <vector>
#include <string>
using namespace std;

void flip(string s){
    for (int i = s.size()-1; i >=0; i--){
        cout << s[i];
    }

}

int main() {
    string s;
    // cin >> s;

    // flip (s);
    while (cin.peek()!=EOF){
        if (cin.peek()==' '){
            cout << ' ';
            cin.ignore();
        }
        else {
            if(cin >>s)
            // cout << ' ';
            flip(s);
            

        }
    }
    return 0;
}