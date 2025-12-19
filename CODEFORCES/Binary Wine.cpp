// C. Binary Wine
// time limit per test
// 2 seconds
// memory limit per test
// 512 megabytes

// You are given n
// integers a1,a2,…,an within the range [0,230)

// .

// You can spend 1
// coin to increase any ai by 1

// . You can perform this operation any number of times.

// You need to solve q
// queries; for each query, you are given an integer c, also in the range [0,230). You would like it if there exists a sequence b of length n

// with the following properties:

//     For every 1≤i≤n

// , 0≤bi≤ai
// .
// b1⊕b2⊕…⊕bn=c
// , where ⊕

//     denotes the bitwise XOR operation. 

// Please calculate the minimum number of coins you will have to spend, such that there exists a suitable b

// .

// The queries are independent, meaning that any operations you perform on the sequence a

// will not impact future queries.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The first line of each test case consists of two integers n,q
// (1≤n≤5⋅105, 1≤q≤5⋅104) — the length of sequence a

// and the number of queries.

// The second line of each test case contains n
// integers a1,a2,…,an (0≤ai<230) — the initial sequence a

// .

// Each of the next q
// lines contains a single integer c (0≤c<230

// ) — the target XOR.

// It is guaranteed that the sum of n
// over all test cases does not exceed 5⋅105

// .

// It is guaranteed that the sum of q
// over all test cases does not exceed 5⋅104

// .
// Output

// For each query, output a single integer — the minimum coins you will have to spend, such that there exists a suitable b

// .
// Example
// Input
// Copy

// 4
// 2 1
// 5 7
// 9
// 3 1
// 9 9 8
// 24
// 6 4
// 1 1 4 5 1 4
// 10
// 20
// 30
// 40
// 1 1
// 0
// 0

// Output
// Copy

// 1
// 7
// 3
// 11
// 16
// 31
// 0

// Note

// In the first test case, we spend 1
// coin to increase a2 by 1, resulting in sequence [5,8]. A suitable b would be [1,8]. It can be shown one cannot spend less than 1

// coin to achieve the objective.

// In the second test case, we can spend 7
// coins to increase a1 by 7, resulting in sequence [16,9,8]. A suitable b would be [16,9,1]

// .




#include <bits/stdc++.h>
#define N 500011
#define ll long long
using namespace std;
int T,n,q,a[N];
int main()
{
	scanf("%d",&T);while(T--)
	{
		scanf("%d%d",&n,&q);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		sort(a+1,a+1+n,greater<int>());
		int nn=min(n,32);
		while(q--)
		{
			int c;scanf("%d",&c);
			static int b[44];ll ans=0;
			for(int i=1;i<=nn;++i)b[i]=a[i];
			for(int i=29;~i;--i)
			{
				int cc=0;
				for(int j=1;j<=nn;++j)cc+=b[j]>>i&1;
				if(cc>(c>>i&1))break;
				if(cc<(c>>i&1))
				{
					int id=1;
					for(int j=2;j<=nn;++j)if(b[j]>b[id])id=j;
					ans+=(1<<i)-b[id];
					b[id]=0;
				}
				else for(int j=1;j<=nn;++j)b[j]&=~(1<<i);
			}
			printf("%lld\n",ans);
		}
	}
}