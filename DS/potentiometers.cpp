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

int n, cnt = 1;

template<typename T>
struct SegmentTree {     // One-based except Input Array
    int N;
    T *input;
    vector<T> lazy;
    vector<T> stree;

    inline T f(T a, T b) { return a + b; }

    void build(int v, int l, int r) {
        if (l == r) {
            stree[v] = input[l - 1];
            return;
        }
        int mid = (l + r) >> 1;
        build(v << 1, l, mid);
        build(v << 1 | 1, mid + 1, r);
        stree[v] = f(stree[v << 1], stree[v << 1 | 1]);
    }

    SegmentTree(T arr[], int n) {
        input = arr;
        N = n;
        int sz = 1;
        while (sz < N)
            sz <<= 1;
        stree.assign(sz << 1, 0);
        lazy.assign(sz << 1, 0);
        build(1, 1, N);
    }

    void updatePoint(int v, int l, int r, int idx, T val) {
        if (l == r) {
            stree[v] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid)
            updatePoint(v << 1, l, mid, idx, val);
        else
            updatePoint(v << 1 | 1, mid + 1, r, idx, val);
        stree[v] = f(stree[v << 1], stree[v << 1 | 1]);
    }

    void updatePoint(int idx, T val) {  //Input index 1-based
        updatePoint(1, 1, N, idx, val);
    }

    void propagate(int v, int l, int mid, int r) {
        lazy[v << 1] += lazy[v];
        lazy[v << 1 | 1] += lazy[v];
        stree[v << 1] += (mid - l + 1) * lazy[v];
        stree[v << 1 | 1] += (r - mid) * lazy[v];
        lazy[v] = 0;
    }

    void updateRange(int v, int l, int r, int rangeStart, int rangeEnd, T val) {
        if (r < rangeStart || l > rangeEnd)
            return;
        if (l >= rangeStart && r <= rangeEnd) {
            stree[v] += (r - l + 1) * val;
            lazy[v] += val;
            return;
        }
        int mid = (l + r) >> 1;
        propagate(v, l, mid, r);
        updateRange(v << 1, l, mid, rangeStart, rangeEnd, val);
        updateRange(v << 1 | 1, mid + 1, r, rangeStart, rangeEnd, val);
        stree[v] = f(stree[v << 1], stree[v << 1 | 1]);
    }

    void updateRange(int l, int r, T val) {
        updateRange(1, 1, N, l, r, val);
    }

    T query(int v, int l, int r, int queryStart, int queryEnd) {
        if (r < queryStart || l > queryEnd)
            return 0; //dummy variable
        if (l >= queryStart && r <= queryEnd)
            return stree[v];
        int mid = (l + r) >> 1;
        propagate(v, l, mid, r);
        T q1 = query(v << 1, l, mid, queryStart, queryEnd);
        T q2 = query(v << 1 | 1, mid + 1, r, queryStart, queryEnd);
        return f(q1, q2);
    }

    T query(int l, int r) {
        return query(1, 1, N, l, r);
    }
};

int main() {
    faster;
    while (true) {
        cin >> n;
        if (n == 0) return 0;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        SegmentTree<int> stree(arr, n);
        if (cnt > 1) cout << nl;
        cout << "Case " << (cnt++) << ":\n";
        while (true) {
            int x, y;
            string s;
            cin >> s;
            if (s == "END") break;
            cin >> x >> y;
            if (s == "M") {
                int ans = stree.query(x, y);
                cout << ans << nl;
            } else {
                int val = stree.query(x, x);
                val = y - val;
                stree.updatePoint(x, val);
            }
        }
    }
}


