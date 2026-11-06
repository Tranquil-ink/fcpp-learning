#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

bool ishuiwen(string s, int l, int r)
{
    if (l >= r)
        return true;
    if (s[r] != s[l])
        return false;
    return ishuiwen(s, l + 1, r - 1);
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string s;
        for (auto c : line)
        {
            if (isalpha(c))
                s = s + c;
        }
        cout << (ishuiwen(s, 0, s.length() - 1) ? "true" : "false") << endl;
    }

    return 0;
}