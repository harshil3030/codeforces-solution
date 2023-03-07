#include<bits/stdc++.h>
using namespace std;
int sp(int n){
    int i = 1;
    while(pow(2,i)*i<n && i<n){
        i++;
    }
    return i;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

//write your code from here
    int tt;
    cin>>tt;
    while(tt--){
        long long int n; 
        cin>>n;
        // cout<<n<<endl;

        // if(n==0){
        //     cout<<0<<" "<<0<<endl;
        // }else
         if(n==1){
            cout<<-1<<endl;
        }else if(n==2){
            cout<<1<<" "<<1<<endl;
        }else{
        
        int temp1,temp2;
        int cnt = 0;
        int r = sp(n);
        // break;
        // cout<<r;
        // break;
        for(long long int i = 0; i <r-1; i++){
            for(long long int j = i;j<r;j++){
                if(pow(i,j)*j+pow(j,i)*i==n){
                    temp1 = i;
                    temp2 = j;
                    cnt++;
                    break;
                }
            }
        }

        if(cnt==0){
            if(n/2*2==n){
                cout<<1<<" "<<n/2<<endl;
            }else{
            cout<<-1<<endl;
        }
            // break;
        }
        else{
        cout<<temp1<<" "<<temp2<<endl;
     } 
    }   
}
return 0;
}
