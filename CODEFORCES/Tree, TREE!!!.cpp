// F. Tree, TREE!!!
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// Roots change, but the tree stands strong — so should your logic.

// Behruzbek received a tree∗
// with n nodes. For a chosen root† r

// , Behruzbek wants to find cuteness of the tree.

// Consider every set of k
// distinct nodes of the tree. For each such set, compute its lowest common ancestor (LCA) in the tree when it is rooted at r. Let Sr be the set of all distinct nodes obtained this way; then cuteness of the tree is |Sr|, where |S|

// means the number of distinct elements.

// After discovering the cuteness of trees, Behruzbek became interested in finding the kawaiiness of the tree! Kawaiiness is defined as:

// ∑r=1n|Sr|=|S1|+|S2|+⋯+|Sn|

// Unfortunately, Behruzbek is feeling sleepy now. Please help Behruzbek by finding the kawaiiness of the tree!

// ∗

// A tree is a connected graph without cycles.

// †

// A rooted tree is a tree where one vertex is special and called the root.
// Input

// The first line contains the number of test cases t
// (1≤t≤104

// ).

// The first line of each test case contains two integers n
// and k (2≤k≤n≤2⋅105

// ) — the number of vertices in the tree and the number of distinct integers to be chosen.

// The following n−1
// lines of each test case describe the tree. Each of the lines contains two integers u and v (1≤u,v≤n, u≠v) that indicate an edge between vertex u and v

// . It is guaranteed that these edges form a tree.

// It is guaranteed that the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output one integer — the value of ∑r=1n|Sr|

// .
// Example
// Input
// Copy

// 4
// 2 2
// 1 2
// 5 3
// 1 2
// 1 3
// 1 4
// 1 5
// 6 3
// 1 2
// 1 3
// 2 4
// 2 5
// 3 6
// 10 5
// 5 6
// 4 9
// 3 9
// 2 6
// 2 8
// 8 9
// 6 10
// 1 6
// 4 7

// Output
// Copy

// 2
// 9
// 17
// 35

// Note

// Let f(i)=|Si|

// For the third example:

//     Root is 1

// , only 1 and 2 nodes can be obtained. For example, we can choose: LCA(4,5,6)=1 and LCA(2,4,5)=2. As a result, f(1)=2
// .

// Root is 2
// , only 1 and 2 nodes can be obtained. For example, we can choose: LCA(1,3,6)=1 and LCA(1,4,5)=2. As a result, f(2)=2
// .

// Root is 3
// , f(3)=3. For example, node 3 can be obtained by choosing: LCA(2,4,6)=3
// .

// Root is 4
// , f(4)=3. For example, node 2 can be obtained by choosing: LCA(1,3,5)=2
// .

// Root is 5
// , f(5)=3. For example, node 2 can be obtained by choosing: LCA(3,4,6)=2
// .

// Root is 6
// , f(6)=4. For example, node 3 can be obtained by choosing: LCA(3,4,5)=2

//     . 

// Overall, 2+2+3+3+3+4=17

// .




#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    using ll = long long;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<vector<int>> a(n);
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v, --u, --v;
            a[u].emplace_back(v);
            a[v].emplace_back(u);
        }
        ll ans = 0; 
        vector<int> sz(n, 1), dp(n); // initial subtree sizes and dp[i] = |S_i|
        auto dfs = [&] (auto &dfs, int v, int p) -> void{ // performing DFS in the tree
            for (int u : a[v]) {
                if (u != p) { // to avoid visiting parent again
                    dfs(dfs, u, v); // recursively visit subtree
                    dp[v] += dp[u]; // answer for subtree of v (merge)
                    sz[v] += sz[u]; // merge
                }
            }
            dp[v] += sz[v] >= k;
        };
        dfs(dfs, 0, -1); // arbitrary starting point
        auto reroot = [&] (auto &reroot, int v, int p) -> void{
            for (int u : a[v]) {
                if (u != p) {
                    int add = dp[v] - dp[u] - (n - sz[u] < k); // value of v other than subtree of u
                    dp[u] = add + (dp[u] + (sz[u] < k));  
                    reroot(reroot, u, v); //continue rerooting
                    // Actually you don't need dp[v] for each subtree (because dp[u] cancels out), I did it for clarity. 
                }
            }
        };
        reroot(reroot, 0, -1);
        cout << accumulate(dp.begin(), dp.end(), 0ll) << '\n'; // print the answer
    }
}




