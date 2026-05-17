#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 2){
        cout << s << endl;
        return 0;
    }
    map<string,int> a;
    string ans;
    int Max = 0;
    for(int i = 0;i < n - 1;i++){
        string cnt = s.substr(i,2);
        if(!a[cnt]){
            a[cnt] = 1;
            if(a[cnt] > Max){
                Max = a[cnt];
                ans = cnt;
            }
        }
        else{
            a[cnt]++;
            if(a[cnt] > Max){
            Max = a[cnt];
            ans = cnt;
            }
        }
    }
    cout << ans << endl;
    return 0;
}