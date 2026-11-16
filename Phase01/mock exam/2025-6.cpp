#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 题目描述
// 给出一个 1∼n 的排列，询问存在多少个数 i(1≤i≤n-1) 满足前 i 个数和后 n-i 个数排序后都是等差数列。
// 数据范围：1≤n≤1000。

// 关于输入
// 本题有多组数据，第一行一个正整数 T，表示数据组数。
// 对于每组数据：第一行一个正整数 n。第二行 n 个正整数表示排列。

// 关于输出
// 对于每组数据：一行一个整数，表示答案。



int main(){
    int n; 
    cin >> n;
    for (int i = 0; i < n; i ++){
        // store input
        int m;
        cin >> m;

        vector<int> v(m, 0);
        for (int j=0;j<m;j++){
            cin >> v[j];
        }

        // special cases
        if (m==1) {cout << 0 << endl; continue;}
        if (m ==2) {cout << 1 << endl; continue;}
        if (m ==3) {cout << 2 << endl; continue;}

        // case 1 一边严格大于另一边，公差均为1
        int count = 0;
        if (v[0]==m||v[0]==1) {count ++;}
        if (v[m-1]==m||v[m-1]==1) {count ++; }

        for (int k = 1; k<(m-2); k++){
            // cout << *max_element(v.begin(),v.begin()+k);
            if (*max_element(v.begin(),v.begin()+k+1)==(k+1)||*min_element(v.begin(),v.begin()+k+1)==(m-k)) {count++;/*  cout << +1; */}
        }
        // case 2  关于中心点对称，两边分别全奇/偶数
        if (m%2==0){
            bool b = true;
            for (int t = 0; t <= (m-2)/2; t++){
                if(v[t]%2==0) {b = false;break;}
            }
            if (b==true) count ++;
            bool c = true;
            for (int t = 0; t <= (m-2)/2; t++){
                if(v[t]%2!=0) {c = false;break;}
            }
            if (c==true) count ++;
        }

        else{
            bool b = true;
            for (int t = 0; t <= (m-1)/2; t++){
                if(v[t]%2==0) {b = false;break;}
            }
            if (b==true) count ++;
            bool c = true;
            for (int t = 0; t <= (m-3)/2; t++){
                if(v[t]%2!=0) {c = false;break;}
            }
            if (c==true) count ++;
        }

        // case 3 (1, m)/(2,...,m-1)
        if ((v[0]==1&&v[1]==m)||(v[0]==m&&v[1]==1)||
            (v[m-1]==1&&v[m-2]==m)||(v[m-2]==1&&v[m-1]==m)) count ++; 


        cout << count << endl;
    }



    return 0;
}