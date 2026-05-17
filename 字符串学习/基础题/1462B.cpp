#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;

        bool ok = false;

        for(int i = 0;i <= 4;i++){
            string s1 = s.substr(0,i);
            string s2 = s.substr(n - (4 - i),4 - i);
            
            if(s1 + s2 == "2020"){
                ok = true;
                break;
            }
        }

        if(ok){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}