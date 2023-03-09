// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
// #endif

// //write your code from here
//     int n;
//     cin >> n;
//     int c = 2*n;
//     int a[c];
//     // for(int i = 0; i < 2*n; i++){
//     //     cin >> a[i];
//     // }
//     int sum = 0;
//     int max = 0;
//     for(int i = 0; i < n; i++){

//         int a;int b;
//         cin >> a;
//         cin >> b;
//         if(i%2==0){
//             sum-=a;
//         }else{
//             sum+=b;
//         }

//         if(sum>=max){
//             max = sum;
//         }
//     }
//     cout<<max<<endl;
    



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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cnt = 0;
    int cmt = 0;
    for(int i = 0; i < s.size() ; i++){
        if(s[i]=='A'){
            cnt++;
        }else{
            cmt++;
        }
    }
    if(cnt>cmt){
        cout<<"Anton\n";
    }else if(cnt<cmt){
        cout<<"Danik\n";
    }else{
        cout<<"Friendship\n";
    }

return 0;
}

