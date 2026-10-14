#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cin >>n;
    vector<double> v{};
    double sum = 0;
    for (int i = 0; i < n; i++){
        double k;
        cin >>k;
        v.push_back(k);
        sum +=k;
    }
    double e = sum / (double)n;
    double d0 = 0;
    for (int i = 0; i < n; i++){
        d0 += (v[i]-e)*(v[i]-e);
    }
    double d = d0 / (double)n;
    
    cout << fixed << setprecision(5) << e << ' ' << d;

    return 0;
}