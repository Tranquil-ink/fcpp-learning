#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 题目描述
给出一个正整数a，要求分解成若干个正整数的乘积，即a = a1 * a2 * a3 * ... * an，并且1 < a1 <= a2 <= a3 <= ... <= an，问这样的分解的种数有多少。注意到a = a也是一种分解。

关于输入
第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数a (1 < a < 32768)

关于输出
n行，每行输出对应一个输入。输出应是一个正整数，指明满足要求的分解的种数 */

int countways(int start, long long target){ //只选择大于等于start的因数，保证因数不降序选择
    int count = 0;
    if (target == 1) return 1;
    // if (start > target) return 0; 可以不加，start>target时不进入for循环，也返回0
    
    for(int i = start; i <= target; i++){
        if(target%i==0){
            count += countways(i, target/i);
        }
    }
    return count;
}

int main() {
    int n;
    cin >>n;
    while(n--){
        long long m;
        cin >> m;
        cout << countways(2,m)<<'\n';
    }
    
    return 0;
}