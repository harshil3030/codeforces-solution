// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif

// //write your code from here
//     int t;
//     cin >> t;
//     while(t--){
//         int n,m,cnt=0;
//         // cin>>n>>m;
//         // string s1,s2;
//         // cin>>s1>>s2;
//         cin>>n>>m;
//         char s1[n],s2[m];
//         string ans1,ans2;
//         int s1target=-1,s2target=-1;
//         cin>>s1;
//         cin>>s2;
//         for (int i = 0; i < n-1; ++i)
//         {
//             if (s1[i]==s1[i+1])
//             {
//                 cnt++;
//                 s1target = i;

//             }
//         }
//          for (int i = 0; i < m-1; ++i)
//         {
//             if (s2[i]==s2[i+1])
//             {
//                 cnt++;
//                 s2target = i;
//             }
//         }
//         int j = 0;
//         if(s1target==-1||s2target==-1){
//             cout<<"YES\n";
//         }else if(s1target != -1){
//             for(int i = 0,j=n-1; i < n-1; j--,i++){
//                 ans1[i]=s1[j];
//             }
//             for(int i = 0,j=n-1; i < n-1; j--,i++){
//                 ans2[i]=s2[j];
//             }

//         }else{
//             cout<<"NO\n";
//         }
//         //     if (s1[n-1]!=s2[m-2])
//         //     {
//         //         cout<<"yes\n";
//         //     }else
//         //         cout<<"no\n";
//         // }

//     }



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
    cin>>t;
    while(t--){
        int n,m,cnt = 0;
        cin>>n>>m;
        char s1[n],s2[m];
        char ans[m+n];
        cin>>s1>>s2;
        // for(int i;i<n/2;i++){
            // for (int i = 0; i < m/2; ++i)
            // {
            //     char temp = s2[i];
            //     s2[i] = s2[m-i-1];
            //     s2[m-i-1] = temp;
            // }
            reverse(s2,s2+m);
            for (int i = 0; i < n; ++i)
            {
                ans[i]=s1[i];
            }
            int j = 0;
            for (int i = n; i < m+n ; ++i)
            {
                ans[i] = s2[j];
                j++;
            }


            for(int i = 1; i < m+n; i++ ){
                if(ans[i-1]==ans[i]){
                    cnt++;
                }
            }
            if(cnt<=1){
                cout<<"YES\n";
            }else
            cout<<"NO\n";
        
    
}
return 0;
}


// return 0;
// }
