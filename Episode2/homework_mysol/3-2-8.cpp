#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> track(int n)
{
    vector<string> v{};
    string s = to_string(n);
    v.push_back (s);
    while (n >= 1)
    {
        n = n / 2;
        v.push_back(to_string(n));
    }
    return v;
}

int main()
{
    int x,y;
    cin >> x>>y;
    vector<string> v1 = track(x);
    vector<string> v2 = track(y);

    for (auto a : v1){
        if (find(v2.begin(), v2.end(), a)!=v2.end()) {cout << a; break;}
    }
    return 0;
}