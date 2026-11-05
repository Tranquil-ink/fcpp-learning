#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Pair{
    int a;
    int b;
    bool operator< (Pair& other){
        return (a<other.a);
    }
};

//函数
void maxevents (vector<Pair>& v, int &count){
    vector<int> vb{};
    for (auto p : v){
        vb.push_back(p.b);
    }
    int tmin = *min_element(vb.begin(), vb.end());
    count +=1;

    sort (v.begin(), v.end());

    int i;
    for (i = 0; i < v.size(); i++){
        if (v[i].a >= tmin) break;
    }  // i 是第一个不用删的索引
    v.erase(v.begin(), v.begin()+i);
    if (v.empty()) return;

    maxevents(v, count);
    return;

}


int main() {

    // cin
    int n; 
    cin>> n;
    vector<Pair> v{};
    for (int i = 0; i < n; i ++){
        Pair p{};
        cin >> p.a >> p.b;
        v.push_back(p);

    }
    int count = 0;
    maxevents(v, count);
    cout << count;






    
    return 0;
}