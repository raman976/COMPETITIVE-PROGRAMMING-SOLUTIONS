// A. Max and Mod
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes

// You are given an integer n
// . Find any permutation p of length n∗

// such that:

//     For all 2≤i≤n

// , max(pi−1,pi)modi † =i−1

//     is satisfied. 

// If it is impossible to find such a permutation p
// , output −1

// .

// ∗
// A permutation of length n is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array), and [1,3,4] is also not a permutation (n=3 but there is 4

// in the array).

// †
// xmody denotes the remainder from dividing x by y

// .
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤99

// ). The description of the test cases follows.

// The first line of each test case contains a single integer n
// (2≤n≤100

// ).
// Output

// For each test case:

//     If such a permutation p

// doesn't exist, output a single integer −1
// .
// Otherwise, output n
// integers p1,p2,…,pn — the permutation p

//     you've found. If there are multiple answers, output any of them. 

// Example
// Input
// Copy

// 4
// 2
// 3
// 4
// 5

// Output
// Copy

// -1
// 3 2 1
// -1
// 1 5 2 3 4

// Note

// In the first test case, it is impossible to find such a permutation p
// , so you should output −1

// .

// In the fourth test case, p=[1,5,2,3,4]

// satisfies the condition:

//     For i=2

// , max(p1,p2)=5 and 5mod2=1
// .
// For i=3
// , max(p2,p3)=5 and 5mod3=2
// .
// For i=4
// , max(p3,p4)=3 and 3mod4=3
// .
// For i=5
// , max(p4,p5)=4 and 4mod5=4

//     . 

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, n;
	cin >> T;
	while (T--) {
		cin >> n;
		if (n & 1) {
			cout << n << ' ';
			for (int i = 1; i < n; ++i) {
				cout << i << " \n"[i == n - 1];
			}
		} else {
			cout << "-1\n";
		}
	}
	return 0;
}