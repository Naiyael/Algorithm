#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    int ans = 0;
    deque<int> Max;
    deque<int> Min;

    for (int l = 0,r = 0;r < n;r++) {

        while (!Max.empty() && a[Max.back()] <= a[r]) {
            Max.pop_back();
        }

        while (!Min.empty() && a[Min.back()] >= a[r]) {
            Min.pop_back();
        }

        Max.push_back(r);
        Min.push_back(r);

        while (a[Max.front()] - a[Min.front()] > 1) {
            if (Max.front() == l) {
                Max.pop_front();
            }
            if (Min.front() == l) {
                Min.pop_front();
            }
            l++;
        }

        ans = max(ans,r - l + 1);
        
    }

    cout << ans << "\n";

    return 0;
}