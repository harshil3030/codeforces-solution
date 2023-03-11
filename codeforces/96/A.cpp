#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

//write your code from here
    string s;
    cin >> s;
    int i  = 0;
    int cnt = 0;
    int max = 0;
    while(i<s.size()-1){
        if(s[i] == s[i+1]){
            cnt++;
            if(cnt>max){
                max = cnt;
            }
        }else{
            cnt = 0;
        }i++;
    }

    if(max>=6){
        cout<<"YES\n";
    }else{
        cout<<"NO\n";
    }

return 0;
}
