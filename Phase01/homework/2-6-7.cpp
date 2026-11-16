    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>
    using namespace std;

    int countstone(vector<int> &v, int r){
        int i = 0;  //首个还没覆盖的士兵
        int j = 0;  // 扫描的指针
        int p; // 放石头的位置
        int stonecount = 0;
        int n = v.size();

        while(i<n){
            while(j<n&&(v[j]-v[i])<=r){  //注意判断顺序不能反！！否则数组越界访问
                j++;
            }
            p=j-1;
            stonecount++;

            j = p+1;
            while(j<n&&(v[j]-v[p])<=r){
                j++;
            }
            i = j;
        }
        return stonecount;
    }

    int main() {
        int r, n;

        while (cin >> r>> n &&r!=(-1)){
            vector<int> v{};
            while (n--){
                int i;
                cin >> i;
                v.push_back(i);
            }
            sort(v.begin(),v.end());
            cout << countstone(v, r) << '\n';
        }
        return 0;
    }