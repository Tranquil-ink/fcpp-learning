#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int weekday(int year, int month, int day){
    int result = 0;
    int i = 1990;
    if (year >=1990){
        while (i < year){
            result += 365;
            if ((i%4==0&&i%100!=0)||i%400==0){
                result +=1;
            }
            i++;
        }
    }
    else{
        i = 1989;
        while(i >=year){
            result -=365;
            if ((i%4==0&&i%100!=0)||i%400==0){
                result -=1;
            }
            i--;

        }
    }

    vector <int>v {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int j = 0;
    while (j < month){
        result += v[j];
        j++;
    }
    if (((year%4==0&&year%100!=0)||year%400==0)&&month>2) result +=1;
    result +=day;
    result = result % 7;
    if (result >=0) return result;
    else return result+7;
    // return result %7;
}

void classify (string s, int& year, int& month, int& day){
    if (s.size()==4) year = stoi(s);
    else if (s.size()==2) day = 10*(s[0] - '0')+(s[1] - '0');
    else{
        if (s == "Jan") month = 1;
        if (s == "Feb") month = 2;
        if (s == "Mar") month = 3;
        if (s == "Apr") month =4;
        if (s == "May") month =5;
        if (s == "Jun") month =6;
        if (s == "Jul") month =7;
        if (s == "Aug") month =8;
        if (s == "Sep") month =9;
        if (s == "Oct") month =10;
        if (s == "Nov") month =11;
        if (s == "Dec") month =12;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++){
        string line;
        getline(cin, line);
        istringstream ss (line);
        string a, b, c;
        int year, month, day;

        getline(ss, a, '-');
        getline(ss, b, '-');
        getline(ss, c, '-');

        classify (a, year, month, day);
        classify(b, year, month, day);
        classify(c, year, month, day);

        vector<string> v{"Sun.", "Mon.", "Tue.", "Wed.", "Thu.", "Fri.", "Sat."};
        cout << v[weekday(year, month, day)] << endl;
    }



    return 0;
}