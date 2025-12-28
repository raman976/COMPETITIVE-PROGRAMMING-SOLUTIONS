// B. Addition on a Segment
// time limit per test
// 2 seconds
// memory limit per test
// 512 megabytes

// You start with an integer array a
// , which initially consists of n zeros. You have to perform the following action exactly n

// times:

//     choose two integers l

// and r (1≤l≤r≤n) and assign ai=ai+1 for each i such that l≤i≤r

//     . 

// You are given an array b
// , consisting of n integers. Your task is to choose such values l and r

// for each action that:

//     after all n

// actions are performed, it's possible to reorder the elements in such a way that a becomes equal to b
// ;
// the maximum value of r−l+1

//     over all actions is as large as possible. 

// What's the maximum possible value of r−l+1

// ?
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The first line of each test case contains one integer n
// (1≤n≤2⋅105) — the length of the array b

// .

// The second line of each test case contains n
// integers bi (0≤bi≤n) — the elements of the array b

// .

// Additional constraints on the input:

//     there exists at least one way to choose l

// and r for each action and reorder the elements at the end so that a becomes equal to b
// ;
// the sum of n
// over all test cases does not exceed 2⋅105

//     . 

// Output

// For each test case, output one integer — the answer to the problem.
// Example
// Input
// Copy

// 3
// 5
// 0 5 1 0 1
// 3
// 3 2 1
// 5
// 1 1 1 1 1

// Output
// Copy

// 3
// 3
// 1

// Note

// Consider the first test case. If the n

// actions were as follows:

//     l=3

// and r=3
// l=1
// and r=3
// l=3
// and r=3
// l=3
// and r=3
// l=3
// and r=3

// The array a=[1,1,5,0,0]
// , so you can reorder the elements to make it equal to [0,5,1,0,1]. As can be seen in this case, the maximum value of r−l+1 is 3

// . It can be shown that this is the optimal answer.

// In the second test case:

//     l=1

// and r=3
// l=2
// and r=3
// l=3
// and r=3

// The answer is 3
// .




#include<bits/stdc++.h>
using namespace std;
 
#define int long long
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
 
    int sum = 0;
    int cnt_one = 0;
 
    for (int i = 0; i < n; i++){
        if (a[i] > 0){
            cnt_one++;
        }
        sum += a[i];
    }
 
    int sum2 = sum - cnt_one;
    int sub = n - 1 - sum2;
 
    cout << cnt_one - max(0ll, sub) << '\n';
}
 
signed main()
{
#ifdef FELIX
    auto _clock_start = chrono::high_resolution_clock::now();
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
 
#ifdef FELIX
    cerr << "Executed in " << chrono::duration_cast<chrono::milliseconds>(
        chrono::high_resolution_clock::now()
            - _clock_start).count() << "ms." << endl;
#endif
    return 0;
}