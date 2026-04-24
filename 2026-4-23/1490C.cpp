#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e4 + 10;
int a[N];

int quick(int a,int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans *= a;
        b >>= 1;
        a *= a;
    }
    return ans;
}

void init() {
    for (int i = 1;i <= 1e4;i++) {
        a[i] = quick(i,3);
    }
}

signed main(){
    int t;
    cin >> t;
    init();
    while (t--) {
        int x;
        cin >> x;

        int left = 1;
        int right = 10000;
        bool found = false;

        while (left <= right) {
            int sum = a[left] + a[right];
            if (sum == x) {
                found = true;
                break;
            }
            else if (sum < x) {
                left++;
            }
            else {
                right--;
            }
        }

        if (found) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}