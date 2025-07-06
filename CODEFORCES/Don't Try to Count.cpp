#include <iostream>
#include <string>
using namespace std;

int findMinOps(string x, string s) {
    string current = x;
    int ops = 0;
    // Cap to avoid infinite loops; 25 + few more is safe due to constraint
    while (current.length() <= 300) {
        if (current.find(s) != string::npos) {
            return ops;
        }
        current += current;
        ops++;
    }
    return -1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
        cout << findMinOps(x, s) << endl;
    }
    return 0;
}
