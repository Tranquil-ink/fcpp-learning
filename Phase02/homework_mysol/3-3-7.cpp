#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
using namespace std;

    
/* 题目描述
给定一个整数，求插入两个乘号将该整数分割成三个数之后，三个数的的最大乘积。

关于输入
只有一行，一个整数。可以是负数

关于输出
所求出的最大乘积。 */

int minimum = INT_MAX;
int maximum = -1;

int k = 3;
string s;

void searchmaxmin(int pos, int curproduct, int pieces){ //pos及后面还需要分成几块
    //要保证s.length-pos >=pieces
    if(pieces==1){
        int newproduct = curproduct*stoi(s.substr(pos,s.length()-pos));
        maximum =  max(maximum, newproduct);
        minimum = min(minimum, newproduct);
        return;
    }
    for(int i = pos+1; i <= s.length()-(pieces-1);i++){
        int cur = curproduct * stoi(s.substr(pos,i-pos));        
        searchmaxmin(i,cur,pieces-1);
    }
}


int main() {
    string line;
    getline(cin,line);

    if(line[0]=='-') {
        s = line.substr(1,line.length()-1);
        searchmaxmin(0,1,k);
        cout <<  '-' << minimum;
        
    }
    else{
        s=line;
        searchmaxmin(0,1,k);
        cout << maximum;
    }

    return 0;
}