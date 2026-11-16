#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* 从楼上走到楼下共有h个台阶，每一步有3种走法：
走1个台阶；走2个台阶；走3个台阶。问可以走出多
少种方案？将所有的方案输出 */


//
void Trys(int n, int& steps, vector<int> &v ){
    if(n==0) {
        cout << steps << ' ';
        for(auto a:v){
            cout<<a;
        }
        cout<<'\n';
        return;
    }
/*     if(n>=1) {
        steps++;
        v.push_back(1);
        Trys(n-1, steps, v);
        v.pop_back();
        steps--;
    }
    if(n>=2) {
        steps++;
        v.push_back(2);
        Trys(n-2, steps, v);
        v.pop_back();
        steps--;
    }
    if(n>=3) {
        steps++;
        v.push_back(3);
        Trys(n-3, steps, v);
        v.pop_back();
        steps--;
    } */
   //简化写法：
    for(int j = 3; j>0;j--){
        if(n<j) continue;
        steps++;
        v.push_back(2);
        Trys(n-2, steps, v);
        v.pop_back();
        steps--;
   }

}

int main() {
    int h;
    cin>>h;
    int steps=0;
    vector<int> v{};
    Trys(h,steps,v);


    
    return 0;
}