// B. Add 0 or K
// time limit per test
// 1.5 seconds
// memory limit per test
// 256 megabytes

// You are given an array of n
// positive integers a1,a2,…,an and a positive integer k

// .

// In one operation, you may add either 0
// or k to each ai, i.e., choose another array of n integers b1,b2,…,bn where each bi is either 0 or k, and update ai to ai+bi for 1≤i≤n. Note that you can choose different values for each element of the array b

// .

// Your task is to perform at most k
// such operations to make gcd(a1,a2,…,an)>1 ∗

// . It can be proved that this is always possible.

// Output the final array after the operations. You do not have to output the operations themselves.

// ∗
// gcd(a1,a2,…,an) denotes the greatest common divisor (GCD) of a1,a2,…,an

// .
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤1000

// ). The description of the test cases follows.

// The first line of each test case contains two integers n
// and k (1≤n≤105, 1≤k≤109) — the length of the array a

// and the given constant.

// The second line of each test case contains n
// integers a1,a2,…,an (1≤ai≤109) — the elements of the array a

// .

// It is guaranteed that the sum of n
// over all test cases does not exceed 105

// .
// Output

// For each test case, output an array of n
// integers in a new line — the final array after the operations. The integers in the output should be within the range from 1 to 109+k2

// .

// If there are multiple valid outputs, you can output any of them.

// Note that you do not have to minimize the number of operations.
// Example
// Input
// Copy

// 8
// 3 3
// 2 7 1
// 4 5
// 2 9 16 14
// 4 1
// 1 2 3 4
// 5 2
// 5 6 7 8 9
// 2 10
// 7 9
// 1 1000000000
// 1
// 1 371
// 1000000000
// 3 6
// 1 3 5

// Output
// Copy

// 8 10 10
// 7 14 21 14
// 2 2 4 4
// 9 6 9 12 9
// 77 99
// 1000000000000000001
// 1000000000
// 25 15 5

// Note

// In the first test case, the output [8,10,10]
// is valid because gcd(8,10,10)=2>1, and the array [2,7,1] can be transformed into [8,10,10] using at most 3

// operations. One possible sequence of operations is shown below:
// Operation	b
// 	Resulting a
// 1
// 	[3,0,3]
// 	[5,7,4]
// 2
// 	[0,0,3]
// 	[5,7,7]
// 3
// 	[3,3,3]
// 	[8,10,10]

// Other outputs like [2,10,4]
// , [8,16,4], and [5,10,10]

// are also considered valid.

// In the second test case, the output [7,14,21,14]

// is valid because:

//     gcd(7,14,21,14)=7>1

// .
// Starting from [2,9,16,14]
// , applying the operation with b=[5,5,5,0] yields [7,14,21,14], requiring no more than 5

//     operations. 



#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &i : a) {
      cin >> i;
    }

    for (int g = 2;; g++) {
      if (gcd(g, k) != 1)
        continue;
      for (auto &i : a) {
        while (i % g != 0)
          i += k;
      }
      for (auto i : a)
        cout << i << ' ';
      cout << '\n';
      break;
    }
  }
}