#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0;i < n;i++) {
            cin >> a[i];
        }
        int m;
        cin >> m;
        while (m--) {
            string s;
            cin >> s;
            if (s.size() != n) {
                cout << "NO" << endl;
                continue;
            }

            map<int,char> cnt1;
            map<char,int> cnt2;
            bool flag = false;
            for (int i = 0;i < n;i++) {
                int num = a[i];
                char ch = s[i];

                if (cnt1.count(num) == 0 && cnt2.count(ch) == 0) {
                    cnt1[num] = ch;
                    cnt2[ch] = num;
                }
                else {
                    if (cnt1[num] != ch || cnt2[ch] != num) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                cout << "NO" << endl;
            }
            else {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}