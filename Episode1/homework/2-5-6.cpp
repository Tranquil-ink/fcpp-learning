#include <iostream>

#include <vector>
#include <string>
using namespace std;

// 题目描述
// N个人围成一圈玩传球游戏。开始时，第一个人拿着球。每个人把球传给左手的第K个人，其中，1 <= K <= N/2。计算最大的K，使得第一个人重新拿到球之前，每个人都拿过球。

// 关于输入
// 正整数N，假定N的值大于2，N≤300010

// 关于输出
// K的最大值

bool validity(int n, int k){
    vector<bool> v(n, false);
    int i = 0;
    while (v[0]==false){
        if ((i + k) < v.size()) i = i+k;
        else i = i + k - v.size();
        v[i] = true;
    }
    for(auto a : v){
        if (a == false) return false;
    }
    return true;
    
}


int main() {
    int n;
    cin >> n;
    for (int i = n/2; i >0; i--){
        if (validity(n, i) == true){
            cout <<i;
            break;
        }
    }
    
    return 0;
}