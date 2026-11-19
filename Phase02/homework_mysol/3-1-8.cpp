#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n,k;
    cin>>n>>k;
    long long result = 1;

    int s= 1;
    bool b = false;
    int m;
    
    while(s++){
        m = s*(n-1);

        for(int i =1;i<=n;i++){
      
            m += (k+m/(n-1));
            if(i==n) {b=true;break;}
            if(m%(n-1)!=0) break;
        }
        if(b==true) break;
    }

    cout << m <<'\n';
    
    return 0;
}