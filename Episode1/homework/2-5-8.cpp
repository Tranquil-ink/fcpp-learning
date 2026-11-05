#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 1顺 2逆 3中心对称 4不变 5 其他
//顺时针：(x,y) - (y,-x)   (i,j) - (i - x0,j - x0) - (j-x0,x0-i) - (j,2x0-i)
//逆时针：(x,y) - (-y, x)                          - (x0-j, i-x0) - (2x0-j, i)
// 中心点坐标：01234在index=(n-1)/2处

//判断相同的函数
bool same(vector<vector<char>>& a, vector<vector<char>>& b){
    int n = a.size();
    int r0 = (n-1)/2;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n ; j ++){
            if (a[i][j]!=b[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// 判断逆时针的函数
bool clock(vector<vector<char>>& a, vector<vector<char>>& b){
    int n = a.size();
    int r0 = (n-1)/2;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n ; j ++){
            if (a[i][j]!=b[j][2*r0 - i]) {
                return false;
            }
        }
    }
    return true;
}

//判断顺时针的函数
bool counter(vector<vector<char>>& a, vector<vector<char>>& b){
    int n = a.size();
    int r0 = (n-1)/2;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n ; j ++){
            if (a[i][j]!=b[2*r0 - j][i]) {
                return false;
            }
        }
    }
    return true;
}

//判断中心对称的函数
bool reflect(vector<vector<char>>& a, vector<vector<char>>& b){
    int n = a.size();
    int r0 = (n-1)/2;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n ; j ++){
            if (a[i][j]!=b[2*r0 - i][2*r0 - j]) {
                return false;
            }
        }
    }
    return true;
}


int main() {
    int n; 
    cin >> n;
    vector<vector<char>> a(n,vector<char>(n,0));
    vector<vector<char>> b(n,vector<char>(n,0));

    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n ; j ++){
            cin >> a[i][j];
            }
        }
    
    for (int m = 0; m < n; m ++){
        for (int k = 0; k < n ; k ++){
            cin >> b[m][k];
            }
        }
    



//判断并输出
    if (same(a, b)) cout << 4;
    else if (clock(a, b)) cout << 1;
    else if (counter(a, b)) cout << 2;
    else if (reflect(a, b)) cout << 3;
    else cout << 5;


    return 0;
}