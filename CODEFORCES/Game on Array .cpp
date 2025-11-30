// D. Game on Array
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// You are given an array a
// of n

// positive integers. Alice and Bob will play a game with this array. They will take alternating turns, with Alice going first.

// At each turn, the player must choose a value x>0
// that appears in a

// at least once. Then,

//     the player earns 1

// point for each value x
// in the array,
// each value x
// in the array is decreased by 1 and becomes x−1

//     . 

// Note that the player can choose x only if it is present in a at the moment, so each valid move earns a positive amount of points. For example, if the array is [3,8,5,8] and Alice chooses x=8, the array will become [3,7,5,7] and Alice will earn 2 points.

// The game ends when no x

// can be chosen; that is, when all the elements in the array are zero.

// Given that both players want to maximize their points and play optimally, calculate the amount of points that each player will end up with.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤103

// ). The description of the test cases follows.

// The first line of each test case contains an integer n
// (1≤n≤2⋅105

// ) — the size of the array.

// The second line contains n
// integers a1,a2,…,an (1≤ai≤109

// ) — the elements of the array.

// It is guaranteed that the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output two integers, the amount of points Alice and Bob will get if both play optimally.
// Example
// Input
// Copy

// 3
// 3
// 2 1 1
// 5
// 3 3 3 5 5
// 4
// 9 9 9 9

// Output
// Copy

// 3 1
// 10 9
// 20 16

// Note

// Visualizer link

// In the first test case, Alice chooses x=1
// with her first move. The array becomes [2,0,0] and she earns 2 points. After that, Bob is forced to choose x=2. The array becomes [1,0,0] and Bob earns 1 point. Finally, Alice is forced to choose x=1 and earn one more point. After that, the array is [0,0,0], so the game ends. In total, Alice finishes with 3 points and Bob with 1

// point.

// In the third test case, each player will decrement all the elements and earn 4
// points each move. Alice will earn 5⋅4=20 points while Bob will only earn 4⋅4=16

// points.

#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
using ld = long double;
using ll = long long;
const int maxN = 2e5+5;
const int INF = 1e18;
const int MOD = 1e9+7;
#define F first
#define S second
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int rnd(int b){
	return (unsigned long long)rng()%b;
}
int power(int a, int b){
	if(b==0)return 1;
	if(b%2)return a*power(a,b-1)%MOD;
	return power(a*a%MOD,b/2);
}
int inv(int a){
	return power(a,MOD-2);
}
vector<int>fact(maxN);
vector<int>invfact(maxN);
 
 
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
 
		map<int,int>freq;
		int s= 0;
		int sum = 0;
		for(int i = 0;i<n;i++){
			int x;
			cin>>x;
			if(x%2)freq[x]++, s+=x-1;
			else s+=x;
			sum +=x;
		}
		int A = s/2;;
		vector<int>b;
		for(auto [u,v] : freq)b.push_back(v);
		sort(b.rbegin(),b.rend());
		for(int i = 0;i<b.size();i+=2)A+=b[i];
		cout<<A<<" "<<sum-A<<endl;
 
	}
	
}