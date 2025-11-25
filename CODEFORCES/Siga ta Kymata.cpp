// B. Siga ta Kymata
// time limit per test
// 1.5 seconds
// memory limit per test
// 256 megabytes

// You are given a permutation∗
// p of every integer from 1 to n. You also own a binary† string s of size n where si=0 for all 1≤i≤n. You may do the following operation at most 5

// times:

//     Choose any two integers l

// and r such that 1≤l≤r≤n. Then, for every i such that l<i<r and min(pl,pr)<pi<max(pl,pr) hold at the same time, you will set si to 1

//     . 

// You are also given a binary string x
// of size n. After performing operations, it must hold for every 1≤i≤n that if xi=1, then si=1. Note that if xi=0, then si

// can have any value.

// Figure out any sequence of at most 5

// operations such that the aforementioned condition is satisfied, or report that it is impossible to do so. Note that you do not have to minimize the number of operations you make.

// ∗
// A permutation p of every integer from 1 to n is a sequence of elements from 1 to n

// such that every element appears exactly once.

// †
// A string b of size m is considered binary if and only if bi=0 or bi=1 for all 1≤i≤m

// .
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
// (3≤n≤2⋅105

// ) — the size of the array.

// The second line contains exactly n
// integers p1,p2,…,pn (1≤pi≤n, the elements of p are pairwise distinct) — where pi is the i

// -th element of the permutation.

// The third line contains a single binary string x
// of size n

// .

// It is guaranteed that the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, if it is impossible to perform operations such that the constraint is satisfied, output −1

// .

// Otherwise, output an integer 0≤k≤5
// , the number of operations. On the i-th of the next k lines, output two integers 1≤li≤ri≤n, the bounds of the i

// -th operation that is performed. If there are multiple correct solutions, output any of them.
// Example
// Input
// Copy

// 6
// 3
// 1 2 3
// 010
// 5
// 3 4 2 1 5
// 11111
// 6
// 1 3 2 4 6 5
// 001100
// 6
// 6 2 3 4 5 1
// 110110
// 5
// 2 1 4 3 5
// 00000
// 5
// 2 5 3 1 4
// 00100

// Output
// Copy

// 1
// 1 3
// -1
// 2
// 1 5
// 2 6
// -1
// 0
// 1
// 2 4

// Note

// In the first example, p=[1,2,3]
// , and x=010. We can perform a single operation, with l=1 and r=3. After the operation, we set s2 to 1 since l<2<r and min(pl,pr)<p2=2<max(pl,pr) hold at the same time. As a result, s=010

// .

// In the second example, it can be shown that there does not exist a correct sequence of at most 5
// operations, so we output −1

// .

// In the third example, p=[1,3,2,4,6,5]
// and x=001100. After performing an operation for l=1 and r=5, then s=011100. If we also perform an operation for l=2 and r=6, then s will remain the same. The string s=011100 is valid, because for every position where x has a 1, then s also has a 1 at that position.




#include <bits/stdc++.h>
using namespace std;
 
void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    int mn = 1, mx = 1;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] < a[mn]) mn = i;
        if (a[i] > a[mx]) mx = i;
    }
    string t; cin >> t;
    t = " " + t;
    if (t[1] == '1' || t[n] == '1') {
        cout << -1 << "\n";
        return;
    }
    if (t[mn] == '1' || t[mx] == '1') {
        cout << -1 << "\n";
        return;
    }
    cout << 5 << "\n";
    cout << 1 << " " << mn << "\n";
    cout << 1 << " " << mx << "\n";
    cout << mn << " " << n << "\n";
    cout << mx << " " << n << "\n";
    cout << min(mn, mx) << " " << max(mn, mx) << "\n";
}
 
int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}