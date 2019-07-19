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

bool memo[35][35][6010], sign[35];
int arr[35], n, offset = 3000;
set<int> ts;

void dp(int idx, int opnb, int sum) {
    if (idx == n) {
        ts.insert(sum);
        return;
    }
    if (memo[idx][opnb][sum + offset]) return;
    int cur = sign[idx] ? -arr[idx] : arr[idx];
    cur = ((opnb & 1) == 0) ? cur : -cur;
    if (opnb > 0) {
        dp(idx + 1, opnb - 1, sum + cur);
    }
    if (sign[idx]) {
        dp(idx + 1, opnb + 1, sum + cur);
    }
    dp(idx + 1, opnb, sum + cur);
    memo[idx][opnb][sum + offset] = true;
}

int main() {
    faster;
    string line;
    char c;
    sign[0] = false;
    while (getline(cin, line)) {
        stringstream ss(line);
        ss >> arr[0];
        for (n = 1; ss >> c; n++) {
            sign[n] = c == '-';
            ss >> arr[n];
        }
        memset(memo, 0, sizeof(memo));
        ts.clear();
        dp(0, 0, 0);
        cout << ts.size() << nl;
    }
}

