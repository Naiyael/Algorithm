#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    vector<int> lmin(n + 1),rmin(n + 1);
    vector<int> lmax(n + 1),rmax(n + 1);
    stack<int> st;

    for(int i = 1;i <= n;i++) {
        while(!st.empty() && a[st.top()] > a[i]) {
            st.pop();
        }
        lmin[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n;i >= 1;i--) {
        while(!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }
        rmin[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = 1;i <= n;i++) {
        while(!st.empty() && a[st.top()] < a[i]) {
            st.pop();
        }
        lmax[i] = st.empty() ? 0 : st.top();
        st.push(i);
    }

    while(!st.empty()) st.pop();

    for(int i = n;i >= 1;i--) {
        while(!st.empty() && a[st.top()] <= a[i]) {
            st.pop();
        }
        rmax[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }

    int ans = 0;
    for(int i = 1;i <= n;i++) {
        int mx = (i - lmax[i]) * (rmax[i] - i);
        int mn = (i - lmin[i]) * (rmin[i] - i);
        ans += a[i] * (mx - mn);
    }
    cout << ans << '\n';
}