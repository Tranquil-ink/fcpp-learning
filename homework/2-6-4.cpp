#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

// 题目描述
// 计算机信息管理免不了要涉及到文本处理的问题，而在众多处理方式中对一句（段）话中单词数的统计是非常基本也是十分重要的一个环节。

// 关于输入
// 一句话，由英文字母，数字及常用标点符号组成。

// 关于输出
// 统计句子中各单词出现的次数，并按单词在句子中第一次出现的顺序输出。
// 输出包括若干行，每一行是一个单词，空格再跟着该单词在句子中出现的次数。

using namespace std;

bool isword (string s){
    char c = s[s.length()-1];
    return ((c>='a'&&c<='z')||(c>='A'&&c<='Z'));
}

struct Pair {
    string s;
    int n;
};

int main(){

    string s;
    vector<Pair> v{};
    vector<string> vs{};
    while (cin >>s && s!="cs"){
        if (!isword(s)) s.erase(s.length()-1);
        if (find(vs.begin(), vs.end(), s) == vs.end()){
            Pair p{s, 1};
            v.push_back(p);
            vs.push_back(s);
        }
        else {
            v[find(vs.begin(), vs.end(), s)-vs.begin()].n+=1;
        }

    }

    for (auto a : v){
        cout << a.s << ' ' << a.n << endl;
    }


    return 0;
}