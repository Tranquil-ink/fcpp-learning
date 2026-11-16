#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int pos[1001] {0};
    int count = 1;
    while(true){
98        int p = a % b;
        a = (a % b)*10;
        // cout << p << endl;
        if (p==0) {cout << 0; break;}
        
        if (pos[p]!=0){
            cout << count - pos[p];
            break;
        }
        else pos[p] = count;
        
        count +=1;
    }

    
    return 0;
}