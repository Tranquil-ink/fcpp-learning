#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

/* 已知 n 个正整数，wi  (1≤i≤n) 形成一个序列 W={w1,w2,...,wn}，元素可以相同。给定某个正整数 M ，
W中可否存在子集，该子集的所有元素之和和恰好为M，问：这样的子集有多少个？ */

// 输入：表示当前子集的subset,避免子集元素重复的哈希集合used,从第i个开始找，当前还需要的元素和target
int countsearch(const vector<int> &v, vector<int> &subset, unordered_set<int> &used, int i, int &target){
    //什么时候会结束？若target为0则返回；target为i越界1格时，判断target是否为0；
    if (target==0){
        for(auto a : subset){
            cout<<a;
        }
        cout<<'\n';
        return 1;
    } 
    if(target<0) return 0;
    if(i==v.size()) return 0; 

    int count = 0;
    count += countsearch(v,subset,used,i+1,target); //当前元素不选
    if(used.count(v[i])==0){
        used.insert(v[i]);
        subset.push_back(v[i]); 
        target -=v[i];
        count += countsearch(v,subset,used, i+1,target);
        target+=v[i];
        subset.pop_back();
        used.erase(v[i]);
    }

    return count;
}

int main() {
    int n,target;
    cin>>n>>target;
    vector<int>v{};
    vector<int> subset{};
    unordered_set<int> used{};

    while(n--){
        int member;
        cin>>member;
        v.push_back(member);
    }
    cout<<countsearch(v,subset,used,0,target);


    
    return 0;
}