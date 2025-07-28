// A. Blackboard Game
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes

// Initially, the integers from 0
// to n−1

// are written on a blackboard.

// In one round,

//     Alice chooses an integer a

// on the blackboard and erases it;
// then Bob chooses an integer b
// on the blackboard such that a+b≡3(mod4)∗

//     and erases it. 

// Rounds take place in succession until a player is unable to make a move — the first player who is unable to make a move loses. Determine who wins with optimal play.

// ∗
// We define that x≡y(modm) whenever x−y is an integer multiple of m

// .
// Input

// The first line contains an integer t
// (1≤t≤100

// )  — the number of test cases.

// The only line of each test case contains an integer n
// (1≤n≤100

// ) — the number of integers written on the blackboard.
// Output

// For each test case, output on a single line "Alice" if Alice wins with optimal play, and "Bob" if Bob wins with optimal play.

// You can output the answer in any case (upper or lower). For example, the strings "aLiCe", "alice", "ALICE", and "alICE" will be recognized as "Alice".
// Example
// Input
// Copy

// 5
// 2
// 4
// 5
// 7
// 100

// Output
// Copy

// Alice
// Bob
// Alice
// Alice
// Bob

// Note

// In the first sample, suppose Alice chooses 0

// , then Bob cannot choose any number so Alice wins immediately.

// In the second sample, suppose Alice chooses 0
// , then Bob can choose 3. Then suppose Alice chooses 2, then Bob can choose 1

// . Then Alice has no numbers remaining, so Bob wins.



#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> cnt(4);
    for(int i=0; i<n; i++)
        cnt[i % 4]++;
    cout << (cnt[0] == cnt[3] && cnt[1] == cnt[2] ? "Bob" : "Alice") << '\n';
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}