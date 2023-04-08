#include<bits/stdc++.h>
using namespace std;
#define f(i,k,n) for(int i = k; i < n; i++)

void Burst();
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
ios_base::sync_with_stdio(0);
cin.tie(0);cout.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        Burst();
    }
return 0;
}

  void Burst(){
    //write your solution from here
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int cnt = 0;
    map <char,int> mp;
    
    f(i,0,n){
        mp[s[i]]++;
    }
    

    f(i,0,26){
        if(mp[(char)(i+65)]>mp[(char)(i+97)]){
            cnt += mp[(char)i+97];
            mp[(char)i+65] -= mp[(char)i+97];
            while(m>0 && mp[(char)i+65]>1){
                cnt++;
                m--;
                mp[(char)i+65]-=2;
            }


        }else if(mp[(char)i+65]<mp[(char)i+97]){
            cnt += mp[(char)i+65];
            mp[(char)i+97] -= mp[(char)i+65];

            while(m>0 && mp[(char)i+97]>1){
                cnt++;
                m--;
                mp[(char)i+97]-=2;
            }    

        }else{
            cnt+= mp[(char)i+65];
            mp[(char)i+65] = 0;
            mp[(char)i+97] = 0;

        }

        }
        cout << cnt << endl;
    
}