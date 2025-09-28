// C. Limited Edition Shop
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes
// cYsmix - House With Legs
// ⠀

// There is a shop with n
// objects numbered from 1 to n, and only one copy of each object. According to you, the objects have values v1,v2,…,vn

// (which can be negative).

// Alice and Bob have their own order of preference of objects (a1,a2,…,an
// and b1,b2,…,bn respectively). In particular, Alice's favourite object is a1, followed by a2, etc.; Bob's favourite object is b1, followed by b2

// , etc.

// For n

// times, one of them goes to the shop and buys her or his most favourite object still in the shop. At the end, Alice and Bob have their own sets of objects.

// Now the shop is empty, and you wonder whether Alice's preferences are similar to yours. Over all sets of objects that Alice could have bought, what's the maximum sum of values according to you?
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
// (1≤n≤2⋅105

// ) — the number of objects.

// The second line of each test case contains n
// integers v1,v2,…,vn (−109≤vi≤109

// ) — the values of the objects, according to you.

// The third line of each test case contains n
// integers a1,a2,…,an (1≤ai≤n) — Alice's order of preference. The ai

// are distinct.

// The fourth line of each test case contains n
// integers b1,b2,…,bn (1≤bi≤n) — Bob's order of preference. The bi

// are distinct.

// It is guaranteed that the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output a single integer: the maximum sum of values over all sets of objects that Alice could have bought.
// Example
// Input
// Copy

// 8
// 3
// 1 -1 1
// 3 1 2
// 2 3 1
// 3
// -2 5 2
// 3 1 2
// 2 3 1
// 3
// -1 -2 -3
// 3 1 2
// 2 3 1
// 3
// 1000000000 1000000000 1000000000
// 3 1 2
// 2 3 1
// 4
// 5 -15 10 -5
// 2 4 3 1
// 1 4 2 3
// 4
// -5 -5 -5 100
// 2 3 1 4
// 4 1 2 3
// 4
// -1 -100 5 10
// 1 2 3 4
// 2 3 4 1
// 12
// -4 6 10 10 1 -8 6 2 -8 -4 0 -6
// 11 12 7 3 6 8 1 5 10 2 9 4
// 7 5 3 6 1 2 8 12 9 4 10 11

// Output
// Copy

// 2
// 5
// 0
// 3000000000
// 10
// 85
// 14
// 24

// Note

// In the first test case, Alice can buy the sets of objects []
// (empty), [1], [3], [3,1], [3,1,2] (the objects are ordered by purchase time). For example, for Alice to buy [1]

// , the two can enter the store in the following order:

//     Bob enters and buys object 2

// ;
// Bob enters and buys object 3
// (object 2
// is sold out);
// Alice enters and buys object 1
// (object 3

//     is sold out). 

// The set of objects with maximum total value according to you is [3,1]
// , which has value v3+v1=2

// .

// In the second test case, Alice's and Bob's preferences are the same as in the first test case, but now the set of objects with maximum total value is [3,1,2]
// , with value 5

// .

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N = 2e5 + 69;
int seg[4 * N], lz[4 * N];

void updlz(int l, int r, int pos){
    seg[pos] += lz[pos];
    if (l != r){
        lz[pos * 2] += lz[pos];
        lz[pos * 2 + 1] += lz[pos];
    }
    lz[pos] = 0;
}

void upd(int l, int r, int pos, int ql, int qr, int v){
    updlz(l, r, pos);
    
    if (l >= ql && r <= qr){
        lz[pos] += v;
        updlz(l, r, pos);
    } else if (l > qr || r < ql){
        
    } else {
        int mid = (l + r) / 2;
        upd(l, mid, pos * 2, ql, qr, v);
        upd(mid + 1, r, pos * 2 + 1, ql, qr, v);
        seg[pos] = max(seg[pos * 2], seg[pos * 2 + 1]);
    }
}

int query(int l, int r, int pos, int ql, int qr){
    updlz(l, r, pos);
    
    if (l >= ql && r <= qr){
        return seg[pos];
    } else if (l > qr || r < ql){
        return -INF;
    } else {
        int mid = (l + r) / 2;
        return max(query(l, mid, pos * 2, ql, qr), query(mid + 1, r, pos * 2 + 1, ql, qr));
    }
}

void Solve() 
{
    int n; cin >> n;
    
    vector <int> c(n + 1), a(n + 1), b(n + 1), pa(n + 1), pb(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        pa[a[i]] = i;
    }
    for (int i = 1; i <= n; i++){
        cin >> b[i];
        pb[b[i]] = i;
    }
    
    vector <int> p(n + 1);
    for (int i = 1; i <= n; i++){
        p[i] = pb[a[i]];
    }
    
    vector <int> v(n + 1);
    for (int i = 1; i <= n; i++){
        v[i] = c[a[i]];
    }
    
    // so at p[i], look over previous max 
    // if max < p[i], take this as A 
    // potentially, take as B as well, updating max 
    // if max > p[i], forced as B
    
    for (int i = 0; i <= 4 * n + 4; i++){
        seg[i] = -1e17;
        lz[i] = 0;
    }
    
    auto chmax = [&](int x, int v){
        int curr = query(0, n, 1, x, x);
        int add = max(0LL, v - curr);
        upd(0, n, 1, x, x, add);
    };
    
    chmax(0, 0);
    
    for (int i = 1; i <= n; i++){
        int val = query(0, n, 1, 0, p[i] - 1);
        chmax(p[i], val);
        upd(0, n, 1, 0, p[i] - 1, v[i]);
    }
    
    cout << query(0, n, 1, 0, n) << "\n";
}

int32_t main() 
{
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        Solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}