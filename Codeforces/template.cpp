#include <bits/stdc++.h>
using namespace std;

// Speed up input and output
void solve() {
    // Your logic goes here
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // Example output
    // cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;

}

// map<int,int> mp;

// for(int x : a) mp[x]++;

// for(auto it : mp) {
//     cout << it.first << " " << it.second << "\n";
// }

// sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b){
//     return a.second < b.second;
// });

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        // solve each test case here
    }

    return 0;
}


// 2. Single Test Case (No t)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << n << "\n";

    return 0;
}


// 3. Array Input
// int n;
// cin >> n;

// vector<int> a(n);
// for(int i = 0; i < n; i++) {
//     cin >> a[i];
// }


// 4. 2D Matrix Input
// int n, m;
// cin >> n >> m;

// vector<vector<int>> mat(n, vector<int>(m));

// for(int i = 0; i < n; i++) {
//     for(int j = 0; j < m; j++) {
//         cin >> mat[i][j];
//     }
// }


// 5. String Input
// string s;
// cin >> s;

// 👉 If spaces included:

// string s;
// getline(cin, s);



// 6. Multiple Inputs per Test Case
// int t;
// cin >> t;

// while(t--) {
//     int n, k;
//     cin >> n >> k;

//     vector<int> a(n);
//     for(int i = 0; i < n; i++) cin >> a[i];
// }

// 7. Pair / Tuple Input
// int n;
// cin >> n;

// vector<pair<int,int>> vp(n);
// for(int i = 0; i < n; i++) {
//     cin >> vp[i].first >> vp[i].second;
// }


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vi a(n);
        for(int &x : a) cin >> x;

        // logic here
    }

    return 0;
}


// stack<int> st;

// for(int i = 0; i < n; i++) {
//     while(!st.empty() && st.top() < a[i]) {
//         st.pop();
//     }
//     st.push(a[i]);
// }


// 13. Queue / BFS
// queue<int> q;
// q.push(start);

// while(!q.empty()) {
//     int node = q.front();
//     q.pop();

//     for(auto it : adj[node]) {
//         q.push(it);
//     }
// }

// if(n & (1 << i)) {
//     // ith bit is set
// }

// // count bits
// int cnt = __builtin_popcount(n);


// 20. Graph Input (Adj List)
// int n, m;
// cin >> n >> m;

// vector<vector<int>> adj(n);

// for(int i = 0; i < m; i++) {
//     int u, v;
//     cin >> u >> v;
//     adj[u].push_back(v);
//     adj[v].push_back(u);
// }

// ll power(ll base, ll exp) {
//     ll res = 1;
//     base %= MOD;
//     while (exp > 0) {
//         if (exp % 2 == 1) res = (res * base) % MOD;
//         base = (base * base) % MOD;
//         exp /= 2;
//     }
//     return res;
// }

// struct DSU {
//     vector<int> parent;
//     DSU(int n) {
//         parent.resize(n + 1);
//         iota(parent.begin(), parent.end(), 0);
//     }
//     int find(int i) {
//         if (parent[i] == i) return i;
//         return parent[i] = find(parent[i]); // Path compression
//     }
//     void unite(int i, int j) {
//         int root_i = find(i);
//         int root_j = find(j);
//         if (root_i != root_j) parent[root_i] = root_j;
//     }
// };


// const int MAXN = 1000005;
// bool is_prime[MAXN];
// void sieve() {
//     fill(is_prime, is_prime + MAXN, true);
//     is_prime[0] = is_prime[1] = false;
//     for (int p = 2; p * p < MAXN; p++) {
//         if (is_prime[p]) {
//             for (int i = p * p; i < MAXN; i += p)
//                 is_prime[i] = false;
//         }
//     }
// }



// int t;
// cin >> t;

// while(t--) {
//     int n, m, k;
//     cin >> n >> m >> k;

//     vector<int> a(n), b(m);

//     for(int &x : a) cin >> x;
//     for(int &x : b) cin >> x;
// }



// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int x) {
//         val = x;
//         left = right = NULL;
//     }
// };

// TreeNode* buildTree() {
//     int x;
//     cin >> x;

//     if(x == -1) return NULL;

//     TreeNode* root = new TreeNode(x);
//     queue<TreeNode*> q;
//     q.push(root);

//     while(!q.empty()) {
//         TreeNode* curr = q.front();
//         q.pop();

//         int l, r;
//         cin >> l >> r;

//         if(l != -1) {
//             curr->left = new TreeNode(l);
//             q.push(curr->left);
//         }

//         if(r != -1) {
//             curr->right = new TreeNode(r);
//             q.push(curr->right);
//         }
//     }

//     return root;
// }


#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve() {
    // take input for ONE test case here
    
    int n;
    cin >> n;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    // logic here
    
    cout << "answer\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--) {
        solve();  // solve one test case
    }

    return 0;
}


bool canSplit(vector<int>& a, int k, long long mid) {
    long long sum = 0;
    int parts = 1;

    for(int x : a) {
        if(sum + x > mid) {
            parts++;
            sum = x;
        } else {
            sum += x;
        }
    }

    return parts <= k;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    long long l = *max_element(a.begin(), a.end());
    long long r = accumulate(a.begin(), a.end(), 0LL);

    long long ans = r;

    while(l <= r) {
        long long mid = (l + r) / 2;

        if(canSplit(a, k, mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << ans << "\n";
}