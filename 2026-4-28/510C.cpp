#include <bits/stdc++.h>
using namespace std;
vector<int> g[26];
int in[26] = {0};

int main() {
    int n;
    cin >> n;
    vector<string> names(n);
    for (int i = 0;i < n;i++) {
        cin >> names[i];
    }

    for (int i = 0;i < n - 1;i++) {
        string s1 = names[i];
        string s2 = names[i + 1];

        int len = min(s1.size(),s2.size());
        bool flag = false;

        for (int j = 0;j < len;j++) {
            if (s1[j] != s2[j]) {
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';

                g[u].push_back(v);
                in[v]++;

                flag = true;
                break;
            }
        }
        if (!flag && s1.size() > s2.size()) {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    queue<int> q;
    vector<char> ans;
    for (int i = 0;i < 26;i++) {
        if (in[i] == 0) q.push(i);
    }

    while (q.size()) {
        int cur = q.front();
        q.pop();
        ans.push_back(cur + 'a');
        for (int i = 0;i < g[cur].size();i++) {
            int node = g[cur][i];
            in[node]--;
            if (in[node] == 0) {
                q.push(node);
            }
        }
    }

    if (ans.size() < 26) {
        cout << "Impossible" << endl;
    }
    else {
        for (int i = 0;i < ans.size();i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}