// C. Range Operation
// time limit per test
// 2 seconds
// memory limit per test
// 512 megabytes

// You are given an integer array a
// of length n

// .

// You can perform the following operation: choose a range [l,r]
// (1≤l≤r≤n) and replace the value of elements al,al+1,…,ar with (l+r)

// .

// Your task is to calculate the maximum possible total array sum if you can perform the aforementioned operation at most once.
// Input

// The first line contains a single integer t
// (1≤t≤104

// ) — the number of test cases.

// The first line of each test case contains a single integer n
// (1≤n≤2⋅105

// ).

// The second line contains n
// integers a1,a2,…,an (0≤ai≤2n

// ).

// Additional constraint on the input: the sum of n
// over all test cases doesn't exceed 2⋅105

// .
// Output

// For each test case, print a single integer — the maximum possible total array sum if you can perform the aforementioned operation at most once.
// Example
// Input
// Copy

// 4
// 3
// 2 5 1
// 2
// 4 4
// 4
// 1 3 2 1
// 5
// 3 2 0 9 10

// Output
// Copy

// 13
// 8
// 20
// 32

// Note

// In the first example, you can perform the operation on the subarray [3,3]
// , resulting in the array [2,5,6] and the sum 13

// .

// In the second example, you don't need to perform any operation.

// In the third example, you can perform the operation on the subarray [1,4]
// , resulting in the array [5,5,5,5] and the sum 20

// .

// In the fourth example, you can perform the operation on the subarray [2,3]
// , resulting in the array [3,5,5,9,10] and the sum 32

// .



#include <bits/stdc++.h>
 
using namespace std;
 
using li = long long;
 
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    li s = 0, mn = 0, bst = 0;
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      s += x;
      li cur = (i + 1) * li(i + 2) - s;
      mn = min(mn, cur);
      bst = max(bst, cur - mn);
    }
    cout << s + bst << '\n';
  }
}