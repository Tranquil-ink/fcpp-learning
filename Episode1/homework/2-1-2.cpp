#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, n1, n2;
    char a, b, c;
    for (int i = 100; i < 1000; i++){
        string s = to_string(i);
        a = s[0];
        b = s[1];
        c = s[2];

        if (a >= '7' || b >='7' || c >='7'){
            continue;
        }

        n1 = (int)(a - '0') * 7*7 + (int)(b - '0')*7 + (int)(c - '0');
        n2 = (int)(a - '0')  + (int)(b - '0')*9 + (int)(c - '0') *81;
        if (n1 == n2) {
            n = n1;
            break;
        }
    }
    int k;
    cin >>k;
    if(k ==1){
        cout << n1 << endl;
    }
    else if(k == 2) cout << a << b << c;
    else if (k==3) cout << c << b << a;
    // cout << 2 + 72 + 81 << endl;
    // cout << 1 + 56 + 98;
    
    return 0;
}