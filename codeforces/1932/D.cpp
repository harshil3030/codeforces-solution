#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define int ll
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordset;
int mod = 1e9 + 7;

void solve();

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt = 1;
    cin >> tt;
    while (tt--)
        solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;
    char ch;
    cin >> ch;
    vector<pair<int, char>> vp(2 * n);
    vector<pair<int, char>> trump;

    vector<pair<int, char>> c;
    vector<pair<int, char>> d;
    vector<pair<int, char>> h;
    vector<pair<int, char>> s;

    for (int i = 0; i < 2 * n; i++) {
        string t;
        cin >> t;
        char chr = t[1];
        int ele = t[0] - '0';

        if (chr == 'S') {
            s.push_back({ele, chr});
        } else if (chr == 'C') {
            c.push_back({ele, chr});
        } else if (chr == 'D') {
            d.push_back({ele, chr});
        } else if (chr == 'H') {
            h.push_back({ele, chr});
        }

    }

    sort(s.begin(), s.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    sort(h.begin(), h.end());

    vector<pair<string, string>> ans;

    auto solvemin = [&](vector<pair<int, char>> &ff, int &i, int &j) {
        while (j < ff.size()) {
            ans.push_back({to_string(ff[i].first) + ff[i].second, to_string(ff[j].first) + ff[j].second});
            j += 2;
            i += 2;
        }
        j--;
        return;
    };

    auto solvefortmp = [&](vector<pair<int, char>> &tmp, vector<pair<int, char>> &ff, int &ffj, int &tmpi) {
        while (ffj < ff.size() && tmpi < tmp.size()) {
            ans.push_back({to_string(ff[ffj].first) + ff[ffj].second, to_string(tmp[tmpi].first) + tmp[tmpi].second});
            ffj++;
            tmpi++;
        }
        return;
    };

    int flg = 0;
    auto getsol = [&](vector<pair<int, char>> &tmp, vector<pair<int, char>> &ff, vector<pair<int, char>> &ss, vector<pair<int, char>> &tt) {
        int ffi = 0, ffj = 1;
        solvemin(ff, ffi, ffj);
        int ssi = 0, ssj = 1;
        solvemin(ss, ssi, ssj);
        int tti = 0, ttj = 1;
        solvemin(tt, tti, ttj);

        int tmpi = 0;
        solvefortmp(tmp, ff, ffj, tmpi);
        solvefortmp(tmp, ss, ssj, tmpi);
        solvefortmp(tmp, tt, ttj, tmpi);

        if (ffj < ff.size() || ssj < ss.size() || ttj < tt.size()) {
            flg = 1;
            return;
        }

        if ((tmp.size() - tmpi) % 2) {
            flg = 1;
            return;
        }

        int tmpj = tmpi + 1;
        while (tmpj < tmp.size()) {
            ans.push_back({to_string(tmp[tmpi].first) + tmp[tmpi].second, to_string(tmp[tmpj].first) + tmp[tmpj].second});
            tmpj += 2;
            tmpi += 2;
        }
    };

    if (ch == 'S') {
        getsol(s, c, d, h);
    } else if (ch == 'D') {
        getsol(d, s, c, h);
    } else if (ch == 'H') {
        getsol(h, s, c, d);
    } else {
        getsol(c, s, h, d);
    }

    if (flg == 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i].first << " " << ans[i].second << "\n";
        }
    }
}
