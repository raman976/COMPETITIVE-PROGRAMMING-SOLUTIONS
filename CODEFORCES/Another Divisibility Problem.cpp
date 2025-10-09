// B. Another Divisibility Problem
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes

// Alice and Bob are playing a game in which Alice has given Bob a positive integer x<108

// .

// To win the game, Bob has to find another positive integer y<109
// such that x#y is divisible by x+y

// .

// Here x#y
// denotes the integer formed by concatenating the integers x and y in that order. For example, if x=835, y=47, then x#y=83547

// .

// However, since Bob is dumb, he is unable to find such an integer. Please help him.

// It can be shown that such an integer always exists.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The only line of each test case contains a single integer x
// (1≤x<108

// ) — the integer that Alice has given to Bob.
// Output

// For each test case, print a single integer y
// (1≤y<109

// ) so that Bob can win the game.

// If there are multiple answers, print any one of them.
// Example
// Input
// Copy

// 6
// 8
// 42
// 1000
// 66666
// 106344
// 9876543

// Output
// Copy

// 1
// 12
// 998
// 7872
// 8190
// 174036

// Note

// For the first test case, x=8
// , we can choose y=1, and we have x#y=81, which is divisible by x+y=9

// .

// For the second test case, x=42
// , we can choose y=12, and we have x#y=4212, which is divisible by x+y=54

// .





#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
        int x;
        cin >> x;
        cout << 2*x<< '\n';
    }
    return 0;
}