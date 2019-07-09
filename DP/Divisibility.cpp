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

int n, m, k, memo[110][10010], arr[10010];

/*the trick about this problem is that the constraints are to big
 * considering the summation 10000*10000 so such solution will give
 * TLE however we don't need the summation we only need the mod of the
 * summation that is <100 giving the accepted solution however notice 
 * that the mod of negative numbers can be negative or positive 
 * to avoid RTE when accessing the memo let's always take in consideration
 * the +ve mod for negative numbers will be given by the equation -pq+r
 * where r is the remainder. To convert the mod of a negative number into
 * positive apply x%k + k all to the % of k this way we have all the % as
 * pos integers another trick to solve this problem is to use offset for negative
 * mods */

int dp(int sum, int idx) {
    if (idx == n) return sum == 0;
    int &ans = memo[sum][idx];
    if (ans != -1) return ans;
    int pos = ((sum + arr[idx]) % k + k) % k;
    int neg = ((sum - arr[idx]) % k + k) % k;
    ans = dp(pos, idx + 1) || dp(neg, idx + 1);
    return ans;
}

int main() {
    faster;
    cin >> m;
    while (m--) {
        memset(memo, -1, sizeof(memo));
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        if (dp(0, 0)) cout << "Divisible\n";
        else cout << "Not divisible\n";
    }
}


