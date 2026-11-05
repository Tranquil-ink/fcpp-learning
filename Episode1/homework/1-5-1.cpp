#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int n;
    while(cin >> n){
        vector <double> v{};
        v.push_back(1);
        int count = 0;
        do{
            v.push_back(0.5*(double(v[count]) + double(n)/double(v[count]))) ;
            count +=1;
        }while (v[count] - v[count - 1] > 1e-6 || v[count] - v[count - 1] + 1e-6 < 0);
        cout << count << ' ' ;
        cout << fixed << setprecision(2) << v[count] << endl;        
    }
    
    return 0;
}