#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n,m;
int r1,c1,r2,c2;
bool vis[N][N];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

bool dfs(int x,int y) {

    for (int i = 0;i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
           if (nx == r2 && ny == c2 && vis[nx][ny] == true) {
               return true;
           }

            if (vis[nx][ny] == false) {
                vis[nx][ny] = true;
                if (dfs(nx,ny)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            char c;
            cin >> c;
            if (c == 'X') {
                vis[i][j] = true;
            }
        }
    }
    cin >> r1 >> c1 >> r2 >> c2;

    if (dfs(r1,c1)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    return 0;
}