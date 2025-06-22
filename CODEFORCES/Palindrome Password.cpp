// A. Palindrome Password
// time limit per test
// 1 second
// memory limit per test
// 64 megabytes

// Your first mission is to find the password of the Martian database. To achieve this, your best secret agents have already discovered the following facts:

//     The password is a substring of a given string composed of a sequence of non-decreasing digits
//     The password is as long as possible
//     The password is always a palindrome 

// A palindrome is a string that reads the same backwards. racecar, bob, and noon are famous examples.

// Given those facts, can you find all possible passwords of the database?
// Input

// The first line contains n, the length of the input string (1 ≤ n ≤ 105).

// The next line contains a string of length n. Every character of this string is a digit.

// The digits in the string are in non-decreasing order.
// Output

// On the first line, print the number of possible passwords, k.

// On the next k lines, print the possible passwords in alphabetical order.
// Examples
// Input
// Copy

// 8
// 34456788

// Output
// Copy

// 2
// 44
// 88

// Input
// Copy

// 1
// 0

// Output
// Copy

// 1
// 0

// Note

// You can easily convert a digit encoded as a character to an integer:

// (int)('1' - '0') will give you 1 for instance, in C++ or Java.

// int('4' - '0') will give you 4 in Python.

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define srt(x) x.begin(), x.end()
#define rsrt(x) x.rbegin(),x.rend()
typedef vector<int> vi;
typedef pair<int, int> pii;

// DEBUGGING (ignore for online judges)
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " = "; _print(x); cerr << endl;
template <class T> void _print(T t) {cerr << t;}
#else
#define debug(x)
#endif

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<string> v;
    int pointer = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            v.push_back(s.substr(pointer, i - pointer + 1));
            pointer = i + 1;
        }
    }
    v.push_back(s.substr(pointer,n - pointer));
    int max_size=0;
    for(auto x:v){
        max_size=max(max_size,(int)x.size());
    }
    int count=0;
    for(auto x:v){
        if((int)x.size()==max_size) count++;
    }
    cout<<count<<"\n";
    for(auto x:v){
        if((int)x.size()==max_size){
            cout<<x<<"\n";
        }
    }
}
#undef int
int main(int argc, char const *argv[])
{
#define int long long
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}