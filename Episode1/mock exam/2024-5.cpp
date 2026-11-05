#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

bool happy (vector<vector<char>> v){
    bool b = false;
    for (int i = 0; i < v.size() - 3; i++){
        if (find(v[i].begin(), v[i].end(), 'v') == v[i].end()){
            continue;
        }
        else {
                for (int j = i+1; j < v.size() -2; j++){
                    if (find(v[j].begin(), v[j].end(), 'i') == v[j].end()) continue;
                    else{
                            for (int k = j+1; k < v.size()-1; k++){
                                if (find(v[k].begin(), v[k].end(), 'k') == v[k].end()) continue;
                                else{
                                    for (int l = k+1; l < v.size(); l++){
                                        if (find(v[l].begin(), v[l].end(), 'a') == v[l].end()) continue;
                                        else b= true;
                                    }
                                }
                            }
                        }
                    }
        }
    }
    return b;
}



int main(){
    int t, m, n;
    cin >> t;
    for (int l= 0; l< t; l ++){
        cin >> n >> m;
        vector<vector<char>> v(m, vector<char>(n));
            for (int j = 0; j < n; j ++){
                string s;
                cin >> s;

                for (int i = 0; i < m; i ++){
                    v[i][j] = s[i];
                }
            }
        if (m < 4) {cout << "NO" << endl; continue;}
        else {
            if (happy(v) == true) cout << "YES" << endl;
            else cout << "NO" << endl;
        }

        
    }

    return 0;

}