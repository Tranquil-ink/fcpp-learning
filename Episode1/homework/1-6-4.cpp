// 题目描述
// 在两个正整数m和n给定的整数范围内（m 小于 n，且不包括m和n）取出各位数字之和均为k的倍数的所有数(k为正整数)，然后将这些数划分成若干个子集合，每个子集合中的元素满足其各位数字之和相等，请输出各个子集合, 其中  n 不大于10000。

// 每个集合元素按从小到大输出，逗号间隔，如果有多个集合，则输出多行；各位数字之和较小的集合在前面行输出。


// 例如，m=11, n=35, k=3
// 则，
// 12,21,30 这三个数的每位数字之和均为3，且为3的倍数
// 15,24,33 这三个数的每位数字之和为6，且为3的倍数
// 18,27 这二个数的每位数字之和为9，也为3的倍数
// 由于三组数的最小数分别是12,15,18，于是，输出结果应为：
// 12,21,30
// 15,24,33
// 18,27
// 关于输入
// 一行，三个值：m,n,k，以逗号间隔

// 关于输出
// 输出各位数之和为k的倍数的若干行，每一行中，其元素的各位数字和相等，且前面行元素的各位数字之和小于后面行元素的各位数字之和，每行的元素按增序排列，以逗号间隔。

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sum_digit(int l){
    string s = to_string (l);
    int count = 0;
    for (char& c : s){
        //while (c != ',') 
        count += static_cast<int>(c - '0'); 
    }
    return count;
}

int main() {
    int n, m, k;
    char s,t;
    cin >> m >> s >> n >> t >> k;
    int max = 36 / k +1; // 最多输出的行数
    vector <vector<int>> arr (max);
    for (int i = m +1; i < n; i++){
        if (sum_digit(i) % k ==0){
            arr[sum_digit(i)/k - 1].push_back(i);
        }
    }
    // for (auto a : arr){
    //     if (!a.empty()){
    //         for (auto token : a){
    //             cout << token << ' ';
    //         }
    //         cout << '\n';
    //     }
    //因为输出中也要有逗号，不得不多写很多行...

    for (auto a : arr){
        if (!a.empty()){
            if (a.size() != 1){
                for (int j = 0; j < a.size()-1; j++){
                    cout << a.at(j) << ", ";
                }
            }
            cout << a.at(a.size()-1) << '\n';

        }
    }


    return 0;
}