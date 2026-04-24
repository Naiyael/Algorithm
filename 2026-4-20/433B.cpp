#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
long long sum1[N], sum2[N];

int main() {
    int n;
    cin >> n;

    vector<long long> a(n + 1);
    vector<long long> sort_a(n + 1);

    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        sort_a[i] = a[i];
    }

    sort(sort_a.begin() + 1, sort_a.end());

    for (int i = 1;i <= n;i++) {
        sum1[i] = a[i] + sum1[i - 1];
        sum2[i] = sort_a[i] + sum2[i - 1];
    }

    int m;
    cin >> m;
    while (m--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            cout << sum1[r] - sum1[l - 1] << endl;
        }
        else {
            cout << sum2[r] - sum2[l - 1] << endl;
        }
    }
    return 0;
}