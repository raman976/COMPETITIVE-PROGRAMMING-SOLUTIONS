// E. Best Time to Buy and Sell Stock
// time limit per test
// 4 seconds
// memory limit per test
// 256 megabytes

// The beauty of an array b
// of length m (with m≥2) is defined as the largest value of bj−bi over all pairs of indices i and j such that 1≤i<j≤m. More formally, it is equal to max1≤i<j≤m(bj−bi)

// . Note that the beauty might be negative if the array is strictly decreasing.

// Hao and Alex play a turn-based game on an array a
// of length n

// . Initially, all elements of the array are unlocked. The players take turns alternately, with Hao going first.

//     On Hao's turn, he selects one unlocked element from array a

// and removes it.
// On Alex's turn, he selects one unlocked element from array a

//     and locks it (so it can no longer be removed by Hao). 

// The game continues until all elements of a
// are either locked or removed. It can be proven that the game lasts exactly n turns, and exactly ⌊n2⌋ elements will remain locked in array a

// at the end.

// Hao wants to minimize the beauty of the final array of locked elements, while Alex wants to maximize it. Determine the beauty of the final array if both players play optimally.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
// (4≤n≤105) — the size of the array a

// .

// The second line contains n
// integers a1,a2,…,an (1≤ai≤109) — the elements of the array a

// .

// It is guaranteed that the sum of n
// over all test cases does not exceed 105

// .
// Output

// For each test case, output a single integer representing the beauty of the final array if both Hao and Alex play optimally.
// Example
// Input
// Copy

// 6
// 5
// 5 1 2 3 4
// 4
// 3 1 2 1
// 10
// 7 1 3 5 8 2 8 3 5 1
// 6
// 1 1 4 5 1 4
// 9
// 9 9 8 2 4 4 3 5 3
// 4
// 1000000000 1 2 3

// Output
// Copy

// 1
// -2
// 5
// 3
// 1
// -999999998

// Note

// In the first test case, the game may proceed as follows. Bolded elements are locked by Alex:

//     Turn 1 (Hao): Remove element 1

// (at position 2), resulting in [5,2,3,4]
// .
// Turn 2 (Alex): Lock element 3
// (at position 3), resulting in [5,2,3,4]
// .
// Turn 3 (Hao): Remove element 2
// (at position 2), resulting in [5,3,4]
// .
// Turn 4 (Alex): Lock element 4
// (at position 3), resulting in [5,3,4]
// .
// Turn 5 (Hao): Remove element 5
// (at position 1), resulting in [3,4]

//     . 

// The beauty of the final array b=[3,4]
// is equal to b2−b1=4−3=1

// .

// In the second test case, note that the answer might be negative:

//     Turn 1 (Hao): Remove element 2

// (at position 3), resulting in [3,1,1]
// .
// Turn 2 (Alex): Lock element 1
// (at position 2), resulting in [3,1,1]
// .
// Turn 3 (Hao): Remove element 1
// (at position 3), resulting in [3,1]
// .
// Turn 4 (Alex): Lock element 3
// (at position 1), resulting in [3,1]

//     . 

// The beauty of the final array b=[3,1]
// is equal to b2−b1=1−3=−2

// .

// In the third test case, one possible final array (assuming optimal play by both players) is b=[3,5,8,5,1]
// . The beauty, which is the largest difference bj−bi over all pairs of indices i and j such that 1≤i<j≤5, is equal to b3−b1=8−3=5.





#include "bits/stdc++.h"
using namespace std;
 
const int MAXN = 200005;
const int INF = 1000000005;
 
inline int fdiv(int num, int denom) {
  return num / denom - ((num ^ denom) < 0 && num % denom);
}
inline int cdiv(int num, int denom) { return fdiv(num + denom - 1, denom); }
 
int t;
int n;
int a[MAXN];
 
vector<int> adj[MAXN];
void add_edge(int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
bool check(int x) {
  for (int i = 1; i <= n; i++) {
    adj[i].clear();
  }
  set<pair<int, int>> st;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (auto [prv, prv_id] : st) {
      if (a[i] - prv >= x) {
        add_edge(prv_id, i);
      }
    }
    st.insert({a[i], i});
    if ((int) st.size() > 3) {
        st.erase(prev(st.end()));
    }
  }
 
  int bad_cnt = 0;
  for (int i = 1; i <= n; i++) {
    if ((int)adj[i].size() >= 2) {
      bad_cnt++;
    }
  }
  for (int i = 1; i <= n; i++) {
    int delta = (int)adj[i].size() >= 2;
    for (int v : adj[i]) {
      if (adj[v].size() == 2) {
        delta++;
      }
    }
    if (delta == bad_cnt) {
      return false;
    }
  }
  return true;
}
 
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int lo = -INF, hi = INF;
    while (lo < hi) {
      int mid = cdiv(lo + hi, 2);
      if (check(mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    cout << lo << '\n';
  }
  return 0;
}