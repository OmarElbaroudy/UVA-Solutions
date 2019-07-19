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

int t, n, m, r1, c1, r2, c2, memo[105][105];

///complexity O(n^4) complexity however can be reduced to O(n^2) using the area under histogram problem
int main() {
    faster;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                memo[i][j] = 1;
            }

        while (m--) {
            cin >> r1 >> c1 >> r2 >> c2;
            r1--, c1--;
            for (int i = r1; i < r2; i++) {
                for (int j = c1; j < c2; j++) {
                    memo[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i) memo[i][j] += memo[i - 1][j];
                if (j) memo[i][j] += memo[i][j - 1];
                if (i && j) memo[i][j] -= memo[i - 1][j - 1];
            }
        }

        int ans = 0;
        //calculating the summation of all 1 inside a rectangle
        //by subtracting all ones outside this rectangle
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = i; k < n; k++) {
                    for (int l = j; l < n; l++) {
                        int sum = memo[k][l];
                        if (i) sum -= memo[i - 1][l];
                        if (j) sum -= memo[k][j - 1];
                        if (i && j) sum += memo[i - 1][j - 1];
                        if (sum == (k - i + 1) * (l - j + 1)) ans = max(ans, sum);
                    }
                }
            }
        }

        cout << ans << nl;
    }
}


