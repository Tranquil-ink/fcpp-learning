// 题目描述
// 给定两个年月日，计算之间的天数。例如 2010-1-1 和 2010-1-3 之间差2天。

// year = 1, 2, ..., 3000.

// 需要考虑闰年情况：闰年的2月份有29天。闰年是：(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)。

// 关于输入
// 第一行
// startYear startMonth startDay

// 第二行
// endYear endMonth endDay

// 关于输出
// 输出只有一行是两个日期之间的天数

// 例子输入
// 2008 1 1
// 2009 1 1
// 例子输出
// 366

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int daysperyear(int y, int m, int d){
    int ans = 0;;
    switch(m-1){
        case 11: ans += 30;
        case 10: ans +=31;
        case 9: ans +=30;
        case 8: ans +=31;
        case 7: ans +=31;
        case 6: ans +=30;
        case 5: ans +=31;
        case 4: ans +=30;
        case 3: ans +=31;
        case 2: 
            ans +=28;
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ans +=1;
        case 1: ans +=31;
        default: ans = ans;
    }
    ans += d;
    return ans;

}


int main() {
    int y1, y2, m1, m2, d1, d2;
    cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
    int yeardiff = 0;
    if (y1 != y2){
        for (int i = y1; i < y2; i++){
            if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) yeardiff +=366;
            else yeardiff += 365;
        }
    }
    
    cout << yeardiff + daysperyear(y2, m2, d2) - daysperyear(y1, m1, d1);
    // cout << ' ' << 31+29+31+30+31+30+31+31+12;


    return 0;
}