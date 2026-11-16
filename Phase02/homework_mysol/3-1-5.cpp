#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

bool cango (vector<vector<int>> &v, int i, int j){
    if (i!=-1&&i!=v.size()&&j!=-1&&j!=v[0].size()){
        if (v[i][j]!=1) return true;
    }
    return false;
}

bool cansave(vector<vector<int>> &v, int i, int j){
    if (cango(v, i, j)&&v[i][j]==3) return true;
    int n1=0;
    int n2=0;
    int n3=0;
    int n4=0;
    v[i][j] = 1; //标记已访问，避免重复访问造成死循环
    if (cango(v, i-1, j)) n1 = (int)cansave(v, i-1, j);
    if (cango(v, i+1, j)) n2 = (int)cansave(v, i+1, j);
    if (cango(v, i, j+1)) n3 = (int)cansave(v, i, j+1);
    if (cango(v, i, j-1)) n4 = (int)cansave(v, i, j-1);
    return (bool) (n1+n2+n3+n4); 


}

int main(){
    int m, n;
    cin >> m >> n;
    int a, b;
    vector<vector<int>> v(m, vector<int>(n,0));
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> v[i][j];
            if (v[i][j]==2) {a=i; b=j;};
        }
    }




    cout << (cansave(v, a, b) ? "Yes":"No"  );






    return 0;
}