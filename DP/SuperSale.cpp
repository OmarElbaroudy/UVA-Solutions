#include <bits/stdc++.h>

using namespace std;

const int INF = (int) 1e9 - 6;
const double EPS = 1e-9;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define all(c) (c).begin(),(c).end()
#define faster ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)
#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())        //for set or map or any container that implements find();
#define vpresent(c, x) (find(all(c),x) != (c).end())    //for vectors
#define print_array(arr, n) for (int i=0; i<n ;i++) { cout << arr[i] << ' ';}
#define nl "\n"
#define sp " "
#define debug(x) cout<<#x<<" = "<<(x)<<nl
#define read_array(arr, n) for(int i=0; i<n; i++){cin >> arr[i];}

int t, n, g, mw, p[1010], w[1010], memo[40][1010];

int dp(int remw, int idx) {
    if (remw < 0) return -INF;
    if (idx == n) return 0;
    int &ans = memo[remw][idx];
    if (ans != -1) return ans;
    ans = max(dp(remw - w[idx], idx + 1) + p[idx], dp(remw, idx + 1));
    return ans;
}

int main() {
    faster;
    cin >> t;
    while (t--) {
        cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> p[i] >> w[i];
        }
        cin >> g;
        while (g--) {
            cin >> mw;
            memset(memo, -1, sizeof(memo));
            ans += dp(mw, 0);
        }
        cout << ans << nl;
    }
}


