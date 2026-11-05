#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector <int> v(100, 0);
    // vector <int> in(n, 0);
    for (int i = 0; i < n; i++){
        int k;
        cin >>k;
        v[k-1] +=1;
    }

    for (int j = 0; j < 100; j++ ){
        if (v[j] % 2 !=0){
            cout << j+1;
            break;
        }
    }
    return 0;
}