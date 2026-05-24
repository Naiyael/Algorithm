#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1;
    string s2;

    cin >> s1 >> s2;

    int ans = 0;
    int pos = 0;

    while (true) {
        int index = s1.find(s2,pos);

        if (index == string::npos) {
            break;
        }

        ans++;

        pos = index + s2.size();
    }

    cout << ans << endl;
}