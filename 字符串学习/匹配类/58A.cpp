#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string a = "hello";

    int j = 0;

    for (int i = 0;i < s.size();i++) {
        if (j < a.size() && s[i] == a[j]) {
            j++;
        }
    }

    if (j == a.size()) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}