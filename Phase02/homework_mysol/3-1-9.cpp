#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>


using namespace std;


int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main() {
    //接收并储存矩阵，初始化vis
    int n,m;
    cin >>n>>m;
    vector<vector<int>> v(n,vector<int>(m,0));
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
            if(v[i][j]==0||vis[i][j]) continue;

            ans++;
            vis[i][j]=true;
            queue<pair<int,int>> q{};
            q.push({i,j});
            while(!q.empty()){
                pair<int,int> cur = q.front();
                q.pop();
                for (int k =0; k <4;k++){
                    int nx = cur.first+dx[k];
                    int ny = cur.second+dy[k];
                    if (nx<0||ny<0||nx>=n||ny>=m) continue;
                    if (v[nx][ny]==0 ||vis[nx][ny] ) continue;
                    q.push({nx,ny});
                    vis[nx][ny]=true;
                }
            }
            

        }
    }
    cout << ans;
    return 0;
}