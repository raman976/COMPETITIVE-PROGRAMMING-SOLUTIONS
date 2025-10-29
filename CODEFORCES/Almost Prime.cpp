// A. Almost Prime
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// A number is called almost prime if it has exactly two distinct prime divisors. For example, numbers 6, 18, 24 are almost prime, while 4, 8, 9, 42 are not. Find the amount of almost prime numbers which are between 1 and n, inclusive.
// Input

// Input contains one integer number n (1 ≤ n ≤ 3000).
// Output

// Output the amount of almost prime numbers between 1 and n, inclusive.
// Examples
// Input
// Copy

// 10

// Output
// Copy

// 2

// Input
// Copy

// 21

// Output
// Copy

// 8






#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> prime_factors_count(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (prime_factors_count[i] == 0) {
            for (int j = i; j <= n; j += i) {
                prime_factors_count[j]++; 
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (prime_factors_count[i] == 2) count++;
    }

    cout << count << endl;
    return 0;
}
