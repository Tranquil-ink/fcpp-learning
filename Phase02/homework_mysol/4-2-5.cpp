#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/* 题目描述
编辑距离是针对二个字符串的差异程度的量化量测，量测方式是看至少需要多少次的处理才能将一个字符串变成另一个字符串。
本题要求写一个单词拼写检查器，具体做法是，根据一个含有正确单词的字典，检查某些单词是否正确，如果不正确，则找出字典中与其编辑距离为1的单词。
使一个单词与其编辑距离为1，修改方法可以是：
1. 删除词中的一个字母
2. 用任意其他字母替换词中的一个字母
3. 在词的任意位置插入一个字母

关于输入
字典最多有10000个单词，输入时每个单词占一行，以“#”结尾，无重复单词。
字典后为要检查的单词，每个单词占一行，以“#”结尾，最多30个待检查。

关于输出
对于每一个单词x，
如果在字典中，则输出"x is correct"，占一行；
若不在字典中，则输出"x:"+字典中所有编辑距离为1的词；
如果无法找到相应的词，则输出"x:" */


vector<string> dict{};
vector<string> targets{};

//issimilar
bool issimilar(string s1, string s2){
    if (s1.length() < s2.length()) {
        string temp = s1;
        s1 = s2;
        s2 = temp;
    }
    // s1 >= s2 in length
    if ((s1.length() - s2.length()) >=2) return false;
    if ((s1.length() - s2.length()) ==1) {
        if (s1.substr(0,s2.length())==s2 || s1.substr(1,s2.length())==s2) return true;
        if (s1.length()>=3){
            for (int i = 1; i < s1.length()-1;i++){
                if ((s1.substr(0,i)+s1.substr(i+1,s1.length()-i-1))==s2) return true;
            }
        }
    }
    else {
        int cnt = 0;
        for (int i =0; i < s1.length();i++){
            if (s1[i]==s2[i]) cnt++;
        }
        if (cnt ==s1.length()-1) return true;
    }
    return false;


}



//vector similarwords()

int main() {
    string s;
    while(cin>>s){
        if (s[0]=='#') break;
        dict.push_back(s);
    }
    while(cin>>s){
        if (s[0]=='#') break;
        targets.push_back(s);
    }
    for (auto a : targets){
        if (find(dict.begin(), dict.end(),a)!=dict.end()) cout << a <<" is correct\n";
        else{
            cout << a<< ": ";
            vector<string> similar{};
            for (auto b : dict){
                if (issimilar(b,a)) similar.push_back(b);
            }
            for (auto c : similar) {cout << c << ' ';}
            cout << '\n';
        }
    }

    return 0;
}