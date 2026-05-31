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

        int lena = (int)a.size();
        int lenb = (int)b.size();

        if (a[0] == b[0]) {
            cout << "YES" << endl;
            cout << a[0] << "*" << endl;
            continue;
        }

        if (a[lena - 1] == b[lenb - 1]) {
            cout << "YES" << endl;
            cout << "*" << a[lena - 1] << endl;
            continue;
        }

        bool flag = false;
        for (int i = 0;i < lena - 1;i++) {
            string s = a.substr(i,2);
            if (b.find(s) != string::npos) {
                cout << "YES" << endl;
                cout << "*" << s << "*" << endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout << "NO" << endl;
        }
    }
    return 0;
}