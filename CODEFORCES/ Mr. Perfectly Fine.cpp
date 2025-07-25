// C. Mr. Perfectly Fine
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// Victor wants to become "Mr. Perfectly Fine". For that, he needs to acquire a certain set of skills. More precisely, he has 2

// skills he needs to acquire.

// Victor has n
// books. Reading book i takes him mi minutes and will give him some (possibly none) of the required two skills, represented by a binary string of length 2

// .

// What is the minimum amount of time required so that Victor acquires all of the two skills?
// Input

// The input consists of multiple test cases. The first line contains an integer t
// (1≤t≤1000

// ) — the number of test cases. The description of the test cases follows.

// The first line of each test case contains an integer n
// (1≤n≤2⋅105

// ) — the number of books available.

// Then n
// lines follow. Line i contains a positive integer mi (1≤mi≤2⋅105) and a binary string of length 2, where si1=1 if reading book i acquires Victor skill 1, and si1=0 otherwise, and si2=1 if reading book i acquires Victor skill 2, and si2=0

// otherwise.

// It is guaranteed that the sum of n
// over all test cases doesn't exceed 2⋅105

// .
// Output

// For each test case, output a single integer denoting the minimum amount of minutes required for Victor to obtain both needed skills and −1

// in case it's impossible to obtain the two skills after reading any amount of books.
// Example
// Input
// Copy

// 6
// 4
// 2 00
// 3 10
// 4 01
// 4 00
// 5
// 3 01
// 3 01
// 5 01
// 2 10
// 9 10
// 1
// 5 11
// 3
// 9 11
// 8 01
// 7 10
// 6
// 4 01
// 6 01
// 7 01
// 8 00
// 9 01
// 1 00
// 4
// 8 00
// 9 10
// 9 11
// 8 11

// Output
// Copy

// 7
// 5
// 5
// 9
// -1
// 8

// Note

// In the first test case, we can use books 2
// and 3, with a total amount of minutes spent equal to 3+4=7

// .

// In the second test case, we can use the books 1
// and 4, with a total amount of minutes spent equal to 3+2=5

// .

// In the third test case, we have only one option and that is reading book 1
// for a total amount of minutes spent equal to 5.



#include <iostream>
#include <climits>
using namespace std;int main() {
    int t;
    cin >> t;    while (t--) {
        int n;
        cin >> n;        int min10 = INT_MAX;
        int min01 = INT_MAX;
        int min11 = INT_MAX;        for (int i = 0; i < n; ++i) {
            int m;
            string s;
            cin >> m >> s;            if (s == "10") {
                min10 = min(min10, m);
            } else if (s == "01") {
                min01 = min(min01, m);
            } else if (s == "11") {
                min11 = min(min11, m);
            }
        }        int both = (min10 != INT_MAX && min01 != INT_MAX) ? min10 + min01 : INT_MAX;
        int result = min(both, min11);        if (result == INT_MAX) cout << -1 << endl;
        else cout << result << endl;
    }    return 0;
}
