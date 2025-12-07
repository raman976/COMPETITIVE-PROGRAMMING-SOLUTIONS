// E. Anisphia Wynn Palettia and Good Permutations
// time limit per test
// 3 seconds
// memory limit per test
// 256 megabytes
// I've always loved the word magic. It has a way of making people happy, of putting a smile on their faces.
// — Anisphia Wynn Palettia

// Anis and her new assistant Euphie are improving the Witch's Broom! Magicology requires great precision and care — in order to fly, the construction of the broom must have sufficiently few imperfections.

// For an arbitrary array a
// of length m, call an index i (1≤i≤m−2) bad if ai, ai+1, and ai+2 are all pairwise coprime. More formally, i is a bad index if and only if gcd(ai,ai+1)=gcd(ai,ai+2)=gcd(ai+1,ai+2)=1∗. Furthermore, call a good if it has at most 6

// bad indices.

// You are given an integer n
// . Construct a good permutation† p of length n

// . It can be shown that such a permutation always exists.

// Note that you do not have to minimize the number of bad indices.

// ∗
// gcd(x,y) denotes the greatest common divisor of x and y

// †
// A permutation of length n is an array that contains every integer from 1 to n

// exactly once, in any order.
// Input

// The first line contains a single integer t
// (1≤t≤104

// )  — the number of test cases.

// The only line of each test case contains a single integer n
// (3≤n≤2⋅105

// ).

// It is guaranteed that the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output on a single line n
// integers p1,p2,…,pn, an example of a good permutation of length n

// . If there are multiple good permutations, you may output any of them.
// Example
// Input
// Copy

// 4
// 3
// 6
// 8
// 9

// Output
// Copy

// 2 1 3
// 4 1 6 3 5 2
// 4 1 6 3 5 2 8 7
// 5 4 8 1 9 3 6 2 7

// Note

// For n=9

// , we have
// i
// 	pi
// 	pi+1
// 	pi+2
// 	gcd(pi,pi+1)
// 	gcd(pi,pi+2)
// 	gcd(pi+1,pi+2)
// 1
// 	5
// 	4
// 	8
// 	1
// 	1
// 	4
// 2
// 	4
// 	8
// 	1
// 	4
// 	1
// 	1
// 3
// 	8
// 	1
// 	9
// 	1
// 	1
// 	1
// 4
// 	1
// 	9
// 	3
// 	1
// 	1
// 	3
// 5
// 	9
// 	3
// 	6
// 	3
// 	3
// 	3
// 6
// 	3
// 	6
// 	2
// 	3
// 	1
// 	2
// 7
// 	6
// 	2
// 	7
// 	2
// 	1
// 	1

// The only bad index is 3
// . Since 1≤6, p is a good permutation.



#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<vector<int>> a(3);
    for(int i=1; i<=n; i++)
        if(!(i % 2))
            a[0].push_back(i);
        else if(!(i % 3))
            a[1].push_back(i);
        else
            a[2].push_back(i);
    while(a[2].size() >= 1 && a[0].size() >= 2){
        cout << a[2].back() << ' ';
        a[2].pop_back();
        cout << a[0].back() << ' ';
        a[0].pop_back();
        cout << a[0].back() << ' ';
        a[0].pop_back();
    }
    while(a[2].size() >= 1 && a[1].size() >= 2){
        cout << a[2].back() << ' ';
        a[2].pop_back();
        cout << a[1].back() << ' ';
        a[1].pop_back();
        cout << a[1].back() << ' ';
        a[1].pop_back();
    }
    for(int i : a[0])
        cout << i << ' ';
    for(int i : a[1])
        cout << i << ' ';
    for(int i : a[2])
        cout << i << ' ';
    cout << '\n';
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}