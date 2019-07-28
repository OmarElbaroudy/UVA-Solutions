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

int n, m, k, s;

class DSU {
public:
    vector<int> p, rank, set_size;
    int num_sets;
public:
    DSU(int N) {
        num_sets = N;
        rank.assign(N, 0);
        p.assign(N, 0);
        set_size.assign(N, 1); //each set is initially 1
        for (int i = 0; i < N; i++) {
            p[i] = i;
        }
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (!isSameSet(i, j)) {
            num_sets--;
            int x = findSet(i), y = findSet(j);
            if (rank[x] > rank[y]) {
                p[y] = x;
                set_size[x] += set_size[y];
            } else {
                p[x] = y;
                set_size[y] += set_size[x];
                if (rank[x] == rank[y]) rank[y]++;
            }
        }
    }

    int num() { return num_sets; }

    int size(int i) { return set_size[findSet(i)]; }
};

int main() {
    faster;
    while (true) {
        cin >> n >> m;
        if (n == m && n == 0) break;
        DSU uf(n);
        while (m--) {
            cin >> k >> s;
            for (int x, i = 0; i < k - 1; i++) {
                cin >> x;
                uf.unionSet(s, x);
            }
        }
        cout << uf.size(0) << nl;
    }
}




