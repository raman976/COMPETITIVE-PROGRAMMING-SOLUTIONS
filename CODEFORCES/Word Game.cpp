#include <bits/stdc++.h>
using namespace std;int main() {
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;        vector<vector<string>> words(3, vector<string>(n));
        map<string, int> freq;        // Input words and count frequencies
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> words[i][j];
                freq[words[i][j]]++;
            }
        }        // Calculate points for each player
        vector<int> points(3, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < n; ++j) {
                string& word = words[i][j];
                if (freq[word] == 1) points[i] += 3;
                else if (freq[word] == 2) points[i] += 1;
                // if freq[word] == 3 → 0 points
            }
        }        // Output result
        for (int i = 0; i < 3; ++i) {
            cout << points[i] << " ";
        }
        cout << endl;
    }
    return 0;
}