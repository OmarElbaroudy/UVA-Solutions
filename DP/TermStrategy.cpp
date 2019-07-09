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

int t, n, m, arr[15][115], memo[15][115];

int dp(int idx, int remh) {
    if (remh < 0) return -INF;
    if (idx == n) return 0;
    int &ans = memo[idx][remh];
    if (ans != -1) return ans;
    ans = -INF;
    for (int i = 0; i < m && i < remh; i++) {
        if (arr[idx][i] > 4) {
            ans = max(ans, dp(idx + 1, remh - i - 1) + arr[idx][i]);
        }
    }
    return ans;
}

int main() {
    faster;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        memset(memo, -1, sizeof(memo));
        double ans = 1e-9 + dp(0, m) / (double) n;
        if (ans < 5.0)
            puts("Peter, you shouldn't have played billiard that much.");
        else
            printf("Maximal possible average mark - %.2lf.\n", ans);
    }
}


