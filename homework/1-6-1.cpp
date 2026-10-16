#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a = (n - (n % 100))/100;
    int b = (n%100 - (n%100)%10)/10;
    int c = n - 100*a - 10 * b;

    cout << a << '\n' << b << '\n' << c << endl;

    return 0;
}