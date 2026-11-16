#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

/* 题目描述
已知 n 个正整数，wi  (1≤i≤n) 形成一个集合 W={w1,w2,...,wn}，集合中的元素彼此不相同。给定某个正整数 M ，集合W中可否存在子集，该子集的所有元素之和和恰好为M，问：这样的子集有多少个？

例如，4个正整数为：
11 13 24 7
若给定M=31，则有两个子集{7,11,13}和{7,24}
于是，这样的子集有 2 个。

关于输入
第1行，输入若干个正整数，表示集合的元素，各整数之间以空格间隔；
后面有多行，每行表示一个 M 值；若某行的 M 值为0，则结束。

关于输出
对应的每个有效的 M 值，输出相应行的子集数目 */

/* **1C 单条件变式：含负数和重复值的子集计数（自拟）。** 输入第一行 `n M`，第二行 n 个整数，
`1≤n≤20`、`-10≤a[i]≤10`、`-200≤M≤200`。输出和为 M 的非空子集数量。按下标区分对象，
即两个位置上即使同为2，选前一个与选后一个仍是不同子集；不区分同一批下标的选取先后顺序。 */

int countways(int i, long long target, vector<int> &v){
    int count = 0;
    if(i==v.size()) return target==0; 

    count += countways(i+1, target, v);
    count += countways(i+1,target-v[i],v);

    return count;
}
//另外注意特殊情况：m=0时会计算空集，如果要求不为空集，可以在main里给countways-=1


int main() {
    string line;
    vector<int> v{};

    getline(cin,line);
    istringstream iss(line);
    int k;
    while(iss>>k){
        v.push_back(k);
    }
    long long m;
    while(cin>>m&&m!=0){
        cout<<countways(0,m,v)<<'\n';
    }

    
    return 0;
}