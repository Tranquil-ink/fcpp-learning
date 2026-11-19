#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 题目描述
Michael喜欢滑雪这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，你不得不再次走上坡或者等待升降机来载你。
Michael想知道载一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子

1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24-17-16-1。当然25-24-23-...-3-2-1更长。
事实上，这是最长的一条。

关于输入
输入的第一行表示区域的行数R和列数C(1 <= R,C <= 100)。下面是R行，每行有C个整数，代表高度h，0<=h<=10000。

关于输出
输出最长区域的长度。 */

//记忆化搜索

int nx[] = {1,0,-1,0};
int ny[] = {0,1,0,-1};

int dfs(int x,int y, vector<vector<int>> &mem, vector<vector<int>> &v){
    if(mem[x][y]!=-1) return mem[x][y];

    int maxlength = 1;
    for(int i=0;i<4;i++){
        int x1 = x+nx[i];
        int y1 = y+ny[i];
        if(x1>=0&&x1<mem.size()&&y1>=0&&y1<mem[0].size()){
            if(v[x1][y1]<v[x][y])
                maxlength = max(maxlength,dfs(x1,y1,mem,v));
        }
    }
    mem[x][y]=maxlength;
    return maxlength;
}



int main() {
    int r,c;
    cin>>r>>c;
    vector<vector<int>> mem(r,vector<int>(c,-1));
    vector<vector<int>> v(r,vector<int>(c,-1));
    int maxresult = 0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>v[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            maxresult = max(maxresult,1+dfs(i,j,mem,v));
        }
    }
    cout<<maxresult;


    
    return 0;
}