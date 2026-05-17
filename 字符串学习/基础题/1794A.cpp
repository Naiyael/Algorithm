#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<string> a;
        for(int i = 0;i < 2 * n - 2;i++){
            string s;
            cin >> s;
            if(s.size() == n - 1){
                a.push_back(s);
            }
        }
        reverse(a[1].begin(),a[1].end());
        if(a[0] == a[1]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}