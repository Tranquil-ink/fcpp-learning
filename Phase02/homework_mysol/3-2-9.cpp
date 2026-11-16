#include <iostream>
#include <vector>
#include <string>
using namespace std;


//从下标i开始往后倒元素中，选取积为target的方法数
int countsub(vector<int> &v, int i, int target){
    if (target==1) return 1;
    if (i==v.size()) return 0; //上一步没有return说明此时target不是1


    int count = countsub(v, i+1, target);
    if (v[i]!=0 && target%v[i]==0) count += countsub(v,i+1,target/v[i]);
    return count;
}

int main() {
    int T,N;
    cin>>T>>N;
    vector<int> v{};
    bool haszero = 0;
    while(N--){
        int k;
        cin >> k;
        v.push_back(k);
        if(k==0) haszero=true;
    }

    if(T==0) {cout<<(haszero ? "YES" : "NO") << endl; return 1;}

    int ans = countsub(v,0,T);
    cout<<(ans ? "YES" : "NO") << endl;
    
    return 0;
}