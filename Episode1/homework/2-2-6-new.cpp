// 题目描述
// 给定两个二进制数 a 和 b ，计算 a + b 之和，输出和的二进制表示。

// 关于输入
// 输入有 2n + 1 行，第一行是 n，其余2n行，每两行一组，第一行是二进制数 a，第二行是二进制数 b；a 和 b 都大于 0 且不含前导 0 ，a、b 的位数不超过 100 位。

// 关于输出
// 输出 n 行 a + b 的结果，用二进制表示。

// 例子输入
// 2
// 1110011
// 11111111000
// 1010101
// 101010
// 例子输出
// 100001101011
// 1111111
// 提示信息
// 如果 Wrong Answer，考虑 int（甚至 long long int）类型能不能存得下两个很大的二进制数 a，b 的十进制表示。可以改用 char 数组，数组的每个元素保存一个二进制位。

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addbin (string a, string b){
    // 如果1+0=0存一个数组，1+1要进位a.size()
    int ex = 0;
    int n1 = a.size();
    int n2 = b.size();
    a = '0' + a;
    b = '0' + b;
    if (n1 < n2){
        string repeated((n2-n1), '0');
        a = repeated + '0' + a;
    }
    if (n1 > n2){
        string repeated((n1-n2), '0');
        b = repeated + b;
    }
    vector<int> v{};
    for (int i = a.size()-1; i >=0; i--){
        switch(a[i]-'0'+b[i]-'0'+ex){
       
            case 0: 
                v.push_back (0);
                ex = 0;
                break;
            case 1:
                v.push_back(1);
                ex = 0;
                break;
            case 2:
                v.push_back(0);
                ex = 1;
                break;
            case 3:
                v.push_back(1);
                ex = 1;
                break;

        }
    }
    if (v[v.size()-1] == 1) cout << 1;

    for (int i = v.size()-2; i>=0; i--){
        cout << v[i];
    }
    cout << '\n';



}

int main() {
    int n;
    cin >> n;
    for (int i = 0;i< n; i++){
        string s1,s2;
        cin >> s1 >> s2;
        addbin(s1, s2);
    }
    return 0;
}