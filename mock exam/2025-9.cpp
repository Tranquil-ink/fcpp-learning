#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// 题目描述
// 给出 2 个 长的 k 进制数 a 和 b，计算 a-b 的结果值（a 和 b可以带符号）。
// 如果 k 大于10，数据可以用英文26个大写字母依次表示，如， A, B, C分别表示 10,11,12，...。设定 k 不大于 36且不小于2。例如16 进制，用符号 0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F

// k进制运算的准则是：当被减数对应的位小于减数对应的位时，应向被减数更高的一位借1当成当前位大小为 k 的值。 例如，3进制运算：221-112=102，因为被减数最低位的1比减数最低位的2小，需要借 1，当成最低位的 3（3进制）使用，但被减数最低位已经有 1，借过来后便为4, 然后，4减去减数对应位的 2，得到低位为 2，第2位的被减数被借1之后，变成1了，与减数1相减，结果为0，高位再用2减1为1，最后得到102。加法运算则满足逢 k 进一（对应位的结果大于等于 k时，将当前位结果减去 k，同时向高位进1）。

// 关于输入
// 输入 n+1 行，其中第一行 为 n，表示后面有 n 组数；后面的 n 组数格式是：

// k a b

// 其中，三个数之间均用空格间隔。k表示后面两个数的进制，a 和 b均可带符号（也可以不带符号，不带符号则为正数），也可以带小数，如果是纯小数，可以从小数点开始输入（如 .1234)，也可以带整数位0（如 0.1234）。假定两个数的长度（连带小数点和符号位）均不超过 100 位。

// 关于输出
// 对应的 n 组运算的输出结果。整数部分的最高位不能为0，小数部分的最低位不能为0；如小数部分全部为0，则只输出整数部分；如整数部分为0，则从小数点开始输出；如果运算的结果为0，则输出0.



//parse input string
struct Pair{
    int sgn;
    string ipart;
    string fpart;
};
Pair parse(string s){
    Pair p{};
    if (s[0]=='-')  {
        p.sgn = -1;
        auto dot = s.find('.');
        if (dot==string::npos){
            p.ipart = s.substr(1, s.length()-1);
        }
        else {
            p.ipart = s.substr(1,dot-1);
            p.fpart = s.substr(dot+1, s.length()-1);
            }
    }
    else {
        p.sgn = 1;
        auto dot = s.find('.');
        if (dot==string::npos){
            p.ipart = s.substr(0, s.length()-1);  // verify:can substr be empty????
        }
        else {
            p.ipart = s.substr(0,dot-1);
            p.fpart = s.substr(dot+1, s.length()-1);
            }
    }
    // fill in 0s
    string padding1((101 - p.ipart.length()), '0');
    string padding2((101 - p.fpart.length()), '0');
    p.ipart = padding1 + p.ipart;
    p.fpart = padding2 + p.fpart;

    return p;
}

// equivalent numbers
int char2num(char c){
    vector<char> num{'0','1','2','3','4','5','6','7','8','9'};
    // for (int i = 0;i<26;i++){
    //     num.push_back((char)('A'+i));
    // }
    if (find(num.begin(), num.end(), 'c')!=num.end())  return (int)(c-'0');
    else return (int)(10+c-'A');
}




int main() {
    // equivalent nums
    vector<char> num{'0','1','2','3','4','5','6','7','8','9'};
    for (int i = 0;i<26;i++){
        num.push_back((char)('A'+i));
    }


    // input
    int n;
    cin >> n;
    cin.ignore();
    for (int row = 0; row < n; row++){
        string line;
        getline(cin, line);
        istringstream iss(line);
        string base, s1, s2;
        getline(iss, base, ' ');
        getline(iss, s1, ' ');
        getline(iss, s2, ' ');
        int k = stoi(base);

        //store input
        //store input
        Pair p1 = parse(s1);
        Pair p2 = parse(s2);

        // calculate
        // USE ex to keep track
        vector<int> vf{};
        vector<int> vi{};
        int ex = 0;
        
        for (int i = 100; i >=0; i--){
            int current = p1.sgn * char2num(p1.fpart[i]) - p2.sgn * char2num(p2.fpart[i]) + ex;
            if(current<0) {
                vf.push_back(k+current);
                ex = -1;
            }
            else if(current>=k){
                vf.push_back(current-k);
                ex = 1;
            }

        }
        for (int i = 100; i >=0; i--){
            int current = p1.sgn * char2num(p1.ipart[i]) - p2.sgn * char2num(p2.ipart[i]) + ex;
            if(current<0) {
                vi.push_back(k+current);
                ex = -1;
            }
            else if(current>=k){
                vi.push_back(current-k);
                ex = 1;
            }

        }
        // 处理多出来的首位,决定正负
        if (ex == 1){
            vi.push_back(1);
        }
        else if(ex == -1){
            for (auto a : vi){
                a = k-a;
            }
            for (auto b : vf){
                b = k-b;
            }
            vi.push_back(1);
            cout << '-';
        }

        reverse(vf.begin(),vf.end());
        reverse(vi.begin(),vi.end());

        //output
        int indexi = -1;
        int indexf = -1;
        for (int i = 0; i < vi.size(); i++) {
            if (vi[i]!=0) {indexi =i;break;}
        }
        for (int i = vf.size()-1; i >=0; i--) {
            if (vf[i]!=0) {indexf =i;break;}
        }
        if ((indexi != -1)&& (indexf != -1)){
            for (int i = indexi; i < vi.size(); i++){
                cout << num[vi[i]];
            }
            cout << ' ';
            for (int i = 0; i <= indexf; i++){
                cout << num[vf[i]];
            }
        }
        else if ((indexi == -1)&& (indexf != -1)){

            cout << ' ';
            for (int i = 0; i <= indexf; i++){
                cout << num[vf[i]];
            }
        }
        else if ((indexi != -1)&& (indexf == -1)){
            for (int i = indexi; i < vi.size(); i++){
                cout << num[vi[i]];
            }

        }
        else cout << '0';

    





    }

    
    return 0;
}