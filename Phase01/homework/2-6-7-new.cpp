#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


// calculate
int countstone(vector<int> &v, int r){
    int i = 0;  //首个还没覆盖的士兵
    int j = 0;  // 扫描的指针
    int p; // 放石头的位置
    int stonecount = 0;

    while(i<n){
        while(j<n&&(v[j]-v[i])<=r){
            j++;
        }
        p=j-1;
        stonecount++;

        j = p+1;
        while(j<n&&(v[j]-v[p])<=r){
            j++;
        }
        i = j;

    }
    return stonecount;
    
}

int main() {
    // 处理输入
    int r, n;
    while (cin >> r >>n ){
        if (r == -1) break;
        vector<int> v(n, 0);
        for (int i =0;i<n;i++){
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        
        // output
        cout << countstone(v, r) << '\n';

    }

    return 0;


}