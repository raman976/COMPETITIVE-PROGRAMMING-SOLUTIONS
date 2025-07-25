// A. Arena
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes

// n
// heroes fight against each other in the Arena. Initially, the i-th hero has level ai

// .

// Each minute, a fight between two different heroes occurs. These heroes can be chosen arbitrarily (it's even possible that it is the same two heroes that were fighting during the last minute).

// When two heroes of equal levels fight, nobody wins the fight. When two heroes of different levels fight, the one with the higher level wins, and his level increases by 1

// .

// The winner of the tournament is the first hero that wins in at least 100500

// fights (note that it's possible that the tournament lasts forever if no hero wins this number of fights, then there is no winner). A possible winner is a hero such that there exists a sequence of fights that this hero becomes the winner of the tournament.

// Calculate the number of possible winners among n

// heroes.
// Input

// The first line contains one integer t
// (1≤t≤500

// ) — the number of test cases.

// Each test case consists of two lines. The first line contains one integer n
// (2≤n≤100) — the number of heroes. The second line contains n integers a1,a2,…,an (1≤ai≤100), where ai is the initial level of the i

// -th hero.
// Output

// For each test case, print one integer — the number of possible winners among the given n

// heroes.
// Example
// Input
// Copy

// 3
// 3
// 3 2 2
// 2
// 5 5
// 4
// 1 3 3 7

// Output
// Copy

// 1
// 0
// 3

// Note

// In the first test case of the example, the only possible winner is the first hero.

// In the second test case of the example, each fight between the heroes results in nobody winning it, so the tournament lasts forever and there is no winner.


// Codeforces



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }        int min_level = *min_element(a.begin(), a.end());        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] > min_level) {
                count++;
            }
        }        cout << count << endl;
    }
    return 0;
}