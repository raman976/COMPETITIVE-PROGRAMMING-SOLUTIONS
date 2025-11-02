// B. Bitwise Reversion
// time limit per test
// 1.5 seconds
// memory limit per test
// 256 megabytes

// You are given three non-negative integers x
// , y and z. Determine whether there exist three non-negative integers a, b and c

// satisfying the following three conditions:

//     a&b=x

// b&c=y
// a&c=z

// where &

// denotes the bitwise AND operation.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The first and only line of each test case contains three integers x
// , y and z (0≤x,y,z≤109) — the target values of a&b, b&c and a&c

// , respectively.
// Output

// For each test case, output "YES" if there exists three non-negative integers a
// , b, and c

// satisfying the above conditions, and "NO" otherwise.

// You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.
// Example
// Input
// Copy

// 5
// 1 1 1
// 3 2 6
// 4 8 12
// 9 10 12
// 12730 3088 28130

// Output
// Copy

// YES
// YES
// NO
// YES
// NO

// Note

// In the first test case, a=3
// , b=5, and c=9 satisfies the condition as 3&5=1, 5&9=1, and 3&9=1

// .

// In the second test case, a=7
// , b=3, and c=22 satisfies the condition as 7&3=3, 3&22=2, and 7&22=6

// .

// In the third test case, it can be proven that there are no three non-negative integers a
// , b, and c such that a&b=4, b&c=8, and a&c=12

// .




#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
const int MAXL = 60;
 
int t;
ll x, y, z;
 
int main() {
    cin >> t;
    while (t--) {
        cin >> x >> y >> z;
        ll a = 0, b = 0, c = 0;
        bool ans = true;
        for (int l = MAXL - 1; l >= 0; l--) {
            ll bit_x = x >> l & 1, bit_y = y >> l & 1, bit_z = z >> l & 1;
            bool found = false;
            for (ll bit_a : {0, 1}) {
                for (ll bit_b : {0, 1}) {
                    for (ll bit_c : {0, 1}) {
                        if ((bit_a & bit_b) == bit_x &&
                            (bit_b & bit_c) == bit_y &&
                            (bit_a & bit_c) == bit_z) {
                            found = true;
                            a |= bit_a << l;
                            b |= bit_b << l;
                            c |= bit_c << l;
                            break;
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                if (found) {
                    break;
                }
            }
            if (!found) {
                ans = false;
                break;
            }
        }
        if (!ans) {
            cout << "NO\n";
        } else {
            assert((a & b) == x);
            assert((b & c) == y);
            assert((a & c) == z);
            cout << "YES\n";
        }
    }
    return 0;
}