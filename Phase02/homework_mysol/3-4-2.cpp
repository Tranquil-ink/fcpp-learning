#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

/* 关于输入
一行两个非负整数，非负整数s（s ≦ 10^9）和乘号的个数k（0 ≦ k < s的位数）。
输入保证，如果按题目要求的乘法操作，不会使int发生溢出。

关于输出
一行一个整数，即乘积的最大值 */

long long maxproduct(string s, long long k){
    if (s.length()==1 || k==0) return stoll(s);
    long long maximum = 0;
    for (int i = 1; i <= s.length()-1; i++){
        string s1 = s.substr(0, i);
        string s2 = s.substr(i, s.length());
        if ((k-1) >= s1.length()) continue;  //容易遗漏
        maximum =  max(maximum, (maxproduct(s1, k-1) * stoll(s2)));
    }
    return maximum;
}

int main() {
    long long k;
    string s;
    cin >> s >> k;
    cout << maxproduct(s, k);
    return 0;
}