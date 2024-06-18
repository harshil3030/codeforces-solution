#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define inf (1LL<<60)
#define prDouble(x) cout << fixed << setprecision(10) << x
using namespace __gnu_pbds;
using namespace std;
#define int long long
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> ordset;

//vector<int> ans;
//void fun(int start, int &end, int &sm, vector<int> tmp, int curr, int &size, map<pair<pair<int, int>, int>, int> &memo) {
//    if (start > end) {
//        if (curr == sm && tmp.size() == size) {
//            ans = tmp;
//            return;
//        }
//        return;
//    }
//
//    if (memo.count({{start, curr}, (int)tmp.size()})) return;
//
//    tmp.push_back(start);
//    fun(start + 1, end, sm, tmp, curr + start, size, memo);
//    memo[{{start+1, curr+start}, (int)tmp.size()}]++;
//    tmp.pop_back();
//    fun(start + 1, end, sm, tmp, curr, size, memo);
//    memo[{{start+1, curr}, (int)tmp.size()}]++;
//}

void solve() {
    int n,l,r,s;
    cin >> n >> l >> r >> s;
    int size = r-l+1;
    if (s < (size*(size+1))/2) {
        cout << -1 << "\n";
        return;
    }

    int curr_size = 0;
    int sm = 0;
    set<int> st;
    for(int i = n; i >= 1; i--) {
        int need_ele = size - curr_size;
        int req_sm = s - sm;

        if (need_ele == 0) break;
        if (req_sm >= i + ((need_ele)*(need_ele-1))/2) {
            sm += i;
            curr_size++;
            st.insert(i);
        }
    }

    if (sm != s) {
        cout << -1 << "\n";
        return;
    }

    vector<int> give;
    for(int i = 1; i <= n; i++) {
        if (st.count(i)) continue;
        give.push_back(i);
    }
    l--, r--;
    int it = 0;
    for(int i = 0; i < l; i++) {
        cout << give[it++] << " ";
    }
    for(auto &x : st) {
        cout << x << " ";
    }
    for(int i = r+1; i < n; i++) {
        cout << give[it++] << " ";
    } cout << "\n";
    

//    int curr_size = 1;
//    int left = 0;
//    int right = s;
//    int tmp = 1;
//
//    set<int> st;
//    while (curr_size < size) {
//        left++;
//        st.insert(left);
//        right -= tmp;
//        tmp++;
//        curr_size++;
//    }
//
//    while (right > n && left < right && size > 1) {
//        if (st.count(left)) st.erase(left);
//         left++; right--;
//         st.insert(left);
//    }
//    st.insert(right);
//    if (st.size() != size) {
//        cout << -1  << "\n";
//        return;
//    }
//    int mx = *st.rbegin();
//    if (mx > n) {
//        cout << -1 << "\n";
//        return;
//    }
//
//    vector<int> give;
//    for(int i = 1; i <= n; i++) {
//        if (!st.count(i)) give.push_back(i);
//    }
//    l--, r--;
//
//    int k = 0;
//    for(int i = 0; i < l; i++) {
//        cout << give[k++] << " ";
//    }
//    for(auto &x: st) {
//        cout << x << " ";
//    }
//    for(int i = r+1; i < n; i++) {
//        cout << give[k++] << " ";
//    }
//    cout << "\n";

















//    vector<int> tmp;
//    map<pair<pair<int, int>, int>, int> memo;
//    fun(1, n, s, tmp, 0ll, size, memo);
//    if (ans.empty()) {
//        cout << -1 << "\n";
//        return;
//    }
//
//    map<int, int> mapping;
//    for(auto &x : ans) mapping[x]++;
//    vector<int> give;
//    for(int i = 1; i <= n; i++) {
//        if (mapping.count(i)) continue;
//        give.push_back(i);
//    }
//
//    int k = 0;
//    l--, r--;
//    for(int i = 0; i < l; i++) {
//        cout << give[k++] << " ";
//    }
//    for(auto &x : ans) cout << x << " ";
//    for(int i = r+1; i < n; i++) {
//        cout << give[k++] << " ";
//    } cout << "\n";
//    ans.clear();

//    t++;
//    while (t == 65) {
//        string t="";
//        t += to_string(n);
//        t += "||"; t += to_string(l);
//        t += "||"; t += to_string(r);
//        t += "||"; t += to_string(s);
//        cout << "\n";
//        return;
//    }

//    int currsize = 1;
//    int left = 0, right = s;
//    int tmp = 1;
//    map<int, int> vis;
//    while (currsize < size) {
//        left++;
//        vis[left]++;
//        right -= tmp;
//        tmp++;
//        currsize++;
//    }
//
//    bool ok = true;
//    while (right > n && right > left && size > 1) {
//        if (ok) {
//            vis.erase(left);
//            ok = false;
//        }
//        right--;
//        left++;
//    }
//    if (right == left) {
//        cout << -1 << "\n";
//        return;
//    }
//    if (!vis.count(left) && size > 1) vis[left]++;
//    if (right > n) {
//        cout << -1 << "\n";
//        return;
//    }
//    vis[right]++;
//    if (vis.size() != size) {
//        cout << -1 << "\n";
//        return;
//    }
//
//    int curr = 1;
//    vector<int> ans(n);
//    int k = 0; int k2 = 0;
//    l--, r--;
//    vector<int> give;
//    for(int i = 1; i <= n; i++) {
//        if (vis.count(i)) continue;
//        give.push_back(i);
//    }
//
//
//
//    for(int i = 0; i < l; i++) {
////        cout << give[k++] <<  " ";
//          ans[k2++] = give[k++];
//    }
//    for(auto &x : vis) {
//        ans[k2++] = x.first;
//    }
//    for(int i = r+1; i < n; i++) {
//        ans[k2++] = give[k++];
//    }
//    int sm = accumulate(ans.begin() + l, ans.begin() + r + 1, 0ll);
//    ok = false;
//    for(auto &x : ans) {
//        if (x > n) ok = true;
//    }
//    if (sm != s || ok) {
//        cout << -1 << "\n";
//        return;
//    }
//
//    for(auto &x : ans) {
//        cout << x << " ";
//    } cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt = 1; cin >> tt; while (tt--)
        solve();
    return 0;
}