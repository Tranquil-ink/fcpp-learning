#include <iostream>
#include <vector>
#include <string>
using namespace std;

//25,10,5, 1

int main() {
    int n, k, a, b, c, d;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> k;
        a = k / 25;
        b= (k % 25) / 10;
        c = (k - 25*a - 10*b) / 5;
        d = (k - 25*a - 10*b -5*c) / 1;

        cout << i+1 << ' ' << a << " QUARTER(S)," << b << " DIME(S)," << c << " NICKEL(S)," << d << " PENNY(S)" << endl;
    }
    return 0;
} 