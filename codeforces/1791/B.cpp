#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

//write your code from here
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt = 0;
        int cmt = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i]=='U')
            {
                cmt++;
            }else if(s[i]=='R'){
                cnt++;
            }else if(s[i]=='L'){
                cnt--;
            }else if(s[i]=='D'){
                cmt--;
            }

            if(cnt == 1 && cmt == 1){
                cout<<"yes\n";
                goto exit;
            }
        }
        cout<<"no\n";
        exit:;
    }

return 0;
}
