#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

    // 判断相差日子数量 m，n要从m加到n-1
bool related(int m1, int m2, int year){
    vector<int>arr{0,31,28,31,30,31,30,31,31,30,31,30,31};
    int mini = min(m1, m2);
    int maxi = max(m1, m2);
    int days =  0;
    for (int i = mini; i < maxi; i++){
        days += arr[i];
    }
    if (((year%4==0&&year%100!=0)||year%400==0)&&mini<=2&&maxi>2){
        days++;
    }
    // cout << days << ' '; ////
    return(days%7==0);
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
    int year, m, n;
    cin >> year >> m >> n;
    if (related(m, n, year)) cout << "YES";
    else cout << "NO";
    cout << endl;

    }
    




    //处理输入

    return 0;
}