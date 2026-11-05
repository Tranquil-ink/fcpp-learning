#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


int main(){
    vector<int> v(26, 0);

    string s;
    getline(cin, s);
    for (int i = 0; i < s.length(); i++){
        char c = s[i];
        if ((c-'a'>=0&&c-'a'<=26)&&v[c-'a']==0){
            v[c-'a'] = i+1;
            // cout << v[c-'a'] << endl;
        }
        else if ((c-'A'>=0&&c-'A'<=26)&&v[c-'A']==0) {v[c-'A'] = i+1;}
        // i = i +1;
        // // cout << i << endl;
    }
    for (int j = 0; j < 26 ; j++){
        if (v[j] !=0 ){
            cout << (char)('a'+j) << ' ' <<  v[j]-1 << '\n';
        }
    }

    return 0;

}