#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Pair{
    string s;
    int cnt;
};

int main() {
    
    //处理输入；建立pair的vector
    vector<Pair> v{};
    char c;
    string s{};
    while (cin.get(c)){
        if (isalpha(c)||c=='\'') s = s+c;
        else {
            if (!s.empty()) {
                bool found = false;
                for (auto &a : v){
                    if (a.s==s) {found = true;  a.cnt++;  break;}
                }
                if (found == false) v.push_back({s, 1}) ;
                s = "";
            }
        }
    }
    for (auto a :v ){
        cout << a.s << ' ' << a.cnt << '\n';
    }

    return 0;
}