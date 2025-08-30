// C. Sending Messages
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// Stepan is a very busy person. Today he needs to send n
// messages at moments m1,m2,…mn (mi<mi+1). Unfortunately, by the moment 0, his phone only has f units of charge left. At the moment 0

// , the phone is turned on.

// The phone loses a
// units of charge for each unit of time it is on. Also, at any moment, Stepan can turn off the phone and turn it on later. This action consumes b units of energy each time. Consider turning on and off to be instantaneous, so you can turn it on at moment x and send a message at the same moment, and vice versa, send a message at moment x

// and turn off the phone at the same moment.

// If at any point the charge level drops to 0
// (becomes ≤0

// ), it is impossible to send a message at that moment.

// Since all messages are very important to Stepan, he wants to know if he can send all the messages without the possibility of charging the phone.
// Input

// The first line of the input contains a single integer t
// (1≤t≤104

// ) — the number of test cases. This is followed by the descriptions of the test cases.

// The first line of each test case contains four integers n
// , f, a, and b (1≤n≤2⋅105, 1≤f,a,b≤109

// ) — the number of messages, the initial phone's charge, the charge consumption per unit of time, and the consumption when turned off and on sequentially.

// The second line of each test case contains n
// integers m1,m2,…,mn (1≤mi≤109, mi<mi+1

// ) — the moments at which messages need to be sent.

// It is guaranteed that in a test the sum of n
// over all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output "YES" if Stepan can send all the messages, and "NO" otherwise.

// You can output each letter in any case (lowercase or uppercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be accepted as a positive answer.
// Example
// Input
// Copy

// 6
// 1 3 1 5
// 3
// 7 21 1 3
// 4 6 10 13 17 20 26
// 5 10 1 2
// 1 2 3 4 5
// 1 1000000000 1000000000 1000000000
// 1000000000
// 3 11 9 6
// 6 8 10
// 12 621526648 2585904 3566299
// 51789 61859 71998 73401 247675 298086 606959 663464 735972 806043 806459 919683

// Output
// Copy

// NO
// YES
// YES
// NO
// NO
// YES

// Note

// In the first test case of the example, at moment 0
// , the phone's charge is 3. When sending a message at moment 3 without turning it off, (3−0)⋅1=3 units of charge will be spent. In this case, the charge will drop to 0 and Stepan will not be able to send the message. When turning off and on, the phone's charge will decrease by 5

// , so it will not be possible to send the message in this way.

// In the third test case of the example, at moment 0
// , the phone's charge is 10. The phone loses 1 unit of charge per unit of time, and when turned off and on, it loses 2

// units of charge. To send all messages, the following actions can be taken:

//     Turn off the phone at moment 0

// and turn it on at moment 1, after which 10−2=8
// units of charge will remain;
// send a message at moment 1
// ;
// send a message at moment 2
// , after which 8−(2−1)⋅1=7
// units of charge will remain;
// Turn off the phone at moment 2
// and turn it on at moment 3, after which 7−2=5
// units of charge will remain;
// send a message at moment 3
// ;
// Turn off the phone at moment 3
// and turn it on at moment 4, after which 5−2=3
// units of charge will remain;
// send a message at moment 4
// ;
// Turn off the phone at moment 4
// and turn it on at moment 5, after which 3−2=1
// unit of charge will remain;
// send a message at moment 5

//     . 

// The last (sixth) test set of the example may fail if there is an integer overflow in your solution.





#include <bits/stdc++.h>
using namespace std;int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x;
    cin >> x;
    while (x--) {
        int n;
        long long f, a, b;
        cin >> n >> f >> a >> b;
        vector<long long> m(n + 1);
        m[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> m[i];
        }        for (int i = 1; i <= n; i++) {
            f -= min(a * (m[i] - m[i - 1]), b);
        }        cout << (f > 0 ? "YES\n" : "NO\n");
    }    return 0;
} 