#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // 处理输入
    int r, n;
    while (cin >> r>> n){
        if (r==-1&&n==-1) break;
        else {
            vector<int> v(n, 0);
            for (int i = 0; i < n; i ++){
                cin >> v[i];
            }
            // sort
            sort (v.begin(), v.end());
            // 核心
            int left = 0;
            int cur = 0;
            int result = 0;
            while (true){
                // cout << left << ' ' << cur << ' ';
                while (/* cur与left距离＜R */(v[cur]-v[left])<=r&&/* cur<最后一个元素 */cur<(v.size()-1)){
                    cur ++;
                }
                // cout << cur;
                //这时cur是下一个left，石头放在cur-1
                result ++; // put stone here

                // 如果这时cur已经到达最后，就可以结束了
                if (cur == v.size()-1) {
                    if ((v[cur]-v[left])<=r) result--;
                    break;
                }
                left = cur;
            }
            cout <<result << endl;

        }
    }

    // 

    return 0;
}
