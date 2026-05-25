#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = (int)s.size();
    bool flag = false;

    for (int i = 0;i < n; ) {
        if (i + 2 < n && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B') {
            flag = true;
            i += 3;
        }
        else {
            if (flag) {
                cout << " ";
                flag = false;
            }
            cout << s[i];
            i++;
        }
    }
    cout << endl;

    return 0;
}