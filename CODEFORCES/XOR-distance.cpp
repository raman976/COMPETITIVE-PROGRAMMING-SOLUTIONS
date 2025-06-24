#include <bits/stdc++.h>
using namespace std;

const int MAX_BITS = 60;

bool getBit(int64_t num, int pos) {
    return num & (1LL << pos);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int testCases;
    cin >> testCases;

    while (testCases--) {
        int64_t a, b, r;
        cin >> a >> b >> r;

        int64_t x = 0;
        bool isFirstDiffBit = true;

        if (a > b)
            swap(a, b);

        for (int i = MAX_BITS - 1; i >= 0; --i) {
            bool bitA = getBit(a, i);
            bool bitB = getBit(b, i);

            if (bitA != bitB) {
                if (isFirstDiffBit) {
                    isFirstDiffBit = false;
                } else {
                    if (!bitA && x + (1LL << i) <= r) {
                        x += (1LL << i);
                        a ^= (1LL << i);
                        b ^= (1LL << i);
                    }
                }
            }
        }

        cout << b - a << "\n";
    }

    return 0;
}
