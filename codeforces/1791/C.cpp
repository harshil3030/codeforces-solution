// // #include<bits/stdc++.h>
// // using namespace std;
// // int main()
// // {
// // #ifndef ONLINE_JUDGE
// //     freopen("input.txt","r",stdin);
// //     freopen("output.txt","w",stdout);
// // #endif

// // //write your code from here
// //     int t;
// //     cin >> t;
// //     while(t--){
// //         long int a,b,m,n,ans;
// //         cin>>a>>b>>n>>m;
// //         // if(m>n){
// //         //     cout<<n*m

// //         // }else{
// //         // ans = (n-m-1)*(b)+a*(m);
// //         // cout<<ans<<endl;
// //         int i = 0;
// //         while(n>m*i){
// //             i++;
// //         }i--;
        
// //         if(a*m <= b*(m+1)){
// //             if(m>=n){
// //                 if(a*n <= b*n){
// //                     cout<<a*n<<endl;
// //                 }else
// //                 {
// //                     cout<<b*n<<endl;
// //                 }
// //             }else
// //                 {
// //                     cout<<i*(a*m) + b*(n-(i*(m+1))) <<endl;
// //                 }
// //         }else{
// //             cout<<b*n<<endl;
// //         }
// // }

// // return 0;
// // }

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
//     cin>>t;
//     while(t--){
//          long long int a,b,m,n;
//         cin>>a>>b;
//         cin>>m>>n;
//          long long int x;
//         x = m/(n+1);
//         if (x*(a*n)<=x*b*(n+1))
//         {
//             if(m>n){
//             cout<<x*(a*n)+b*(m-x*(n+1))<<endl;
//             }else{
//                 cout<<m*min(a,b)<<endl;
//                 // if(a>b){
//                 // cout<<b*m;
//                 // }else
//                 // {
//                 // cout<<a*m;
//                 // }   // cout<<x*(a*n)+b*(m-(x*n+1))<<endl;
//         }
//         }else
//         cout<<b*m<<endl;
//     }

// return 0;
// }

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
        int n;
        cin>>n;
        char s[2000];
        int start = -1,end = -1;
        cin>>s;
        for (int i = 0,j=n-1; i < n/2; ++i,--j)
        {
            if (s[i]==s[j])
            {
                start = i;
                end = j;
                break;
            }
        }
        if (end == -1 && n%2==0)
        {
            cout<<0<<endl;
        }else if(end == -1 && n%2==1){
            cout<<1<<endl;
        }else
        cout<<end-start+1<<endl;

    }

return 0;
}
