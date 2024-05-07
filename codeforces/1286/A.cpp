#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;
void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int tt = 1; cin >> tt; while (tt--)  
    solve();
    return 0;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto &x : v) cin >> x;
	/*int odd = 0;
	int even = 0;

	for (int i = 0; i < n; i++) {
		if (v[i] != 0) {
			odd += v[i] % 2;
			even += v[i] % 2 == 0;
		}
	}
	odd = (n+1)/2 - odd;
	even = (n)/2 - even;
*/    
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
	int dp[n][n+1][n+1][2];

    // for (int x = 0; x <= odd; x++) {
    //     for (int y = 0; y <= even; y++) {
    //         if (v[0]) {
    //             if (v[0] % 2 == 0) {
    //                      dp[0][x][y][0] = 0;
    //                      dp[0][x][y][1] = 1e9;
    //             } else {
    //                     dp[0][x][y][1] = 0;
    //                     dp[0][x][y][0] = 1e9;
    //             }
    //         } else {
    //             if (x == 0 && y == 0) {
    //                 dp[0][x][y][0] = dp[0][x][y][1] = 1e9;
    //             } else if (x == 0) {
    //                 dp[0][x][y][0] = 1e9;
    //                 dp[0][x][y][1] = 0;
    //             } else if (y == 0) {
    //                 dp[0][x][y][0] = 0;
    //                 dp[0][x][y][1] = 1e9;        
    //             } else {
    //                 dp[0][x][y][0] = 0;
    //                 dp[0][x][y][1] = 0;
    //             }
    //         }
    //     }
    // }


    for (int i = 0; i < n; i++) {
        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= n; y++) {
                dp[i][x][y][0] = dp[i][x][y][1] = 1e9;
            }
        }
    }

    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (v[0]) {
               if (y > 0) if(v[0] % 2 == 0) dp[0][x][y][0] = 0;
               if (x > 0) if(v[0] % 2 == 1) dp[0][x][y][1] = 0;
            } else {
                if (x > 0) dp[0][x][y][1] = 0;
                if (y > 0) dp[0][x][y][0] = 0;
            }
        }
    }



	for (int i = 1; i < n; i++) {

        // cout << "at index i " << i << "\n"; 

		for (int x = 0; x <= n; x++) {
			for (int y = 0; y <= n; y++) {
                if (!v[i]) {
                    if (y > 0) dp[i][x][y][0] = min(dp[i-1][x][y-1][0], dp[i-1][x][y-1][1] + 1);
                    if (x > 0) dp[i][x][y][1] = min(dp[i-1][x-1][y][0] + 1, dp[i-1][x-1][y][1]); 
				} else {
                     if (v[i] % 2 == 0) {
                         if(y > 0) dp[i][x][y][0] = min(dp[i-1][x][y-1][0], dp[i-1][x][y-1][1] + 1);
                    } else {
                        if(x > 0) dp[i][x][y][1] = min(dp[i-1][x-1][y][1], dp[i-1][x-1][y][0] + 1);
                    }
                }

                // cout << x << " " << y << " " << dp[i][x][y][0] << " " << dp[i][x][y][1] << "\n";
			}
		}
	}





    cout << min(dp[n-1][(n+1)/2][n/2][0], dp[n-1][(n+1)/2][n/2][1]) << "\n";

}
