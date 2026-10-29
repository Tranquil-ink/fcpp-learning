// 题目描述
// 各种语言都充满了缩略语。如汉语上的“非典（非典型性肺炎）”，“北大（北京大学）”，英语上的“SARS(Severe Atypical Respiratory Syndrome)”。假定某个字符串A中的每个字符出现在另一个字符串S中不同的位置（大小写完全相同），且字符串 A 中字符的前后关系在 S 中不发生改变，同时，A的长度小于S的长度，就认为 A 是 S 的一个可能缩略语。现在任意给定两对串，请判断前面的串是否是后面串的可能缩略语。若是，则输出 YES，否则，输出 NO

// 关于输入
// 第1行为串对数目n；
// 后面 n 行中，每行是一对字符串，其间以冒号间隔（判断左边的串是否是右边串可能的缩略语），假定左边串的长度不大于30个字符，右边串的长度不大于300个字符。

// 关于输出
// 若有n对，则有 n 行输出，每行对应判断的结果。若是可能的缩略语，输出YES；若否，输出 NO

// 如何判断？i = s1的大小；

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

bool abbre(string s1, string s2){
    int i = 0;
    for (int j = 0; j < s2.length(); j++){
        if (s2[j]==s1[i]){
            i +=1;

        }
        if (i == s1.length()) break;

    }

    return (i == s1.length()&&s1.length()<s2.length());
}

int main() {
    int n; 
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i ++){
        string line; 
        getline(cin, line);
        auto iss = istringstream(line);
        string s1, s2;
        getline(iss, s1, ':');
        // cout << s1;
        getline (iss, s2, ':');
        // cout << s2;
        if (abbre(s1, s2)==true) cout << "YES" << endl;
        else cout << "NO" << endl;


        

    }


    
    return 0;
}