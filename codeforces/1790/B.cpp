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
        int n,s,r;
        cin >> n >> s >> r;
        int arr[n];
        arr[0] = s-r;
        int temp = r;
        int temp1,temp2;
        int sum = 0;
        int rem = 0;
        for (int i = 1; i < n; ++i)
        {

            if(i==n-1){
                
                if(r<=s-temp && r > 0)
                {arr[n-1] = r;}
                // if(r < 0){
                // temp1 = -r+1;
                // arr[n-1] = -r+1;
                // r = -r+1;
                // temp2 = temp1%(n-2);
                //     // if(r>(n-2)){

                //     // }  
                // for (int i = 1; i < r; ++i)
                // {
                //     if(i==1){
                //     arr[1] +=temp2;
                //     temp1-=temp2;
                //     }else{
                //     arr[i] += temp1/(n-2);
                //     }
                // }
                
                else{
                    arr[n-1] = r-(n-2);
                    for (int i = 1; i < n-1; ++i)
                    {
                        arr[i]++;
                    }
                    if(arr[n-1]<=0){

                        // temp1 = -arr[n-1] + 1;
                        // arr[n-1] = 1;
                        // int k = 1;
                        // while(temp1>0){
                        //     if(k%n!=0 && k%n!=(n-1)){
                        //     arr[k%n]++;
                        //     k++;
                        //     temp1--;
                        // }
                        int l = 1;
                        while(arr[n-1]!=1){
                            arr[l]--;
                            arr[n-1]++;
                            l++;
                            if(l%(n-1)==0){
                                l=1;
                            }
                        }
                        }
                    }
                
            }
            else{
            arr[i] = temp/(n-1);
            }
            r = r - temp/(n-1);
        }

        for (int i = 0; i < n; ++i)
        {
            sum+=arr[i];
        }
        if(sum>s){

            // rem = sum - s;
            // cout<<rem<<endl;
            // int l = 1;
            // while(rem!=0){
            //     if(l%n!=0 && l%n!=(n-1)){
            //     arr[l%n]--;
            //     l++;
            //     rem--;
            
            }
        

        for (int i = 0; i < n; ++i)
        {
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

return 0;
}
