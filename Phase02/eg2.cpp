#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 有编号分别为0、1，2，3，4的五本书，准备分给
A,B,C,D,E五个人，每人一本，每个人的阅读兴趣用
一个二维数组来描述
u请写一个程序，输出所有分书方案，让人人皆大欢喜 */

//abcde用01234来表示
//interest表示兴趣
//v表示当前方案
//i表示当前要分第i本书

string s = "ABCDE";
const int N = 5;
vector<vector<int>> interest(N,vector<int>(N,0));

void search(vector<int> &v, const vector<vector<int>> &interest, int i){
    if(i==5){
        for(int j = 0;j<N;j++){
            cout<<v[j];
        }
        cout << '\n';
        return;
    }
    for(int k =0;k<5;k++){ //k表示将i书分给第k人
        if(interest[i][k]==0) continue;
        
        v.push_back(k);
        search(v,interest,i+1);
        v.pop_back();

    }
}

int main() {
    vector<int> v{};
    for(int i = 0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>interest[i][j];
        }
    }
    search(v,interest,0);
     
    return 0;
}