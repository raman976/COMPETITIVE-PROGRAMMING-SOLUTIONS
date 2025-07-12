#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t; 
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string res(n, ' ');

        for (int i = 0; i < n; ) {
            if (s[i] == 'U') {
                res[i] = 'D';
                i++;
            }
            else if (s[i] == 'D') {
                res[i] = 'U';
                i++;
            }
            else if (s[i] == 'L') {
                res[i] = 'L';
                res[i + 1] = 'R';
                i += 2;
            }
            else if (s[i] == 'R') {

                i++;
            }
        }

        cout << res << endl;
    }

    return 0;
}
