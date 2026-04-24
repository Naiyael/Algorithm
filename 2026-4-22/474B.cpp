#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    vector<int> add(n + 1);
    for (int i = 1;i <= n;i++) {
        add[i] = a[i] + add[i - 1];
    }

    int m;
    cin >> m;
    while (m--) {
        int x;
        cin >> x;
        int i = lower_bound(add.begin() + 1,add.end(),x) - add.begin();
        cout << i << endl;
    }
    return 0;
}