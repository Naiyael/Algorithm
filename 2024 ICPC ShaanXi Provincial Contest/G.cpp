#include <bits/stdc++.h>
using namespace std;
#define int long long

int quick(int a,int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        int x;
        cin >> s >> x;
        int n = s.size();
        vector<int> a(n);
        for (int i = 0;i < (int)s.size();i++) {
            int digit = s[i] - '0';
            if (digit > x) {
                a[i] = digit - 1;
            }
            else {
                a[i] = digit;
            }
        }
        
        int sum = 0;
        reverse(a.begin(),a.end());
        for (int i = 0;i < n;i++) {
            sum += a[i] * quick(9,i);
        }
        cout << sum  + 1 << endl;
    }
}