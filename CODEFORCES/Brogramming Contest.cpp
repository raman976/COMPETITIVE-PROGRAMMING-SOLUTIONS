// A. Brogramming Contest
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes

// One day after waking up, your friend challenged you to a brogramming contest. In a brogramming contest, you are given a binary string∗
// s of length n and an initially empty binary string t

// . During a brogramming contest, you can make either of the following moves any number of times:

//     remove some suffix†

// from s and place it at the end of t
// , or
// remove some suffix from t
// and place it at the end of s

//     . 

// To win the brogramming contest, you must make the minimum number of moves required to make s contain only the character 0 and t contain only the character 1. Find the minimum number of moves required.

// ∗
// A binary string is a string consisting of characters 0 and 1

// .

// †
// A string a is a suffix of a string b if a can be obtained from deletion of several (possibly, zero or all) elements from the beginning of b

// .
// Input

// The first line contains an integer t
// (1≤t≤100

// ) — the number of test cases.

// The first line of each test case is an integer n
// (1≤n≤1000) — the length of the string s

// .

// The second line of each test case contains the binary string s

// .

// The sum of n
// across all test cases does not exceed 1000

// .
// Output

// For each testcase, output the minimum number of moves required.
// Example
// Input
// Copy

// 5
// 5
// 00110
// 4
// 1111
// 3
// 001
// 5
// 00000
// 3
// 101

// Output
// Copy

// 2
// 1
// 1
// 0
// 3

// Note

// An optimal solution to the first test case is as follows:

//     s=00110

// , t=
// empty string.
// s=00
// , t=110
// .
// s=000
// , t=11

//     . 

// It can be proven that there is no solution using less than 2

// moves.

// In the second test case, you have to move the whole string from s
// to t

// in one move.

// In the fourth test case, you don't have to do any moves.





#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for(auto x: a) cout << x << " "; cout << "\n";
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int a, int b) { return uniform_int_distribution<int>(a, b)(rng); }
ll uld(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }

void solve(){
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] != s[i + 1]) ans++;
    }

    if (s[0] == '1') ans++;
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) solve();
}