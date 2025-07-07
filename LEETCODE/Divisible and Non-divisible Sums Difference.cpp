class Solution {
public:
    int differenceOfSums(int n, int m) {
        int total = n * (n + 1) / 2;
        int k = n / m;
        int sumDiv = m * (k * (k + 1)) / 2;
        return total - 2 * sumDiv;
    }
};
