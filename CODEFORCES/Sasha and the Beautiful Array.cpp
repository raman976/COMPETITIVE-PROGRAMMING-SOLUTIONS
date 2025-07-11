// A. Sasha and the Beautiful Array
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes

// Sasha decided to give his girlfriend an array a1,a2,…,an
// . He found out that his girlfriend evaluates the beauty of the array as the sum of the values (ai−ai−1) for all integers i from 2 to n

// .

// Help Sasha and tell him the maximum beauty of the array a

// that he can obtain, if he can rearrange its elements in any way.
// Input

// Each test consists of multiple test cases. The first line contains a single integer t
// (1≤t≤500

// ) — the number of test cases. The description of the test cases follows.

// The first line of each test case contains a single integer n
// (2≤n≤100) — the length of the array a

// .

// The second line of each test case contains n
// integers a1,a2,…,an (1≤ai≤109) — the elements of the array a

// .
// Output

// For each test case, output a single integer — the maximum beauty of the array a

// that can be obtained.
// Example
// Input
// Copy

// 5
// 3
// 2 1 3
// 3
// 69 69 69
// 5
// 100 54 80 43 90
// 4
// 3 4 3 3
// 2
// 2 1

// Output
// Copy

// 2
// 0
// 57
// 1
// 1

// Note

// In the first test case, the elements of the array a
// can be rearranged to make a=[1,2,3]. Then its beauty will be equal to (a2−a1)+(a3−a2)=(2−1)+(3−2)=2

// .

// In the second test case, there is no need to rearrange the elements of the array a
// . Then its beauty will be equal to 0.




#include <bits/stdc++.h>
using namespace std;int main() {
    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;
        int mn = *min_element(a.begin(), a.end());
        int mx = *max_element(a.begin(), a.end());
        cout << mx - mn << '\n';
    }    return 0;
}