#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;



int main() {
    int n;
    cin >>n;

    
    long long a = 1;
    long long b = 1;
    for(int i = 1;i<=n;i++){
        if (i==1||i==2) cout << setw(10) << 1;
        else{
            cout << setw(10)<<(a+b);
            long long c = a+b;
            b = a;
            a = c;
        }

        if (i%5==0) cout << '\n';
    }

    
    return 0;
}