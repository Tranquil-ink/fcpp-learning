/* 题目描述
一张画布里有n行*m列个格子，其中有的格子里有颜色填充，有的格子是空的没有颜色填充。现在需要你写一个程序来数出画布里边有颜色填充的格子构成了多少个图案，其中图案的定义为：

如果两个有颜色的格子边相邻或者角相邻（即横、纵两个方向上的位置差都不超过1），则他们属于同一个图案。

关于输入
第一行为两个整数n和m（1<=n, m<=200）。
之后的n行，每行为一个长度为m的字符串，构成了整个画布。字符串中，#表示颜色，-表示空白。

关于输出
一个整数，表示图案的个数 */

#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>


using namespace std;


int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

int main() {
    //接收并储存矩阵，初始化vis
    int n,m;
    cin >>n>>m;
    vector<vector<char>> v(n,vector<char>(m,0));
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    
    for (int i =0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    int ans = 0;
    //
    for (int i = 0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]!='#'||vis[i][j]) continue;

            ans++;
            vis[i][j]=true;
            queue<pair<int,int>> q{};
            q.push({i,j});
            while(!q.empty()){
                pair<int,int> cur = q.front();
                q.pop();
                for (int k =0; k <8;k++){
                    int nx = cur.first+dx[k];
                    int ny = cur.second+dy[k];
                    if (nx<0||ny<0||nx>=n||ny>=m) continue;
                    if (v[nx][ny]!='#' ||vis[nx][ny] ) continue;
                    q.push({nx,ny});
                    vis[nx][ny]=true;
                }
            }
            

        }
    }
    cout << ans;
    return 0;
}