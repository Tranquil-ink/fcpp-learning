#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

/* 题目描述
后缀表达式是指这样的一个表达式：式中不使用括号，运算符号放在两个运算数之后，所有计算按运算符号出现的顺序，严格地自左而右进行（不用考虑运算符的优先级）
如：3*(5-2)+7对应的后缀表达式为：3 5 2 - *  7 + @。’@’为表达式的结束符号。

（注：运算过程中请使用long long进行运算。）

关于输入
多行，每行一个用空格分割的后缀表达式。保证表达式长度不超过1000个字符。
表达式中可能出现整数，+ - * /四种运算符，以及@。

关于输出
输出多行，为对应表达式的值。

如果在运算过程中出现除0，那么输出NaN。 */

int main() {
    string line;
    while(getline(cin,line)){
        istringstream iss(line);
        string token;
        stack<long long> st{};
        bool bad = false;
        while(iss>>token && token!="@"){

            if (token!="+"&&token!="-"&&token!="*"&&token!="/"){
                long long cur = stoll (token);
                st.push(cur);
            }
            else{
                long long b = st.top();
                st.pop();
                long long a = st.top();
                st.pop();
                if (token[0]=='/'&&b==0){
                    
                    bad = true;
                    break;
                }
                switch(token[0]){
                    case '+' : st.push(a+b); break;
                    case '-' : st.push(a-b); break;
                    case '*' : st.push(a*b); break;
                    case '/' : st.push(a/b); break;
                }

            }
        }
        cout << (bad==true ? "NaN" : to_string(st.top())) << endl;

    }
    
    return 0;
}