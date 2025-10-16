// B. Not Quite a Palindromic String
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// Vlad found a binary string∗
// s of even length n. He considers a pair of indices (i,n−i+1), where 1≤i<n−i+1, to be good if si=sn−i+1

// holds true.

// For example, in the string '010001' there is only 1
// good pair, since s1≠s6, s2≠s5, and s3=s4

// . In the string '0101' there are no good pairs.

// Vlad loves palindromes, but not too much, so he wants to rearrange some characters of the string so that there are exactly k

// good pairs of indices.

// Determine whether it is possible to rearrange the characters in the given string so that there are exactly k
// good pairs of indices (i,n−i+1

// ).

// ∗
// A string s

// is called binary if it consists only of the characters '0' and '1'
// Input

// The first line contains an integer t
// (1≤t≤104

// ) — the number of test cases.

// The first line of each test case contains two integers n
// and k (2≤n≤2⋅105, 0≤k≤n2, n

// is even) — the length of the string and the required number of good pairs.

// The second line of each test case contains a binary string s
// of length n

// .

// It is guaranteed that the sum of n
// across all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output "YES" if there is a way to rearrange the characters of the string so that there are exactly k

// good pairs, otherwise output "NO".

// You may output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.
// Example
// Input
// Copy

// 6
// 6 2
// 000000
// 2 1
// 01
// 4 1
// 1011
// 10 2
// 1101011001
// 10 1
// 1101011001
// 2 1
// 11

// Output
// Copy

// NO
// NO
// YES
// NO
// YES
// YES




#include <bits/stdc++.h>

#define int long long
#define pb emplace_back
#define mp make_pair
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

typedef long double ld;
typedef long long ll;

using namespace std;

mt19937 rnd(time(nullptr));

const int inf = 1e9;
const int M = 1e9 + 7;
const ld pi = atan2(0, -1);
const ld eps = 1e-6;

void solve(int tc){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(2);
    for(char c: s){
        cnt[c - '0']++;
    }
    int mn = max(cnt[0], cnt[1]) - n / 2;
    int mx = cnt[0] / 2 + cnt[1] / 2;
    if(k >= mn && (k - mn) % 2 == 0 && k <= mx) cout << "YES";
    else cout << "NO";
}

bool multi = true;

signed main() {
    int t = 1;
    if (multi)cin >> t;
    for (int i = 1; i <= t; ++i) {
        solve(i);
        cout << "\n";
    }
    return 0;
}