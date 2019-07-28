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

int t, n, m, k, d;

class DSU {
private:
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

inline bool reachable(ii &a, ii &b, bool treetotree) {
    if (treetotree)
        return hypot(a.first - b.first, a.second - b.second) - k < EPS;
    return hypot(a.first - b.first, a.second - b.second) - d < EPS;
}

inline bool connectable(vii &a, vii &b, bool treetotree) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            if (reachable(a[i], b[j], treetotree))
                return true;
        }
    }
    return false;
}

int main() {
    faster;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k >> d;
        vii doctor(m);
        vii trees[n];

        for (int i = 0; i < m; i++) {
            cin >> doctor[i].first >> doctor[i].second;
        }

        for (int l, i = 0; i < n; i++) {
            cin >> l;
            trees[i] = vii(l);
            for (int j = 0; j < l; j++) {
                cin >> trees[i][j].first >> trees[i][j].second;
            }
        }

        DSU uf(n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (connectable(trees[i], trees[j], true))
                    uf.unionSet(i, j);
            }
        }
        for (int i = 0; i < n; i++) {
            if (connectable(doctor, trees[i], false)) {
                uf.unionSet(n, i);
            }
        }
        printf("%s\n", uf.isSameSet(0, n) ? "Tree can be saved :)" : "Tree can't be saved :(");

    }
}




