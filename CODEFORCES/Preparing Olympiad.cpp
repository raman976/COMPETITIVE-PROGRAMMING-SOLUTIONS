#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define srt(x) x.begin(), x.end()
#define rsrt(x) x.rbegin(),x.rend()
typedef vector<int> vi;
typedef pair<int, int> pii;

// DEBUGGING (ignore for online judges)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(T t) {cerr << t;}
#else
#define debug(x)
#endif
vector<vector<int>> allSubsequences; 

void generateSubsequences(vector<int>& nums, vector<int>& current, int index) {
    if (index == nums.size()) {
        if (!current.empty()) allSubsequences.push_back(current); 
        return;
    }
    current.push_back(nums[index]);
    generateSubsequences(nums, current, index + 1);
    current.pop_back();
    generateSubsequences(nums, current, index + 1);
}

void solve() {
  int n,l,r,x;
  cin >> n >> l >> r >> x;
  vector<int>prob(n);
  for(int i=0;i<n;i++){
    cin >> prob[i];
  }
  vector<int> current;
  generateSubsequences(prob, current, 0);
  int count = 0;
  for (auto& subset : allSubsequences) {
      if (subset.size() < 2) continue;
      int sum = 0, mn = INT_MAX, mx = INT_MIN;
      for (int val : subset) {
          sum += val;
          mn = min(mn, val);
          mx = max(mx, val);
      }
      if (sum >= l && sum <= r && (mx - mn >= x)) {
          count++;
      }
  }
  cout << count << "\n";
}

int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

   solve();

    return 0;
}