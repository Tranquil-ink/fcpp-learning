#include <iostream>
#include <vector>
#include <string>
using namespace std;

int count(bool a, bool b){
    if (a &&b) return 2;
    else if (a || b) return 1;
    else return 0;

}

int main() {
    for (int a = 0; a < 3; a++){
        for (int b = 0; b < 3; b++){
            for (int c = 0; c < 3; c++){
                bool A1 = b>a;
                bool A2 = c==a;
                bool B1 = a>b;
                bool B2 = a>c;
                bool C1 = c>b;
                bool C2 = b>a;
                if (a!=b&&b!=c&&c!=a&& 
            a+count(A1,A2)==2&&b+count(B1,B2)==2&&c+count(C1,C2)==2){
                if (a == 0) cout << 'A';
                if (b == 0) cout << 'B';
                if (c == 0) cout << 'B';
                if (a == 1) cout << 'A';
                if (b == 1) cout << 'B';
                if (c == 1) cout << 'C';
                if (a == 2) cout << 'A';
                if (b == 2) cout << 'B';
                if (c == 2) cout << 'C';

            }



            }
        }

    }
    return 0;
}