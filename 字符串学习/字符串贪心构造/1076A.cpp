#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    bool flag = false;
    for (int i = 0;i < n - 1;i++) {
        if (s[i] > s[i + 1]) {
            s.erase(i,1);
            flag = true;
            break;
        }
    }
    if (!flag) {
        s.erase(n - 1,1);
    }
    cout << s << "\n";
    return 0;
}