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

int n, s;
ll memo[2][70][70];

ll dp(int prev, int idx, int cnt) {
    if (cnt > s) return 0;
    if (idx == n) return (cnt == s) ? 1 : 0;
    ll &ans = memo[prev][idx][cnt];
    if (ans != -1) return ans;
    ans = dp(1, idx + 1, cnt + prev) + dp(0, idx + 1, cnt);
    return ans;
}

int main() {
    faster;
    while (true) {
        cin >> n >> s;
        if (n < 0 && s < 0) return 0;
        memset(memo, -1, sizeof(memo));
        cout << (dp(1, 0, 0)) << nl;
    }
}


