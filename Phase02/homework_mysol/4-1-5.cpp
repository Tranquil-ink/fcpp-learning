#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

using namespace std;

vector<vector<int>> v{};
vector<vector<bool>> vis{};

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};



int main() {
    int N;
    cin >>N;
    while(N--){
        int m;
        cin >>m;
        v.assign(m,vector<int>(m,0));
        vis.assign(m,vector<bool>(m,0));

        for (int i =0;i<m;i++){
            for(int j=0;j<m;j++){
                cin >>v[i][j];
            }
        }
        int ans = 0;
        for (int i =0;i<m;i++){
            for(int j=0;j<m;j++){
                if (vis[i][j]) continue;

                ans++;

                queue<pair<int,int>> q{};

                int mark = v[i][j];

                q.push({i,j});

                while(!q.empty()){
                    pair cur = q.front();
                    q.pop();
                    for (int k =0 ;k<4;k++){
                        int nx  = cur.first+dx[k];
                        int ny = cur.second+dy[k];
                        if (nx<0||ny<0||nx>=m||ny>=m) continue;
                        if (v[nx][ny]!=mark||vis[nx][ny]) continue;

                        vis[nx][ny] = 1;
                        q.push({nx,ny});

                    }
                }

                



            }
        }
        cout << ans << '\n';

    }
    
    return 0;
}