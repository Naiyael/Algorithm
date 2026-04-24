#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n) {
        if (n - 100 >= 0) {
            n -= 100;
            ans++;
        }
        else if (n - 20 >= 0) {
            n -= 20;
            ans++;
        }
        else if (n - 10 >= 0) {
            n -= 10;
            ans++;
        }
        else if (n - 5 >= 0){
            n -= 5;
            ans++;
        }
        else {
            n -= 1;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}