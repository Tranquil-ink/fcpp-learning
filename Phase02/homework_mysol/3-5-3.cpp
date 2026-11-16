#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string> v{};
const int l = 201;

vector<int> sumincome(vector<string> &v){
    vector<int> sum(l,0);
    for (int i=0;i<v[0].length();i++){
        for(auto a : v){
            sum[i] += (int)(a[i]-'0');
        }
    }
    for (int i = 0; i < (l-1);i++){
        sum[i+1] += sum[i]/10;
        sum[i]= sum[i]%10;
    }
    return sum;
}



int main() {
    int n;
    cin >> n;
    cin.ignore();
    v.resize(n, string(l,'0'));
    for (int j = 0; j <n;j++){
        string line{};
        getline(cin, line);
        for (int i = 0; i < line.length(); i++){
            v[j][i] = line[line.length()-1-i];
        }
    }
    vector<int>  sum = sumincome(v);
    reverse(sum.begin(), sum.end());

    int index = 0;

    while(sum[index]==0&&index<sum.size()-1){
        index ++;
    }
    for (int i = index; i < sum.size(); i++){
        cout << sum[i];
    }



    
    return 0;
}