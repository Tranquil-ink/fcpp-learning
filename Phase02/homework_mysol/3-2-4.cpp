/* 题目描述
在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能
放在棋盘中的同一行或者同一列，请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。

关于输入
输入含有多组测试数据。
每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8 , k <= n
当为-1 -1时表示输入结束。
随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域， . 表示空白区域（数据保证不出现多余的空白行或者空白列）。

关于输出
对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2^31）。 */


#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countways(int k, int row, vector<bool> &usedcol, int &n_usedcol, vector<string> &v){
    int count = 0;
    if (n_usedcol == k) return 1;
    if(row==v.size()) return (n_usedcol==k);


    for(int j =0;j<v[0].length();j++){
        if(v[row][j]=='#'&&!usedcol[j]){
            usedcol[j]=true;
            n_usedcol++;
            count += countways(k, row+1,usedcol, n_usedcol,v);
            usedcol[j]=false;
            n_usedcol--;
        }
    }
    count+= countways(k, row+1,usedcol, n_usedcol,v);
    return count;
}
int main() {
    int n,k;
    while(cin>>n>>k&&k!=(-1)){
        vector<string> v(n);
        vector<bool>usedcol(n,false);
        int n_usedcol=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        cout<<countways(k, 0,usedcol, n_usedcol,v)<<'\n';
    }

    
    return 0;
}