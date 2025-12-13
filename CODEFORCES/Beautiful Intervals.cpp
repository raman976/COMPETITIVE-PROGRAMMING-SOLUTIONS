// F. Beautiful Intervals
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// You are given an integer n
// and m intervals. Each interval is of the form [li,ri] and satisfies 1≤li≤ri≤n

// . Note that there can be duplicate intervals.

// Let p
// be a permutation of length n containing all the integers 0,1,2,…,n−1

// exactly once.

// There is a multiset M

// which is initially empty.

// For each interval [li,ri]

// :

//     consider the subarray p[li…ri]

// ,
// compute vi=mex
// ∗(p[li…ri])
// ,
// insert vi
// into M

//     . 

// After processing all the intervals, M
// will be equal to {v1,v2,…,vm}

// .

// Your task is to construct a permutation p
// of length n containing all the integers 0,1,2,…,n−1 exactly once such that mex(M)

// is minimized.

// ∗
// mex(a) denotes the minimum excluded (MEX) of the integers in a. For example, mex([2,2,1])=0 because 0 does not belong to the array, and mex([0,3,1,2])=4 because 0, 1, 2, and 3 appear in the array, but 4

// does not.
// Input

// The first line contains a single integer t
// (1≤t≤1000

// ) — the number of test cases. Description of each testcase follows.

// The first line contains two integers n
// and m (3≤n≤3000, 1≤m≤3000

// ).

// The next m
// lines each contain two space-separated integers li,ri (1≤li≤ri≤n

// ) each denoting an interval.

// It is guaranteed that the sum of n
// over all test cases does not exceed 3000, and the sum of m over all test cases does not exceed 3000

// .
// Output

// For each testcase, print a permutation p
// of length n containing all the integers 0,1,2,…,n−1 exactly once such that mex(M)

// is minimized.

// If there are multiple answers, you may print any one of them.
// Example
// Input
// Copy

// 5
// 3 1
// 1 2
// 3 5
// 1 1
// 1 2
// 2 2
// 2 2
// 2 3
// 4 5
// 1 2
// 2 3
// 3 4
// 1 1
// 4 4
// 5 4
// 3 5
// 1 1
// 2 4
// 4 4
// 4 2
// 1 3
// 2 4

// Output
// Copy

// 2 0 1
// 2 1 0 
// 0 2 1 3 
// 2 0 1 3 4 
// 3 1 0 2

// Note

// For the first testcase, if we choose to construct p=[2,0,1]
// , then M={mex(2,0)}={1}. Now, mex(M)=0

// .

// For the third testcase, if we choose to construct p=[0,2,1,3]
// , then M={mex(0,2),mex(2,1),mex(1,3),mex(0),mex(3)}={1,0,0,1,0}. Now, mex(M)=2

// .

// For the fourth testcase, if we choose to construct p=[2,0,1,3,4]
// , then M={mex(1,3,4),mex(2),mex(0,1,3),mex(4)}={0,0,2,0}. Now, mex(M)=1

// .

// For the fifth testcase, if we choose to construct p=[3,1,0,2]
// , then M={mex(3,1,0),mex(1,0,2)}={2,3}. Now, mex(M)=0

// .



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF (int)1e18

void Solve() 
{
    
    int n, m; cin >> n >> m;
    
    vector <int> l(m), r(m), f(n + 1), st(n + 1, 0), en(n + 1);
    for (int i = 0; i < m; i++){
        cin >> l[i] >> r[i];
        st[l[i]] = 1;
        en[r[i]] = 1;
        for (int j = l[i]; j <= r[i]; j++){
            f[j]++;
        }
    }
    
    vector <int> ans(n + 1, -1);
    
    auto fill = [&](){
        vector <bool> used(n, false);
        for (int i = 1; i <= n; i++) if (ans[i] != -1) used[ans[i]] = true;
        
        int p = 0;
        for (int i = 1; i <= n; i++){
            if (ans[i] == -1){
                while (used[p]) p++;
                
                ans[i] = p;
                used[p] = true;
            }
        }
        
        for (int i = 1; i <= n; i++){
            cout << ans[i] << " \n"[i == n];
        }
    };
    
    for (int i = 1; i <= n; i++){
        if (f[i] == m){
            int ptr = 1;
            ans[i] = 0;
            
            fill();
            return;
        }
    }
    
    for (int i = 1; i < n; i++){
        if (en[i] == 0){
            ans[i] = 0;
            ans[i + 1] = 1;
            fill();
            return;
        }
        
        if (st[i + 1] == 0){
            ans[i] = 1;
            ans[i + 1] = 0;
            fill();
            return;
        }
    }
    
    assert(n >= 3);
    ans[1] = 0;
    ans[2] = 2;
    ans[3] = 1;
    
    fill();
}

int32_t main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        Solve();
    }
    
    return 0;
}