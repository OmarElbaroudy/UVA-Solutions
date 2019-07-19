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

const int N = 10010;
int n, arr[N], le[N], ri[N];
vi length;

void lis(int n, int *dist) {
    length.clear();
    for (int i = 0; i < n; i++) {
        const int num = arr[i];
        int pos = lower_bound(length.begin(), length.end(), num) - length.begin();
        if (pos == length.size()) length.push_back(num);
        else length[pos] = num;
        dist[i] = pos + 1;

    }
}

int main() {
    faster;
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        lis(n, le);
        reverse(arr, arr + n);
        lis(n, ri);
        int ans = 1;
        for (int i = 0; i < n; i++) {
            int cur = min(le[i], ri[n - i - 1]);
            ans = max(ans, cur * 2 - 1);
        }
        cout << ans << nl;
    }
}


