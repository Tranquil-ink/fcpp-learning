// 题目描述
// 小朋友玩跳绳比赛,要计算在一分钟内跳了多少下.假设每秒钟跳一下,如果中途失败了,则要花三秒钟后才能开始重跳.一般小朋友跳绳一分钟要跳坏好几次.现在给出小朋友每次跳坏时已经跳的总数,求小朋友在一分钟内跳了多少下.(请注意分析示例数据.)

// 关于输入
// 第一行为n个小朋友
// 其余各行,每行第一个整数是跳坏的次数m,其余m个整数是跳坏时累计跳了多少下. 这m个整数是从小到大排列的

// 关于输出
// 输出相应小朋友第一分钟内跳了多少下。

// 例子输入
// 6
// 0
// 3 12 23 45 
// 1 17
// 4 10 20 30 40
// 5 10 20 30 40 58 
// 6 10 20 30 40 47 60
// 例子输出
// 60
// 51
// 57
// 48
// 48
// 47
// 提示信息
// 提示，在跳绳比赛时，你可能已经超时了，而自己还在计数，但裁判已经停止计时并得到成绩了。这里相当于自己给自己计的数。因此，并非跳坏的时候都是在前一分钟以内。请注意分析示例数据。

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int times (vector<int> v, int n){
    

    int temp = v[n] + 3*n;
    if (temp + 3 <= 60 ) return (60 - 3*(n+1));
    else if (temp <= 60 ) return (v[n]);
    else return times(v, n-1);
}

int main() {
    int n, k;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >>k;
        if (k == 0) {
            cout << 60 << endl;
            continue;
        }
        vector <int> v1{};
        for (int j = 0; j < k; j++){
            int m;
            cin >> m;
            v1.push_back(m);
        }

        // if ((v1[k-1] + 3*(k-1)) <= 60) cout << (v1[k-1]) << endl;
        // else 
        cout << times(v1, k-1) << endl;
    }
    
    return 0;
}