#include <iostream>
#include <vector>
#include <string>
using namespace std;

// namespace 
// // [Namespace]-(2) 0-9
// ...
// [Path]
// ...
// [Requirement]
// ...

int main() {
    string s;
    int index = 0;
    while (getline(cin, s)){
        
        if (s == "[Namespace]" || s=="[Namespace]-(0)"|| s=="[Namespace]-(1)"|| s=="[Namespace]-(2)"|| s=="[Namespace]-(3)"|| s=="[Namespace]-(4)"|| s=="[Namespace]-(5)"|| s=="[Namespace]-(6)"|| s=="[Namespace]-(7)"|| s=="[Namespace]-(8)"|| s=="[Namespace]-(9)" ){
            if (s.length() < 13) index = 10;
            else index = s[13] - '0';
            cout << "[Namespace]" << '\n';

        }

        else if (s == "[Requirement]"){
            if (index == 10) cout << s << '\n';
            else  cout << "[Requirement]-(" << index << ')' << '\n';
        }
        else cout << s << '\n';


    }
    return 0;
}