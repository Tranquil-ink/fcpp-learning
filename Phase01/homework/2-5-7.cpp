// 题目描述
// 输入4行全部由大写字母组成的文本，输出一个垂直直方图，给出每个字符出现的次数。注意：只用输出字符的出现次数，不用输出空白字符，数字或者标点符号的输出次数。

// 关于输入
// 输入：包括4行由大写字母组成的文本，每行上字符的数目不超过80个。

// 关于输出
// 输出：包括若干行。其中最后一行给出26个大写英文字母，这些字母之间用空格隔开。前面的几行包括空格和星号，每个字母出现几次，就在这个字母的上方输出一个星号。
// 注意：输出的第一行不能是空行。每行的末尾不能有空格。每行以#开始

// 列表记录字母的次数；一个列表用来记录最后一个达到高度的字符是哪个；注意不要漏掉＃


#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {
    string l1, l2, l3, l4;
    getline(cin, l1);
    getline(cin, l2);
    getline(cin, l3);
    getline(cin, l4);

    string s = l1+l2+l3+l4;
    // cout << s << ' '; ////
    vector<int> v(26, 0);
    for (char a : s){
        if (a - 'A' >=0 && a - 'Z' <=0){
            v[a - 'A'] +=1;
        }
    }
    // for (auto a : v) {cout << a;} ////////////
    vector<int> arr(1, 0);
    int h = 1;
    while(true){

        for (int i = 25; i >=0; i --){
            if (v[i] >= h){
                arr.push_back(i); //字母i是最后一个达到h次数的字母 //arr[3]表示最后一个达到3次的字母是index3
                break;
            }
        }
        if (arr.size()<(h+1)) break;
        h++;
    }
    //   for (auto a : arr) {cout << a;} ////////////

    for (int i = arr.size()-1;i >0; i--){//高度为i
        cout << '#';
        for (int j = 0; j <= arr[i];  j++ ){
            cout << ' ';
            if (v[j]<i ) cout << ' ';
            else cout << '*';
        }
        cout << '\n';
    }
    cout << '#';

    for (int i = 0; i < 26; i++){
         cout << ' ' << (char)('A'+i);
    }



    
    return 0;
}