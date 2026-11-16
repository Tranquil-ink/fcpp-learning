#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

/* 题目描述
求一个 m 级矩阵的所有行列连续的子矩阵中元素和最大者。

关于输入
第一行为正整数 m，m ≤ 4。从第二行起按行输入该矩阵。

关于输出
按行输出子矩阵。最后一行输出这个子矩阵的所有元素之和。 */

vector<vector<int>> v{};

//函数：取出子阵，求和
int sumpart(vector<vector<int>> &v, int x, int y, int lengthx, int lengthy){
    int sum = 0;
    for (int i = x; i < x+lengthx; i++){
        for (int j = y;j<y+lengthy;j++){
            sum+=v[i][j];
        }
    }
    return sum;

}

void coutpart(vector<vector<int>> &v, int x, int y, int lengthx, int lengthy){
        for (int i = x; i < x+lengthx; i++){
        for (int j = y;j<y+lengthy;j++){
            cout << v[i][j];
            cout << ((j==(y+lengthy-1)) ? '\n' : ' ');
        }
    }
}

int main() {
    //cin,resize
    int m; 
    cin >> m;
    v.resize(m,vector<int>(m));
    for (int i = 0;i<m;i++){
        for(int j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
    int maxsum = 0;
    int x0 = -1;
    int y0 = -1;
    int lengthx0 = -1;
    int lengthy0 = -1;

    for (int lengthx = 1; lengthx <=m; lengthx++){
        for(int lengthy = 1; lengthy <=m; lengthy++)
        for (int x = 0; x <=(m-lengthx);x++){
            for(int y=0;y<=(m-lengthy);y++){
                int newsum = sumpart(v,x,y,lengthx, lengthy);
                if (newsum > maxsum){
                    maxsum = newsum;
                    x0 = x;
                    y0 = y;
                    lengthx0 = lengthx;
                    lengthy0 = lengthy;
                }

            }
        }
    }
    coutpart(v, x0,y0,lengthx0, lengthy0);
    cout << maxsum;





    //遍历子阵，扫描max
    
    return 0;
}