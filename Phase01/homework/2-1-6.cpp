#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<bool> v(n+1, true);
    for (int i = 0; i< k; i++){
        int m,n;
        cin >> m >> n;
        for (int j = m; j <=n; j++){
            v[j] = false;
        }
    }
    int count = 0;
    for (auto a : v){
        if (a == true) count +=1;
    }
    cout << count;
    return 0;
}