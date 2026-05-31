#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string a,b;
        cin >> a >> b;

        int len1 = a.size();
        int len2 = b.size();
        int ans = 0;

        for (int i = 0;i < len2;i++) {
            int index = i;
            for (int j = 0;j < len1;j++) {
                if (index < len2 && a[j] == b[index]) {
                    index++;
                }
            }
            int cur = index - i;
            ans = max(ans,cur);
        }
        ans = len1 + (len2 - ans);
        cout << ans << endl;
    }
    return 0;
}