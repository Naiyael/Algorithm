#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main() {
    string s;
    int m;
    cin >> s >> m;
    for (int i = 0;i < s.size();i++) {
        bool flag = (s[i] == s[i + 1]);
        a[i + 1] = a[i] + flag;
    }

    while (m--) {
        int l,r;
        cin >> l >> r;
        cout << a[r- 1] - a[l - 1] << endl;
    }
    return 0;
}