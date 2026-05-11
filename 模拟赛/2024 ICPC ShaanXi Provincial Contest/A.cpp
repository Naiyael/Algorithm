#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        string ans = "";
        cin >> s;
        for (int i = 0;i < 3;i++) {
            if (s[i] == '7') {
                ans += "rwx";
            }
            else if (s[i] == '6') {
                ans += "rw-";
            }
            else if (s[i] == '5') {
                ans += "r-x";
            }
            else if (s[i] == '4') {
                ans += "r--";
            }
            else if (s[i] == '3') {
                ans += "-wx";
            }
            else if (s[i] == '1') {
                ans += "--x";
            }
            else if (s[i] == '2'){
                ans += "-w-";
            }
            else {
                ans += "---";
            }
        }
        cout << ans << endl;
    }
    return 0;
}