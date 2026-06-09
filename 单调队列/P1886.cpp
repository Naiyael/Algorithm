#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0;i < n;i++) {
        cin >> a[i];
    }

    deque<int> q;
    for (int i = 0;i < n;i++) {
        while (!q.empty() && q.front() < i - k + 1) {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()] >= a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k - 1) {
            cout << a[q.front()] << " ";
        }
    }

    q.clear();
    cout << "\n";

    for (int i = 0;i < n;i++) {
        while (!q.empty() && q.front() < i - k + 1) {
            q.pop_front();
        }
        while (!q.empty() && a[q.back()] <= a[i]) {
            q.pop_back();
        }
        q.push_back(i);
        if (i >= k - 1) {
            cout << a[q.front()] << " ";
        }
    }

    return 0;
}