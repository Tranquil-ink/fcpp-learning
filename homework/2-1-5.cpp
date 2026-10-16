#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
    vector<int> v1{};
    vector <int> v2{};
    
    string l1, l2;
    getline(cin, l1);
    istringstream iss1(l1);
    string token1;
    int min1 = 24;
    while (getline(iss1, token1, ',')){
        v1.push_back(stod(token1));
        if (stod(token1) < min1) min1 = stod(token1);
    }
    getline(cin, l2);
    istringstream iss2(l2);
    int max2=0;
    string token2;
    while (getline(iss2, token2, ',')){
        v2.push_back(stod(token2));
        
        if (stod(token2) > max2) max2 = stod(token2);
    }

    
    int cmax=0;
    for (int i = min1; i < max2; i++){
        int c = 0;

        for (int j = 0; j < v1.size() ; j++){
            if (i >= v1[j] && i < v2[j]){
                c+=1;
            }

        }
        if (cmax < c) cmax = c;
    }
    
    cout << v1.size() << ' ' << cmax;
    return 0;
}