// A. Treasure Hunt
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes

// Little B and his friend Little K found a treasure map, and now they just need to dig up the treasure, which is buried at a depth of a.5

// meters.

// They take turns digging. On the first day, Little B digs; on the second day, Little K. After each day, they switch. Little B digs exactly x
// meters of soil each day, while Little K digs y meters. They became curious about who will dig up the treasure first, meaning during whose day the total dug depth will exceed a.5

// .

// But they are too busy digging, so help them and tell who will dig up the treasure!
// Input

// The first line contains an integer t
// (1≤t≤1000

// ) — the number of test cases. The description of the test cases follows.

// In a single line of each test case, three integers x,y,a
// are given (1≤x,y,a≤109

// ).
// Output

// For each test case, output "NO" if Little B digs it up first; otherwise, output "YES". You can output the answer in any case.
// Example
// Input
// Copy

// 3
// 1 2 4
// 2 1 4
// 2 2 1

// Output
// Copy

// YES
// NO
// NO

// Note

// In the first test case, on the first day they will dig 1
// meter; on the second day 1+2=3 meters in total; on the third day 1+2+1=4 meters; and on the fourth day they will dig 6

// meters. Thus, the treasure will be dug up first by Little K.

// In the second test case, on the first day they will dig 2
// meters; on the second day 2+1=3 meters in total; on the third day 2+1+2=5

// meters, meaning it was dug up first by Little B.


// 





#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x, y, a;
    cin >> x >> y >> a;
    if (a % (x + y) < x) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}