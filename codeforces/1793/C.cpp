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
//         int n;
//        cin >> n;
//        int a[n],ans[n],temp[n];
//        for (int i = 0; i < n; ++i)
//        {
//            cin >> a[i];
//            ans[i] = a[i];
//            temp[i] = a[i];
//        }
//        if (n>3)
//        {    
//             int c,b;
//             c = temp[0];
//             b = temp[n-1];
//             sort(temp,temp+n);
//             if ((c==temp[0] || c==temp[n-1]) && (b==temp[0] || b==temp[n-1]))
//             {
//                 sort(a+1,a+n-1);
//             if( (a[1] > ans[1] && a[1]>ans[n-2]) || (a[1]<ans[1] && a[1]<ans[n-2]) || (a[n-2]>ans[1] && a[n-2]>ans[n-2])
//             || (a[n-2]<ans[1] && a[n-2]<ans[n-2]))
//             {
//                 cout<<2<<" "<<n-1<<endl;
//             }else
//                 cout<<"-1"<<endl;
//         }else if(c==temp[0]||b==temp[n-1]||c==temp[n-1]||b==temp[0]){
//             cout<<-1<<endl;
//         }else{
//             cout<<1<<" "<<n<<endl;
//         }
//         // }else if((c!=temp[0] && b==temp[n-1])
//         //     || (c!=temp[n-1] && b==temp[0])
//         //     || (b!=temp[0] && c==temp[n-1])
//         //     || (b!=temp[n-1] && c==temp[0]) )
//         //     {

//         //     }
            
           
//        }else
//        {cout<<"-1"<<endl;}
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
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; ++i)
        {
            cin>>a[i];
        }
        int min = 1; int max = n;
        int left = 0; int right = n-1;
        while(left<=right){
            if(a[left]==min){
                left++;
                min++;
            }else if(a[left]==max){
                left++;
                max--;
            }else if(a[right]==min){
                right--;
                min++;
            }else if(a[right]==max){
                right--;
                max--;
            }else if(a[left]!=min && a[left]!=max && a[right]!=min && a[right]!=max)
            {
                cout<<left+1<<" "<<right+1<<endl;
                goto exit;
            }

            // if(((a[left]==min) || (a[left]==max)) 
            //     && ((a[right]==min) || (a[right]==max))){
            //     left++;
            //     right--;
            //     min++;
            //     max--;
            // }else if((a[left]!=min)&&(a[left]!=max)&&
            //     a[right]!=min && a[right]!= max){
            //     cout<<left<<" "<<right<<endl;
            //     break;
            // }else
        //     else if(a[left]==min || a[left]==max || a[right]==min || a[right]==max){
        //     }else
        // }
    }

    cout<<-1<<endl;
    exit:;
}

return 0;
}
