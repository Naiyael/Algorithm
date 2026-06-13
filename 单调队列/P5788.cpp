#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    vector<int> ans(n,0);
    stack<int> s;

    for (int i = n - 1;i >= 0;i--) {
        while (!s.empty() && a[s.top()] <= a[i]) {
            s.pop();
        }

        ans[i] = s.empty() ? 0 : s.top();

        s.push(i);
    }

    for (int i = 0;i < n;i++) {
        if (ans[i] == 0) {
            cout << 0 << " ";
        }
        else {
            cout << ans[i] + 1 << " ";
        }
    }
    return 0;
}