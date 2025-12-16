// B. Marble Council
// time limit per test
// 2 seconds
// memory limit per test
// 512 megabytes

// You are given a multiset a
// , which consists of n integers a1,a2,…,an. You would like to generate a new multiset s

// through the following procedure:

//     Partition a

// into any number of non-empty multisets x1,x2,…,xk, such that each element of a
// belongs to exactly one of these multisets.
// Initially, s
// is empty. From each xi, choose one of its modes∗ and insert it into s

//     . 

// Please count the number of different multisets s
// that can be generated through the procedure, modulo 998244353

// .

// Please note that the number of different multisets is counted, which means that the order of elements does not matter. However, the count of each element does matter, i.e. {1,1,2},{1,2},{1,1,2,2}

// are all considered different.

// ∗

// The mode of a multiset is defined as the element which appears the most; if several elements are tied as the maximum, then all of them are considered modes.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤5000

// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
// (1≤n≤5000) — the size of multiset a

// .

// The second line of each test case contains n
// integers a1,a2,…,an (1≤ai≤n

// ).

// It is guaranteed that the sum of n
// over all test cases does not exceed 5000

// .
// Output

// For each test case, print one line containing a single integer — the number of different multisets you can obtain, modulo 998244353

// .
// Example
// Input
// Copy

// 5
// 3
// 1 2 3
// 3
// 1 1 1
// 3
// 1 2 2
// 10
// 1 1 1 1 2 2 2 3 3 4
// 10
// 1 1 1 2 2 2 3 3 3 4

// Output
// Copy

// 7
// 3
// 4
// 111
// 126

// Note

// In the first test case, any non-empty subset of {1,2,3}
// can be achieved, for a total of 7

// multisets.

// In the third test case, we can generate 4

// different multisets:

//     Partition the elements into set {1,2,2}

// , resulting in multiset {2}
// .
// Partition the elements into sets {1,2},{2}
// , resulting in multiset {2,2}
// .
// Partition the elements into sets {1},{2,2}
// , resulting in multiset {1,2}
// .
// Partition the elements into sets {1},{2},{2}
// , resulting in multiset {1,2,2}

//     . 

// It can be proven that no other multisets are possible.


#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e3 + 5, P = 998244353;
 
int n;
int a[N], cnt[N];
int dp[N];
 
void solve() {
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	memset(cnt, 0, sizeof cnt);
	int max_cnt = 0;
	for (int i = 1; i <= n; ++i) {
		max_cnt = max(max_cnt, ++cnt[a[i]]);
	}
 
	memset(dp, 0, sizeof dp), dp[0] = 1;
	for (int i = 1; i <= n; ++i) if (cnt[i]) {
		for (int j = n; j >= cnt[i]; --j) {
			dp[j] = (dp[j] + 1ll * cnt[i] * dp[j - cnt[i]]) % P;
		}
	}
	
	int ans = 0;
	for (int i = max_cnt; i <= n; ++i) (ans += dp[i]) %= P;
	cout << ans << endl;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 
	int T;	
	cin >> T;
	while (T--) {
		solve();
	}
 
	return 0;
}