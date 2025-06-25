#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;  // number of test cases

    while (t--) {
        int n;
        cin >> n;  // length of the array

        int max_blank = 0, current_blank = 0;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;

            if (x == 0) {
                current_blank++;
                max_blank = max(max_blank, current_blank);
            } else {
                current_blank = 0;
            }
        }

        cout << max_blank << endl;
    }

    return 0;
}