#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

// 题目描述
// 你一定听过田忌赛马的故事吧？
// 如果3匹马变成1000匹，齐王仍然让他的马按从优到劣的顺序出赛，田忌可以按任意顺序选择他的赛马出赛。赢一局，田忌可以得到200两银子，输一局，田忌就要输掉200两银子，平局的话不输不赢。
// 请问田忌最多能赢多少银子?

// 关于输入
// 输入包含多组测试数据.
// 每组测试数据的第一行是一个整数n(1<=n<=1000),表示田忌和齐王都拥有n匹马。接下来一行是n个整数，表示田忌的马的速度，下一行也是n个整数，表示齐王的马的速度。
// 输入的最后以一个0表示结束。

// 关于输出
// 对每组数据，输出一个整数，表示田忌至多可以赢多少银子，如果田忌赢不了，就输出一个负数，表示田忌最少要输多少银子。

using namespace std;

void fight(vector<int>& v1, vector<int>& v2, int i, int j, double&count){
    int k;
    for (k = j; k < v2.size(); k++){

        if (v1[i]>v2[k]){
            count +=1;
            break;
        }
        if (v1[i]==v2[k]) {
            if (i == v1.size()-1 || k == v2.size()-1) {count += 0.5; break;}
            else{
                double counttemp = 0;
                fight(v1, v2, i+1, k+1, counttemp);
                // cout << counttemp;
                if(counttemp != (v1.size()-1-k)) {
                    continue;
                }
                else {
                    count += 0.5;
                    break;
                }
            }
        }
    }
    if (i == v1.size()-1) return;
    if (k == v2.size()-1) return;

    fight(v1, v2, i+1, k+1, count);
    return;
}

int main(){
    int n;
    while(cin >> n && n!=0){
        
        vector<int> v1(n,0);
        vector<int> v2(n,0);

        for (int i = 0; i < n; i ++){
            cin >> v1[i];
        }
        for (int j = 0; j < n; j ++){
            cin >> v2[j];
        }
        sort(v1.begin(), v1.end());
        reverse(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        reverse(v2.begin(), v2.end());
        double count = 0;
        fight(v1, v2, 0, 0, count);

        cout << count*200 - (n-count)*200 << endl;
    }

    return 0;
}