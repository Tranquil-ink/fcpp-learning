#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 题目描述
给定一个长度为n的数组，从其中任意选择不相邻的m个元素形成子数组，求这个子数组所有元素之和的最大值。

关于输入
输入包括两行。
第一行为一个正整数n(0<=n<=10000)。
第二行为n个整数，表示整个数组。

关于输出
输出一个数字，代表数组所有不相邻元素之和的最大值。 */

vector<vector<int>> dp{};
vector<int> v;


int main() {
    int n;
    cin>>n;
    dp.resize(n+1,vector<int>(n+1,0));
    v.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            if(i<j) {dp[i][j]=0; continue;} //可以不加？
            
            if(i-2<0) {dp[i][j]= max(dp[i-1][j],v[i]); continue;}
            dp[i][j] = max(dp[i-1][j],(dp[i-2][j-1]+v[i]));
        }
    }
    cout << *max_element(dp[n].begin(),dp[n].end())<<endl;
    
    return 0;
}