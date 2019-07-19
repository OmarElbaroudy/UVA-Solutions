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

int n, tmp, p[15];
ll memo[15][15];


ll dp(int i, int j) {
    if (i == j)
        return 0;
    if (memo[i][j] != -1) return memo[i][j];
    ll ans = LONG_MAX, cost;
    for (int k = i; k < j; k++) {
        cost = dp(i, k) + dp(k + 1, j) + p[i - 1] * p[k] * p[j];
        ans = min(ans, cost);
    }
    return memo[i][j] = ans;
}

string print(int i, int j) {
    if (i == j)
        return "A" + to_string(i);
    ll ans = dp(i, j), cost;
    for (int k = i; k < j; k++) {
        cost = dp(i, k) + dp(k + 1, j) + p[i - 1] * p[k] * p[j];
        if (cost == ans) {
            return "(" + print(i, k) + " x " + print(k + 1, j) + ")";
        }
    }
    return "";
}

int main() {
    faster;
    int cnt = 1;
    while (true) {
        cin >> n;
        if (n == 0) return 0;
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                cin >> p[i];
                ++i;
                cin >> p[i];
            } else {
                cin >> tmp >> p[i];
            }
        }
        memset(memo, -1, sizeof(memo));
        dp(0, n - 1);
        printf("Case %d: %s\n", cnt++, print(1, n).c_str());
    }
}

