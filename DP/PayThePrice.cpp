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

int n, l, r;
ll memo[310][310][310];

ll dp(int sum, int c, int k) {
    if (c < 0 || k > 300 || sum > n) return 0;
    if (sum == n) return c == 0;
    ll &ans = memo[sum][c][k];
    if (ans != -1) return ans;
    ans = dp(sum + k, c - 1, k) + dp(sum, c, k + 1);
    return ans;
}

ll solve(int sum, int c, int k) {
    if (c < 0 || sum > n) return 0;
    if (sum == n) return c == 0;
    ll &ans = memo[sum][c][k];
    if (ans != -1) return ans;
    ans = 0;
    for (int i = k; i <= n; i++) {
        ans += dp(sum + i, c - 1, i);
    }
    return ans;
}

int main() {
    faster;
    string line;
    while (getline(cin, line)) {
        stringstream ss = stringstream(line);
        ss >> n >> l >> r;
        l = (l) ? l : 1, r = (r) ? r : n;
        l = min(l, 300), r = min(r, 300);
        memset(memo, -1, sizeof(memo));
        ll ans = 0;
        for (int i = l; i <= r; i++) {
            ans += dp(0, i, 1);
        }
        cout << ans << endl;
    }

}


