#include <iostream>
using namespace std;
const int N = 510;
int n,m,k;
char a[N][N];
bool vis[N][N];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x,int y) {
    vis[x][y] = true;

    for (int i = 0;i < 4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !vis[nx][ny] && a[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }

    if (k > 0) {
        a[x][y] = 'X';
        k--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    int x = -1, y = -1;

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cin >> a[i][j];
            if (a[i][j] == '.' && x == -1) {
                x = i;
                y = j;
            }
        }
    }

    if (x != -1) {
        dfs(x,y);
    }

    for (int i = 1;i <= n;i++) {
        for (int j = 1;j <= m;j++) {
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}