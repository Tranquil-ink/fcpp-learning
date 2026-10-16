#include <iostream>
#include <vector>
#include <string>
using namespace std;

// int phi(int l){
//     int count = 0;
//     for (int i = 1; i < l; i++){
//         if (l % i == 0) count += i;
//     }
//     return count;
// }

int main() {
    int n;
    cin >> n;
    vector <int> v(n+1, 0);
    // for (int i = 1; i <= n; i++)
    // {
    //     v[i] = phi(i);
    // }
    for (int d = 1; d <= n; d ++){
        for (int k = 2*d; k <= n; k +=d){
            v[k] += d;
        }
    }

    
    for (int i = 1; i <= n; i++){
        int j = v[i];
        if (j > i && j <= n && v[j] == i){
            cout << i << ' ' << j << endl;
        }
    }
    return 0;
}