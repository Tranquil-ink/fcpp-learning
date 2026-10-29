// 题目描述
// // 有三个字符串S,S1,S2，其中，S长度不超过300,S1和S2的长度不超过10，想检测S1和S2是否同时在S中出现，且S1位于S2的左边，并在S中互不交叉
// （即，S1的右边界点在S2的左边界点的左侧）。计算满足上述条件的最大跨距（即，最大间隔距离：最右边的S2的起始点与最左边的S1的终止点之间的字符数目）。
// 如果没有满足条件的偶对S1，S2存在，则输出 -1

// 例如，S = "abcd123ab888efghij45ef67kl", S1="ab", S2="ef"，其中，S1在S中出现了2次，S2也在S中出现了2次，最大跨距则为：18

// 关于输入
// 三个串：S, S2, S3，其间以逗号间隔（注意，S, S2, S3中均不含逗号）；

// 关于输出
// S1和S2在S最大跨距；若在S中没有满足条件的S1和S2，则输出-1

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);
    auto iss = istringstream(line);
    string s, s1, s2;
    getline(iss, s, ',');
    getline(iss, s1, ',');
    getline(iss, s2, ',' );

    size_t pos1_0 = s.find(s1);
    size_t pos2 = s.rfind(s2);
    if (pos1_0 == string::npos || pos2 == string::npos) {
        cout << -1;
        return -1;
    }
    size_t pos1 = pos1_0 + s1.length() - 1;
    if (pos2 <= pos1){
        cout << -1;
        return -1;
    }
    cout << pos2 - pos1 -1;
    






    

    return 0;
}