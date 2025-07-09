#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int total_twos = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (a[i] == 2) total_twos++;
        }

        int left_twos = 0;
        int answer = -1;
        for (int k = 0; k < n - 1; ++k) {
            if (a[k] == 2) left_twos++;
            int right_twos = total_twos - left_twos;
            if (left_twos == right_twos) {
                answer = k + 1;
                break;
            }
        }

        cout << answer << "\n";
    }

    return 0;
}
