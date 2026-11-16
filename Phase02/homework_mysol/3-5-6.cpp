#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 题目描述
要过新年了，小明想给许多同学购买礼物，选好礼物结账时发现带的钱不够，所以只能选择留下一部分。
每个要送礼物的同学在他心中有个优先级，小明决定优先级最大的优先购买，他为每个人挑选的礼物价格不同，下面请你算出小明能给多少人买到礼物。

关于输入
输入有N+1行，第一行两个数字，选的礼物总数N和带的钱的总数M，后面N行每行包含两个数字，第一个数字表示礼物的价格P，第二个数字表示这个礼物要送的人在他心中的优先级L，越大越优先购买，优先级不能相同（N<100  M<1000  P<100  L<200   N,M,P,L均为整数）

关于输出
输出一行，能买的礼物个数 */

struct Friend
{
    int p;
    int l;
    bool operator< (const Friend& other) const{
        return (l> other.l);
    }
};


int main() {
    // cin
    int n,m;
    cin >> n>>m;
    vector<Friend> v{};
    while(n--){
        int p, l;
        cin >> p >> l;
        v.push_back({p, l});
    }
    sort(v.begin(), v.end());

    int sumprice = 0;
    int i;
    while(i < v.size() && sumprice<=m){
        sumprice+=v[i].p;
        i++;
    }
    if (sumprice>m) i--;

    cout << i;

    return 0;
}