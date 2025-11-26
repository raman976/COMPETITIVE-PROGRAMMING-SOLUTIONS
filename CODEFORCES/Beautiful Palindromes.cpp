// E. Beautiful Palindromes
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// We call an array [b1,b2,…,bm]
// of length m

// palindromic if the following condition holds:

//     bi=bm−i+1

// for all 1≤i≤m

// In other words, an array is palindromic if it reads the same forward and backward.

// You are given an array [a1,a2,…,an]
// of n integers where 1≤ai≤n and an integer k

// .

// You are required to perform the following operation exactly k

// times:

//     choose an integer x

// such that 1≤x≤n
// ,
// append x
// to the end of the array a

//     . 

// Your goal is to perform these k
// operations in such a way that the number of palindromic subarrays∗

// in the resulting array is minimized.

// Output the k

// integers you chose for each operation, in the order they were appended.

// ∗
// An array b is a subarray of an array a if b can be obtained from a

// by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end. In particular, an array is a subarray of itself.
// Input

// The first line of input contains a single integer t
// (1≤t≤104

// ) — the number of test cases.

// The first line of each test case contains two integers n
// and k (3≤n≤2⋅105,1≤k≤n) — the length of the array a

// .

// The second line of each test case contains n
// integers a1,a2,…,an (1≤ai≤n) — the elements of the array a

// .

// It is guaranteed that the sum of n
// over all the test cases does not exceed 2⋅105

// .
// Output

// For each test case, print the k

// integers chosen for the append operations, in the order they were appended, such that the total number of palindromic subarrays in the resulting array is minimized.

// If there are multiple answers, you may output any one of them.
// Example
// Input
// Copy

// 5
// 4 1
// 1 3 3 4
// 4 2
// 2 2 2 2
// 5 1
// 4 1 5 2 2
// 6 3
// 1 2 3 4 5 6
// 5 3
// 3 2 5 2 3

// Output
// Copy

// 2 
// 1 3 
// 3 
// 3 4 1
// 4 1 5

// Note

// For the first test case, if we append 2
// to the end of the array, a becomes [1,3,3,4,2]. Now a has only 6 palindromic subarrays — [1], [3], [3], [4], [2], [3,3].




#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
    int t;
    cin >> t;
 
    while(t--){
        
        int n, k;
        cin >> n >> k;

        vector<int> a(n), cnt(n + 1, 0);
        for(int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;

        int x = -1;
        for(int i = 1; i <= n; i++) if(cnt[i] == 0){
            x = i;
            break;
        }

        if(x == -1){
            for(int i = 0; i < k; i++) cout << a[n - 3 + (i % 3)] << ' ';
            cout << '\n';
        }
        else{
            int y = -1;
            for(int i = 1; i <= n; i++) if(i != x && i != a[n - 1]){
                y = i;
                break;
            }
            vector<int> v = {x, y, a[n - 1]};
            for(int i = 0; i < k; i++) cout << v[i % 3] << ' ';
            cout << '\n';
        }

    }
}