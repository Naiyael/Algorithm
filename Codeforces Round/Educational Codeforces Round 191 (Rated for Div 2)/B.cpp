#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> res;

        for (int i = 1; i <= n; i++) {
            res.push_back(i);
        }
        for (int i = 2; i <= n; i++) {
            res.push_back(i);
        }
        res.push_back(1);
        for (int i = 1; i <= n; i++) {
            res.push_back(i);
        }
        for (int i = 1; i <= n; i++) {
            res.push_back(i);
        }
        for (int i = 0; i < 4 * n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
