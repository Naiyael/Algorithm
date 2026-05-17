#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int n = s.size();

    for(int i = 0;i < n;i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            s[i] += 32;
        }
        if(s[i] != 'a' && s[i] != 'o' && s[i] != 'y'
        && s[i] != 'e' && s[i] != 'u' && s[i] != 'i'){
            cout << '.' << s[i];
        }
    }
    return 0;
}