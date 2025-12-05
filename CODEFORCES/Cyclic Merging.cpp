// A. Cyclic Merging
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// You are given n
// non-negative integers a1,a2,…,an arranged on a ring. For each 1≤i<n, ai and ai+1 are adjacent; a1 and an

// are adjacent.

// You need to perform the following operation exactly n−1

// times:

//     Choose any pair of adjacent elements on the ring, let their values be x

// and y, and merge them into a single element of value max(x,y) with cost max(x,y)

//     . 

// Note that this operation will decrease the size of the ring by 1

// and update the adjacent relationships accordingly.

// Please calculate the minimum total cost to merge the ring into one element.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The first line of each test case contains an integer n
// (2≤n≤2⋅105

// ).

// The following line contains n
// integers a1,a2,…,an (0≤ai≤109

// ).

// It is guaranteed that the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, please print a single integer — the minimum total cost.
// Example
// Input
// Copy

// 3
// 4
// 1 1 3 2
// 2
// 0 2
// 7
// 1 1 4 5 1 4 1

// Output
// Copy

// 6
// 2
// 19

// Note

// In the first test case, we can achieve a cost of 6
// on [1,1,3,2]

// as follows:

//     Merge indexes 1

// and 2 with a cost of 1, the ring becomes [1,3,2]
// .
// Merge indexes 1
// and 3 with a cost of 2, the ring becomes [3,2]
// .
// Merge indexes 1
// and 2 with a cost of 3, the ring becomes [3]

//     . 

// The total cost is 1+2+3=6
// . It can be proven that it is impossible to achieve a lower cost; thus, the answer is indeed 6

// .

// In the second test case, the only option is to merge the two elements, with a cost of 2
// .



#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 1e6 + 5;
ll a[N];

int main()
{
	int t, n, m, i;
	ll k;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		m = 0;
		for(i = 0; i < n; i++)
		{
			scanf("%lld", a + i);
			if(a[i] > a[m])
				m = i;
		}
		a[n] = a[0];
		k = -a[m];
		for(i = 0; i < n; i++)
			k += max(a[i], a[i + 1]);
		printf("%lld\n", k);
	}
	return 0;
}