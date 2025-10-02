// B. Lasers
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// There is a 2D-coordinate plane that ranges from (0,0)
// to (x,y). You are located at (0,0) and want to head to (x,y)

// .

// However, there are n
// horizontal lasers, with the i-th laser continuously spanning (0,ai) to (x,ai). Additionally, there are also m vertical lasers, with the i-th laser continuously spanning (bi,0) to (bi,y)

// .

// You may move in any direction to reach (x,y)

// , but your movement must be a continuous curve that lies inside the plane. Every time you cross a vertical or a horizontal laser, it counts as one crossing. Particularly, if you pass through an intersection point between two lasers, it counts as two crossings.

// For example, if x=y=2
// , n=m=1, a=[1], b=[1]

// , the movement can be as follows:

// What is the minimum number of crossings necessary to reach (x,y)

// ?
// Input

// The first line contains t
// (1≤t≤104

// )  — the number of test cases.

// The first line of each test case contains four integers n
// , m, x, and y (1≤n,m≤2⋅105,2≤x,y≤109

// ).

// The following line contains n
// integers a1,a2,…,an (0<ai<y)  — the y-coordinates of the horizontal lasers. It is guaranteed that ai>ai−1 for all i>1

// .

// The following line contains m
// integers b1,b2,…,bm (0<bi<x)  — the x-coordinates of the vertical lasers. It is guaranteed that bi>bi−1 for all i>1

// .

// It is guaranteed that the sum of n
// and m over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output the minimum number of crossings necessary to reach (x,y)

// .
// Example
// Input
// Copy

// 2
// 1 1 2 2
// 1
// 1
// 2 1 100000 100000
// 42 58
// 32

// Output
// Copy

// 2
// 3






#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)

int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n, m, x, y, s = 0;
        cin >> n >> m >> x >> y;

        forn(i, n)
            cin >> s; 
        forn(i, m)
            cin >> s; 

        cout << n + m << endl;

    }
}