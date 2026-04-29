#include <bits/stdc++.h>
using namespace std;

int n,w[4],f[4010];

int main(){
    cin >> n;
    for(int i = 1;i <= 3;i++)
        cin >> w[i];
    memset(f,-1,sizeof(f));
    f[0] = 0;
    for(int i = 1;i <= 3;i++)
        for(int j = w[i];j <= n;j++){
            if(f[j - w[i]] != -1)
                f[j] = max(f[j],f[j-w[i]] + 1);
        }
    cout << f[n] << endl;
    return 0;
}