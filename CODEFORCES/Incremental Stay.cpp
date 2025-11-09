// C. Incremental Stay
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes
// Danimal Cannon, Zef - The Lunar Whale
// ⠀

// You are the security guard of a museum.

// The main door of the museum is both an entrance and an exit. At most one person can pass through the door every second. There is a sensor that detects when a visitor passes through the door. The sensor cannot determine neither who the visitor is, nor whether he entered or exited the museum. The sensor detected some activity in 2n
// distinct moments of time a1,a2,…,a2n

// (measured in seconds).

// For each visitor, his stay time is equal to the exit time minus the entrance time.

// Right now the museum is closed (so it has no visitors), and you wonder about the maximum possible total stay time today, i.e., the maximum possible sum of the stay times of all the visitors that entered the museum today. At second 0

// , the museum was closed as well.

// For security reasons, there is also a limit on the number of people who can stay in the museum simultaneously, but you forgot this limit. For each k
// from 1 to n, you want to determine the maximum possible total stay time today, assuming that at most k

// people can stay in the museum simultaneously.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
// (1≤n≤2⋅105), indicating that the sensor detected some activity in 2n

// distinct moments of time.

// The second line of each test case contains 2n
// integers a1,a2,…,a2n (1≤a1<a2<…<a2n≤109

// ) — the seconds when the sensor detected some activity.

// It is guaranteed that the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, print n
// integers: for each k from 1 to n, print the maximum possible total stay time today, assuming that at most k

// people can stay in the museum simultaneously.
// Example
// Input
// Copy

// 3
// 1
// 32 78
// 2
// 4 5 6 9
// 4
// 6149048 26582657 36124499 43993239 813829899 860114890 910238130 913669539

// Output
// Copy

// 46 
// 4 6 
// 78018749 1737022233 1845329695 3385003015 

// Note

// In the first test case, the sensor detected activity at seconds 32
// and 78. Recall that k

// is the maximum number of people who can stay in the museum simultaneously.

//     If k

// is 1, the maximum possible total stay time is 46, reached if visitor 1 enters at time 32 and exits at time 78

//     . 

// In the second test case, the sensor detected activity at seconds 4
// , 5, 6, and 9

// .

//     If k

// is 1, the maximum possible total stay time is 4, reached if visitor 1 enters at time 4 and exits at time 5, and visitor 2 enters at time 6 and exits at time 9
// .
// If k
// is 2, the maximum possible total stay time is 6, reached if visitor 1 enters at time 4 and exits at time 9, and visitor 2 enters at time 5 and exits at time 6. 





#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> v;
        for (ll i = 0; i < 2 * n; i++) {
            ll x; cin >> x; v.pb(x);
        }

        vector<ll> ans(n + 3, 0);
        for (ll i = 0; i < 2 * n; i += 2) ans[1] -= v[i];
        for (ll i = 1; i < 2 * n; i += 2) {
            ans[1] += v[i]; ans[2] -= v[i];
        }
        for (ll i = 2; i < 2 * n; i += 2) ans[2] += v[i];
        ans[2] += 2 * v.back() - v[0];

        for (ll i = 3; i <= n; i++) {
            ans[i] = ans[i - 2] + 2 * (v[(ll)v.size() - i + 1] - v[i - 2]);
        }

        for (ll i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << nl;
    }

    return 0;
}