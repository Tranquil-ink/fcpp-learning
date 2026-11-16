#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//  为了帮助佩奇,她的小伙伴给她准备一台勇气获得机。初始的时候佩奇的勇气值是0, 勇气获得机有两个按钮:

// 1、N按钮: 如果当期拥有的勇气值为x, 按下之后勇气值将变为2*x+1，

// 2、G按钮: 如果当前拥有的勇气值为x, 按下之后勇气值将变为2*x+2，

// 勇气值过高也会膨胀,所以佩奇需要将自己的勇气值恰好变为n, 请你帮助她设计一个勇气获得机的按键方案使妞妞的勇气值恰好变为n。

// 2x+1


string strat (int n){
    string s;
    if (n == 1) s += 'N';
    else if (n == 2) s += 'G';
    else{
        if (n %2 == 0) {
            s += 'G';
            s += strat((n-2)/2);
        }
        else{
            s += 'N';
            s += strat((n-1)/2);
        }
        
    }
    return s;

    
    


}

int main() {
    int n; 
    cin >> n;
    string s = strat(n);
    reverse(s.begin(), s.end());
    cout << s;


    return 0;
}