#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0;i < n;i++) {
        cin >> h[i];
    }

    deque<int> Min;
    deque<int> Max;
    vector<pair<int,int>> ans;

    int l = 0;
    int len = 0;
    for (int i = 0;i < n;i++) {

        while (!Min.empty() && h[Min.back()] >= h[i]) {
            Min.pop_back();
        }
        Min.push_back(i);

        while (!Max.empty() && h[Max.back()] <= h[i]) {
            Max.pop_back();
        }
        Max.push_back(i);

        while (!Max.empty() && !Min.empty() && h[Max.front()] - h[Min.front()] > k) {
            l++;
            if (Max.front() < l) {
                Max.pop_front();
            }
            if (Min.front() < l) {
                Min.pop_front();
            }
        }

        if (i - l + 1 > len) {
            ans.clear();
            ans.push_back({l,i});
            len = i - l + 1;
        }
        else if (i - l + 1 == len) {
            ans.push_back({l,i});
        }
    }

    cout << len << " " << (int)ans.size() << "\n";

    for (int i = 0;i < (int)ans.size();i++) {
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
    }

    return 0;
}