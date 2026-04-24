#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1,a.end());

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        int i = upper_bound(a.begin() + 1,a.end(),x) - a.begin() - 1;
        cout << i << endl;
    }
    return 0;
}