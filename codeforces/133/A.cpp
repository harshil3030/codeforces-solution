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
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='H' || s[i]=='Q' || s[i]=='9' ){
            cout<<"YES\n";
            goto exit;
        }
    }cout<<"NO\n";
    exit:;

return 0;
}
