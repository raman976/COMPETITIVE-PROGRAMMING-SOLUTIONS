// D. Not Alone
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// A circular array b
// of length m is nice if every element has at least one adjacent element∗ that is equal to it. Formally, for every 1≤i≤m, at least one of the following holds: bi=b(i+m−2)modm+1, or bi=bimodm+1, where xmody denotes the remainder from dividing x by y

// .

// You are given a circular array a
// of length n. In one operation, you may increase or decrease any element of a by 1. Your task is to determine the minimum number of operations required to make array a nice. More formally, find the minimum value of ∑ni=1|bi−ai| among all nice circular arrays b of length n

// .

// ∗
// In a circular array of length m

// :

//     For each index 2≤i≤m−1

// , the element at index i is adjacent to the elements at indices i−1 and i+1
// .
// The element at index 1
// is adjacent to the elements at indices 2 and m
// .
// The element at index m
// is adjacent to the elements at indices m−1 and 1

//     . 

// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
// (3≤n≤2⋅105) — the length of the circular array a

// .

// The second line of each test case contains n
// integers a1,a2,…,an (1≤ai≤109) — the elements of the circular array a

// .

// It is guaranteed that the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output a single integer representing the minimum number of operations required to make array a

// nice.
// Example
// Input
// Copy

// 4
// 5
// 1 1 1 1 1
// 4
// 2 100 99 3
// 5
// 2 2 5 9 5
// 6
// 1 1 1 2 1 2

// Output
// Copy

// 0
// 2
// 4
// 1

// Note

// In the first test case, all elements of a
// are equal. Therefore, the circular array a

// is already nice and no operations are required.

// In the second test case, we can perform the following sequence of operations:

//     Increase a1

// by 1. Now, a=[3,100,99,3]
// .
// Decrease a2
// by 1. Now, a=[3,99,99,3]

//     . 

// After these operations, every element has at least one adjacent element with the same value:

//     a1

// is equal to a4
// .
// a2
// is equal to a3
// .
// a3
// is equal to a2
// .
// a4
// is equal to a1

//     . 

// In the third test case, the circular array a
// can become nice by decreasing a4 four times. This results in a=[2,2,5,5,5] which is nice as every element has at least one adjacent element with the same value.




#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const ll LINF = 1000000000000000005;
const int MAXN = 500005;
 
int t;
int n;
int a[MAXN];
ll dp[MAXN];
 
ll cost(int x, int y) { return abs(x - y); }
 
ll cost(int x, int y, int z) {
    if (x > y) {
        swap(x, y);
    }
    if (y > z) {
        swap(y, z);
    }
    if (x > y) {
        swap(x, y);
    }
    return z - x;
}
 
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
 
        ll ans = LINF;
        for (int cyc = 0; cyc < 4; cyc++) {
            dp[0] = 0;
            dp[1] = LINF;
            for (int i = 2; i <= n; i++) {
                dp[i] = dp[i - 2] + cost(a[i - 1], a[i]);
                if (i >= 3) {
                    dp[i] =
                        min(dp[i], dp[i - 3] + cost(a[i - 2], a[i - 1], a[i]));
                }
            }
            ans = min(ans, dp[n]);
 
            // cyclic shift anti-clockwise
            for (int i = 2; i <= n; i++) {
                swap(a[i], a[i - 1]);
            }
        }
 
        cout << ans << '\n';
    }
    return 0;
}