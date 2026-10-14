#include <iostream>
#include <vector>
#include <string>
using namespace std;

int frep(vector<int> v){
    int count = 1;
    int count_max = 1;
        for (int i = 0; i < v.size(); i++){
        if (v[i+1] == v[i]){
            count +=1;
        }
        else {
            if (count_max < count) count_max = count;
            count = 1;
        }
    }
    return (count_max);

}

int main() {
    while (true){
        int n;
        cin >> n;
        if (n == 0) break;
        vector <int> v{};
        for (int i = 0; i < n; i++){
                int k;
                cin >>k;
                v.push_back(k);
        }
        cout << frep(v) << endl;
               
    }
    return 0;
}