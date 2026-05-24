#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    int cnt = 0;

    if (m < n - 1) {
        cout << "NO" << endl;
        return 0;
    }

    if (s.find('*') == string::npos) {
        if (s == t) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
        return 0;
    }

    int index = s.find('*');
    string l = s.substr(0,index);
    string ll = t.substr(0,index);
    string r = s.substr(index + 1,n);
    string rr = t.substr(m - (n - 1 - index),m);
    if (l == ll && r == rr) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}