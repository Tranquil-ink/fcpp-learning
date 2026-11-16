#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int k, n1, n2, n3, n4, n5;
    cin >> k>>n1>>n2>>n3>>n4>>n5;
    bool b = false;
    for (int i = 1; i <= 100*k; i++){
        
        for (int a1 = 1; a1< i/n1 +2; a1++){
            int a2 = i - n1*a1;
            int a3 = i - n2*a2;
            int a4 = i - n3*a3;
            int a5 = i - n4*a4;
            if(a2 > 0&&a3>0&&a4>0&&a5>0&&((n5*a5 +a1)==i)&&a2!=a3){
                cout << i << ' '<<a1 <<' ' <<a2 <<' '<< a3<<' '<<a4<<' '<<a5;
                b = true;
                break;
            }


        }
        if (b == true) break;
    }
    if (b == false) cout << "not found";
    return 0;
}