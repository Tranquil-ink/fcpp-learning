#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

/* 题目描述
一个商人穿过一个 N*N 的正方形的网格，去参加一个非常重要的商务活动。从一个角进，相对的另一个角出。每穿越中间1个小方格，都要花费1个单位时间。商人必须在(2N-1)个单位时间穿越出去。在经过中间的每个小方格时，都需要缴纳一定的费用。这个商人期望在规定时间内用最少费用穿越出去。假定从左上角进，右下角出，至少需要多少费用？

注意：不能对角穿越各个小方格（即，只能行号或列号之一增减1）。

关于输入
第一行是一个整数，表示正方形的宽度N (N <100),
后面 N 行 N 列为网格上每个小方格的费用。

如：
5
1  4  6  8  10
2  5  7  15 17
6  8  9  18 20
10 11 12 19 21
20 23 25 29 33

关于输出
最小费用

上述例子中，最小值为109=1+2+5+7+9+12+19+21+33 */

// 只能向右走或向下走

vector<vector<int>> v{};
vector<vector<int>> cost{};

bool cango(vector<vector<int>> &v, int x, int y){
    return (x>=0&&y>=0&&x<v.size()&&y<v[0].size());
}

int mincost(vector<vector<int>> &v, vector<vector<int>> &cost, int x, int y){
    if (x== (v.size()-1) && y == (v[0].size()-1)) return v[x][y];
    int cost1 = 0;
    int cost2 = 0;
    if (cango(v,x+1,y)) {
        if (cost[x+1][y] == -1) cost1 = mincost(v, cost,  x+1,y) ;
        else cost1 = cost[x+1][y];
    }
    if (cango(v,x,y+1)) {
        if (cost[x][y+1] == -1) cost2 = mincost(v, cost, x,y+1) ;
        else cost2 = cost[x][y+1];
    }


    int result =  (cost1!=0&&cost2!=0) ? (min(cost1,cost2)+v[x][y]) : (max(cost1,cost2)+v[x][y]);
    cost[x][y] = result;
    return result;
}

int main() {
    int n;
    cin >> n;
    v.resize(n, vector<int>(n));
    cost.resize(n, vector<int>(n,(-1)));

    for (int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> v[i][j];
        }
    }

    cout << mincost(v,cost, 0,0);

    
    return 0;
}