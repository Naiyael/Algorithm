#include <bits/stdc++.h>
using namespace std;

int BF(const string& a, const string& b, int c) {
    int n = a.length();
    int m = b.length();

    if (c + m > n) {
        return -1;
    }

    int i = c;
    int j = 0;

    while (i < n && j < m) {
        if (a[i] == b[j]) {
            i++;
            j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }

    if (j == m) {
        return i - j;
    }
    return -1;
}

bool check(string a, string b, string c) {

    int pos_b = BF(a, b, 0);
    if (pos_b == -1) {
        return false;
    }

    int start_for_c = pos_b + b.length();

    int pos_c = BF(a, c, start_for_c);

    return pos_c != -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b, c;
    cin >> a >> b >> c;

    bool can_forward = check(a, b, c);

    reverse(a.begin(), a.end());
    bool can_backward = check(a, b, c);

    if (can_forward && can_backward) {
        cout << "both" << endl;
    } else if (can_forward) {
        cout << "forward" << endl;
    } else if (can_backward) {
        cout << "backward" << endl;
    } else {
        cout << "fantasy" << endl;
    }

    return 0;
}