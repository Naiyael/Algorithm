#include <bits/stdc++.h>
using namespace std;

int get_val(char c) {
    if (c == 'l') return 0;
    if (c == 'o') return 1;
    if (c == 's') return 2;
    if (c == 'e') return 3;
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    string s;
    cin >> s;

    vector<int> blocks;
    int len = 0;
    int val = -1;

    for (char c : s) {
        int v = get_val(c);

        if (v == -1) {
            if (len > 0) {
                blocks.push_back(len);
                len = 0;
                val = -1;
            }
        } else {
            if (v > val) {
                len++;
                val = v;
            }
            else {
                if (len > 0) {
                    blocks.push_back(len);
                }
                len = 1;
                val = v;
            }
        }
    }
    if (len > 0) {
        blocks.push_back(len);
    }

    sort(blocks.rbegin(), blocks.rend());

    long long ans = 0;

    for (int len : blocks) {
        int cost = 4 - len;
        if (k >= cost) {
            k -= cost;
            ans++;
        }
    }

    ans += k / 4;

    cout << ans << endl;

    return 0;
}