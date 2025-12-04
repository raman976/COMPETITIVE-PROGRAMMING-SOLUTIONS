// A. Against the Difference
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// We define that a block is an array where all elements in it are equal to the length of the array. For example, [3,3,3]
// , [1], and [4,4,4,4] are blocks, while [1,1,1] and [2,3,3]

// are not.

// An array is called neat if it can be obtained by the concatenation of an arbitrary number of blocks (possibly zero). Note that an empty array is always neat.

// You are given an array a
// consisting of n integers. Find the length of its longest neat subsequence∗

// .

// ∗
// A sequence c is a subsequence of a sequence a if c can be obtained from a

// by the deletion of several (possibly, zero or all) element from arbitrary positions.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The first line of each test case contains an integer n
// (1≤n≤2⋅105) — the length of a

// .

// The second line contains n
// integers a1,a2,…,an (1≤ai≤n) — the elements of a

// .

// It is guaranteed that the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output a single integer — the length of the longest neat subsequence of a

// .
// Example
// Input
// Copy

// 6
// 1
// 1
// 2
// 2 2
// 4
// 2 2 1 1
// 6
// 1 2 3 3 3 1
// 8
// 8 8 8 8 8 8 8 7
// 10
// 2 3 3 1 2 3 5 1 1 7

// Output
// Copy

// 1
// 2
// 4
// 5
// 0
// 5

// Note

// In the first test case, the whole array [1]

// is neat because it is a block.

// In the second test case, the whole array [2,2]

// is neat because it is a block.

// In the third test case, the whole array [2,2,1,1]
// is neat because it is the concatenation of three blocks: [2,2], [1], and [1]

// .

// In the fourth test case, one of the longest neat subsequences of a
// is [1,3,3,3,1]

// .

// In the fifth test case, the longest neat subsequence of a

// is the empty subsequence.




#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 10;

int T, n, a[MAXN], dp[MAXN]; deque<int> q[MAXN];

int main() {
	for (scanf("%d", &T); T--; ) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) q[i].clear();
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++) {
			dp[i] = dp[i - 1], q[a[i]].emplace_back(i);
			if (q[a[i]].size() > a[i]) q[a[i]].pop_front();
			if (q[a[i]].size() == a[i]) dp[i] = max(dp[i], dp[q[a[i]].front() - 1] + a[i]);
		}
		printf("%d\n", dp[n]);
	}
}