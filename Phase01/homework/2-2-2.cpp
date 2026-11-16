#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    char c;
    int n1=0;
    int n2=0;
    int n3=0;
    while(cin >>c){

        if (c>='A' && c <= 'Z'){
            n1 +=1;
        }
        else if (c>='a' && c<='z') n2+=1;
        else if (c>= '0'&& c<='9') n3+=1;
    }



    cout << n1 << ' ' << n2 <<' ' << n3;
    return 0;
}