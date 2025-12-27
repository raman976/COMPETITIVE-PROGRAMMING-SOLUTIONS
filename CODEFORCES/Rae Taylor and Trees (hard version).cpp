// F. Rae Taylor and Trees (hard version)
// time limit per test
// 3 seconds
// memory limit per test
// 256 megabytes
// "To think a commoner would even fathom sitting next to me. Know your place!"
// — Claire François

// This is the hard version of the problem. The only difference between the easy and hard versions is that the hard version asks you to construct an example of a satisfactory tree.

// As an Earth mage, Rae has mastered the spell of growing trees! But Manaria brags that she can grow a more impressive species of trees. Rae remembers that the most rare type of tree can be grown using a formula represented by a certain permutation — please help her construct it!

// You are given a permutation∗
// p of length n

// .

// Determine if there exists an undirected tree with n
// vertices labeled 1,2,…,n

// , satisfying the following condition:

//     Let u

// and v (1≤u<v≤n) be any two vertices connected by an edge. Then u appears before v in p

//     . 

// Additionally, if there exists such a tree, output any of them.

// ∗
// A permutation of length n is an array that contains every integer from 1 to n

// exactly once, in any order.
// Input

// The first line contains a single integer t
// (1≤t≤104

// )  — the number of test cases.

// The first line of each test case contains a single integer n
// (2≤n≤2⋅105

// ).

// The second line of each test case contains n
// integers, p1,p2,…,pn (1≤pi≤n). It is guaranteed that all pi

// are distinct.

// It is guaranteed that the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output on a single line "Yes" if there exists a tree satisfying the given condition, and "No" otherwise.

// Then, if the answer is "Yes", output n−1
// lines. The i-th of these lines should contain two integers u and v, denoting an edge connecting vertices u and v

// .

// You may output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "YES", and "yeS" will be recognized as "Yes".
// Example
// Input
// Copy

// 9
// 6
// 1 3 4 5 2 6
// 4
// 3 4 1 2
// 5
// 4 3 5 1 2
// 4
// 1 2 3 4
// 7
// 4 3 5 7 6 2 1
// 6
// 2 4 6 1 3 5
// 3
// 2 1 3
// 4
// 2 4 1 3
// 6
// 4 2 6 5 1 3

// Output
// Copy

// Yes
// 3 1
// 4 1
// 6 5
// 6 2
// 6 1
// No
// No
// Yes
// 2 1
// 4 3
// 4 1
// No
// Yes
// 4 2
// 6 2
// 3 1
// 5 1
// 5 2
// Yes
// 3 2
// 3 1
// Yes
// 4 2
// 3 1
// 3 2
// Yes
// 6 4
// 6 2
// 3 1
// 5 4
// 2 3

// Note

// In the first example, we can construct the tree given in the sample output. We have that

//     1<3

// , and 1 appears before 3 in p
// ,
// 1<4
// , and 1 appears before 4 in p
// ,
// 5<6
// , and 5 appears before 6 in p
// ,
// 2<6
// , and 2 appears before 6 in p
// ,
// 1<6
// , and 1 appears before 6 in p

//     . 

// In the second example, it can be shown that there does not exist a tree satisfying the given constraints.






#include <bits/stdc++.h>
using namespace std;
 
void solve(){
    int n;
    cin >> n;
    vector<int> p(n+1), pre(n+1, n);
    vector<pair<int, int>> suf(n+2);
    for(int i=1; i<=n; i++){
        cin >> p[i];
        pre[i] = min(pre[i-1], p[i]);
    }
    for(int i=n; i>=1; i--)
        suf[i] = max(suf[i+1], {p[i], i});
    for(int i=2; i<=n; i++)
        if(pre[i-1] > suf[i].first){
            cout << "No" << '\n';
            return;
        }
    cout << "Yes" << '\n';
    for(int l=1; l<=n;){
        int r = suf[l].second;
        for(int i=l; i<r; i++)
            cout << p[i] << ' ' << p[r] << '\n';
        if(l > 1)
            cout << pre[l-1] << ' ' << p[r] << '\n';
        l = r+1;
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
}