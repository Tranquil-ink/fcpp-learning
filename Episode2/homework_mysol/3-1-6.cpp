#include <iostream>
#include <vector>
#include <string>
using namespace std;

double poly(int n, int x){
    if (n==0) return (double)1;
    if (n==1) return (double)x;
    return (((double)((double)((2*n)-1)*x)*poly(n-1, x))- (double)(n-1)*poly(n-2, x))/(double)n;
}

int main() {
    int n, x;
    cin >> n >> x;
    cout << poly(n, x);
    return 0;
}