#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n,m;
string a[N];
bool vis[N][N];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs(int x,int y,int px,int py,char colour) {
    vis[x][y] = true;
    for (int i = 0;i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 0 && ny < m) {
            if (a[nx][ny] != colour) continue;
            if (nx == px && ny == py) continue;
            if (vis[nx][ny]) return true;
            if (dfs(nx,ny,x,y,colour)) return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    memset(vis,false,sizeof vis);
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 0;j < m;j++) {
            if (!vis[i][j]) {
                if (dfs(i,j,-1,-1,a[i][j])) {
                    cout << "Yes" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
