// 题目描述
// Geeker对计算机和数学非常感兴趣，刚学完计概的他有一天突发奇想能不能编段小程序验证下哥德巴赫猜想，即对于任意给定的偶数m（m>=6且不超出int范围），验证其能够表示成2个奇素数之和。注意，1被认为既不是素数，也不是合数。

// 关于输入
// 一个偶数m，m的取值范围6 <= m <= 10000

// 关于输出
// 2个和是m的奇素数，它们之间用空格分隔。如果有多组满足，则每组之间需要换行（2个奇素数输出时候小的在前面，大的在后面）。每组之间没有重复，存在多个组满足的情况下按第一个奇数从小到大排列，见例子输出

// 例子输入
// 40
// 例子输出
// 3 37
// 11 29
// 17 23

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector <int> v{};
    for (int i = 3; i <= n; i++){
        bool prime = true;
        for (int j = 2; j < i; j++){
            if (i % j == 0) {
                prime = false;
                break;
            }
        }
        if (prime == true) v.push_back(i);
        
    }

    for (auto a : v){
        if (find(v.begin(), v.end(), (n-a)) != v.end() && a <= (n-a)){
            cout << a << ' ' << (n-a) << endl;
        }
    }


    return 0;
}