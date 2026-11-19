#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

/* 题目描述
现在有一个n阶正整数方阵（n<=7），现在可以对矩阵的任意一行进行左移，具体操作为：每次对于某一行a_i1,a_i2,…,a_in进行一次左移，
最左边的元素移动到这一行的末尾，其他元素均向左移动一位，即变为a_i2,a_i3,…,a_in,a_i1。对某一行可以执行任意次的左移。
现在我们的目标是：通过对矩阵的每一行进行若干次左移，使得矩阵中每列和的最大值最小。

关于输入
输入包含多组数据。
对于每组数据，第一行为一个正整数n（1<=n<=7），代表矩阵的阶。接下来的n行，每行n个正整数（不超过10000），代表这个矩阵。
输入数据以一个-1为结尾代表输入结束。

关于输出
对于每组数据，输出一行一个正整数，为最小的最大列和。  */

long long best = LLONG_MAX;
vector<vector<int>> v;
vector<long long> curcol;

int n;
int m;


void search(int row){
    if (row==v.size() ) {
        best = min(best,*max_element(curcol.begin(),curcol.end()));
        return;
    }
    if (*max_element(curcol.begin(), curcol.end()) >= best) return;
    for(int i =0;i<m;i++){
        for(int j=0;j<m;j++){
            curcol[j]+=v[row][(j+i)%m];            
        }
        search(row+1);
        for(int j=0;j<m;j++){
            curcol[j]-=v[row][(j+i)%m];            
        }
    }

}



int main() {
    int N;
    
    while(cin>> N&&N!=-1){
        n=m=N;
        v.assign(N,vector<int>(N,0));
        curcol.assign(N,0);

        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
                curcol[j]+=v[i][j];
            }
        }
        best = *max_element(curcol.begin(),curcol.end());
/*         curcol.assign(n,0);
        search(0); */

        // 第一行固定不移动，直接加入列和。
        for (int j = 0; j < m; ++j)
            curcol[j] = v[0][j];

        search(1);  // 从第二行开始枚举
        cout<<best<<'\n';
    }

    
    return 0;
}