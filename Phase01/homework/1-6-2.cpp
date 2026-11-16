#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector <long long> a(2,0);
    vector <long long> b(2,0);
    vector <long long> c(2,0);
    vector <long long> d(2,0);

    //while (true){
        //cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1] >> d[0] >> d[1];
        //一定要确保循环可以结束！
    while (cin >> a[0] >> a[1] >> b[0] >> b[1]
               >> c[0] >> c[1] >> d[0] >> d[1]) {
        
        bool v1 = (((b[0]-a[0])*(c[1]-a[1])-(b[1]-a[1])*(c[0]-a[0]))*((b[0]-a[0])*(d[1]-a[1])-(b[1]-a[1])*(d[0]-a[0]))>0);
        bool v2 = (((c[0]-b[0])*(d[1]-b[1])-(c[1]-b[1])*(d[0]-b[0]))*((c[0]-b[0])*(a[1]-b[1])-(c[1]-b[1])*(a[0]-b[0]))>0);
        bool v3 = (((d[0]-c[0])*(a[1]-c[1])-(d[1]-c[1])*(a[0]-c[0]))*((d[0]-c[0])*(b[1]-c[1])-(d[1]-c[1])*(b[0]-c[0]))>0);
        bool v4 = (((a[0]-d[0])*(b[1]-d[1])-(a[1]-d[1])*(b[0]-d[0]))*((a[0]-d[0])*(c[1]-d[1])-(a[1]-d[1])*(c[0]-d[0]))>0);

        if (v1 == true && v2 == true && v3 == true && v4 == true) cout << "yes" << endl;
        else cout << "no" << endl;

    }

    return 0;
}