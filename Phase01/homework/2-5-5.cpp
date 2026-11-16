#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// 关于输入
// 输入为2行
// 第一行为n，为等待看病的人数(n<=1000)
// 第二行分别表示第一位病人到第n位病人的诊断时间T1，T2，…，Tn，每个数据间有一个空格

// 关于输出
// 输出为2行
// 第一行为一种排队顺序，即1到n的一种排列
// 第二行为这种方案下的平均等待时间（精确到小数点后两位）

struct Pair
{
    int t;
    int index;

    bool operator< (Pair& other){
        return (t < other.t);
    }

};


int main() {
    int n; 
    cin >> n;
    vector <Pair> v{};
    for (int  i = 1; i <= n; i++){
        Pair p;
        cin >> p.t;
        p.index = i;
        v.push_back(p);
        
    }
    sort (v.begin(), v.end());
    int sum  = 0;
    int accusum = 0;

    // for (auto a : v){
    //     sum += a.t;
    //     accusum += sum;
    //     // cout << a.index << ' ';
        
    // }
    cout << v[0].index;
    for (int i = 1; i <n; i++){
        cout << ' ' << v[i].index;

    }
    for (int i = 0; i < n ; i ++){
        sum += (n-1-i)*v[i].t;
    }
    cout << endl;
    cout << fixed << setprecision(2) << double(sum)/double(n);


    
    return 0;
}