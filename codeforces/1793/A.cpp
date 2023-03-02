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
//         // cout<<t<<endl;
//         int n;
//         cin >> n;
//         int arr[n];
//         for (int i = 0; i < n; ++i)
//         {
//             cin>>arr[i];
//             cout<<arr[i];
//         }

//         int cnt = -1;
//         int sum1 = arr[0];int sum2 = arr[n-1];
//         int j = n-2;int i = 1;
//         // for (int i = 0,j=n-1; i < j; ++i,j--)
//         // {
//         while(i<j){
//             if(sum2>sum1){
//             sum1*=arr[i];
//             i++;}
//             else if(sum1>sum2){
//             sum2*=arr[j];
//             j--;}
//             else if(sum1==sum2 && (j-i==1)||(i-j==0)||(j-i==2)){
//                 cnt++;
//             }else{
//                 sum1*=arr[i];
//                 sum2*=arr[j];
//                 i++;
//                 j--;
//             }cout<<i<<j;

//         }
//         // cout<<i<<" "<<j<<" "<<endl<<t;
//         // cout<<cnt<<endl;
//         if(cnt == -1){
//             cout<<-1<<endl;
//         }else{
//             cout<<cnt<<endl;
//         }
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
     ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


//write your code from here
    int t;
    cin>>t;
    while(t--){
      unsigned long long  a,b,m,n;
        int sum = 0;int r;
        unsigned long  long  temp;int x = 0;
        cin>>a>>b>>n>>m;
        temp = n;
        // if (a*m <= b*(m+1))
        // {
        //     if(m>=n){
        //         if(a>b){
        //         cout<<b*n<<endl;
        //         goto exit1;
        //         }
        //         else{
        //             cout<<a*n<<endl;
        //             goto exit;
        //         }
        //     }else{
                // cout<<"problem"<<endl;
                // while(temp>=0){
                    
                //     temp -= m+1;
                //     // temp = sum;
                //     x++;
                // }x-=1;
                x = temp/(m+1);
                // cout<<x<<endl; 
                // cout<<(a*m*x) + b*(n-(x*(m+1)))<<endl;
                // goto exit2;
                r = n - x*(m+1);
               cout << x* min(a * m, b * (m + 1))+ r*min(a,b)<<endl;
            // }



        // }else{
        //     if (a>b)
        //     {
        //         cout<<n*b<<endl;
        //         goto exit3;
        //     }else{
        //     cout<<a*n<<endl;
        //     goto exit4;
        // }
        // }
        // exit:;
        // exit1:;
        // exit2:;
        // exit3:;
        // exit4:;
    }


return 0;
}


