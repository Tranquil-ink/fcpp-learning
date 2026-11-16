#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v{};
    int n;
    while (cin>>n){
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    cout << v[0];
    for (int i = 1; i < v.size(); i++)
    {
        /* code */
        cout << ' ' << v[i];
    }
    
    return 0;
}