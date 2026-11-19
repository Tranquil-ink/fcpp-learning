#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool result(int a, int b) /* //a>=b */{
    if (b==0) return false;
    if (a/b >= 2) return true;
    return (!result(b,a-b));
}

int main() {
    int m,n;
    while(cin>>m>>n &&m!=0){
        int a = max(m,n);
        int b = min(m,n);

        cout<< (result(a,b) ? ("win") : "lose")<<'\n';
    }
    
    return 0;
}