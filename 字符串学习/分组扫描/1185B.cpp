#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string s, t;
        cin >> s >> t;

        int len1 = s.size();
        int len2 = t.size();

        int i = 0,j = 0;
        bool flag = true;

        while (i < len1 && j < len2) {
            if (s[i] != t[j]) {
                flag = false;
                break;
            }

            char cur = s[i];
            int count1 = 0;
            int count2 = 0;

            while (i < len1 && s[i] == cur) {
                count1++;
                i++;
            }

            while (j < len2 && t[j] == cur) {
                count2++;
                j++;
            }

            if (count2 < count1) {
                flag = false;
                break;
            }
        }

        if (i != len1 || j != len2) {
            flag = false;
        }

        if (flag) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
    return 0;
}