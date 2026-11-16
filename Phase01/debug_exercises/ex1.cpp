#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {  // 故意写错
        sum += a[i];
    }

    cout << sum << '\n';
    return 0;
}