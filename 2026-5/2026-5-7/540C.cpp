#include <bits/stdc++.h>
using namespace std;

const int N = 510;
int n,m;
int a[N][N];
int r1,c1,r2,c2;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool dfs(int x,int y) {
    for (int i = 0;i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {

            if (nx == r2 && ny == c2 && a[nx][ny] == 0) {
                return true;
            }

            if (a[nx][ny] == 1) {
                a[nx][ny] = 0;
                if (dfs(nx,ny)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            if (c == '.') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;

    if (dfs(r1,c1)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}