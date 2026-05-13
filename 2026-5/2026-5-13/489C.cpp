#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m,s;
    cin >> m >> s;

    if (s == 0) {
        if (m == 1) {
            cout << "0 0" << endl;
        }
        else {
            cout << "-1 -1" << endl;
        }
        return 0;
    }

    if (s > 9 * m) {
        cout << "-1 -1" << endl;
        return 0;
    }

    string Min(m,'0');
    int ss = s;
    ss -= 1;

    for (int i = m - 1;i > 0;i--) {
        int d = min(9,ss);
        Min[i] += d;
        ss -= d;
    }
    Min[0] += (ss + 1);

    string Max(m,'0');
    int sss = s;

    for (int i = 0;i < m;i++) {
        int d = min(9,sss);
        Max[i] += d;
        sss -= d;
    }
    cout << Min << " " << Max << endl;
}