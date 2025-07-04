// D. Translation
// time limit per test
// 2 seconds
// memory limit per test
// 64 megabytes

// Martians use the English alphabet to communicate. However, they have an entirely different language, but it’s based on a one-to-one (bijective) mapping of letters from Martian to English. Be careful though, lower-case and upper-case letters in English aren’t necessarily the same in Martian. For example, the word "CARS" in Martian translates to "Unil" in English, whereas the word "cars" in Martian translates to "EPFL".

// The Martians have invaded Earth! But, we have intercepted their communications. Help us translate their messages to English.
// Input

// The first line of the input contains an integer n (1 ≤ n ≤ 100).

// The second line contains a sentence in Martian, consisting of n space-separated words each consisting of lower-case and upper-case English letters. The total number of letters in the sentence is at most 105.
// Output

// Print, on a single line, n space-separated words representing the English translation of the sentence.

// Do not print any leading or trailing spaces, and end your output with a newline character.
// Examples
// Input
// Copy

// 1
// CARS

// Output
// Copy

// Unil

// Input
// Copy

// 1
// cars

// Output
// Copy

// EPFL

// Input
// Copy

// 3
// IuVEJxTXs UvOHhng yZKfAYmaqolM

// Output
// Copy

// vpVZzBNtL SCubWma ocIYneAPqxDs

// Input
// Copy

// 3
// NtGQibw djPrCpek FWzL

// Output
// Copy

// hRkMGgJ fHrFUQTj XOwd

// Input
// Copy

// 3
// aySBaPyb RM gzYMynY

// Output
// Copy

// PolyProg is awesome

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

void solve() {
  int n;
  cin>>n;
  string given;
  for (int i = 0; i < n; i++)
  {
      string s;
      cin>>s;
      given+=s+' ';
  }
  map<char,char> mp;
  mp['A']='n';
  mp['B']='y';
  mp['C']='U';
  mp['D']='K';
  mp['E']='Z';
  mp['F']='X';
  mp['G']='k';
  mp['H']='b';
  mp['I']='v';
  mp['J']='z';
  mp['K']='I';
  mp['L']='d';
  mp['M']='s';
  mp['N']='h';
  mp['O']='u';
  mp['P']='r';
  mp['Q']='M';
  mp['R']='i';
  mp['S']='l';
  mp['T']='N';
  mp['U']='S';
  mp['V']='V';
  mp['W']='O';
  mp['X']='t';
  mp['Y']='e';
  mp['Z']='c';
  mp['a']='P';
  mp['b']='g';
  mp['c']='E';
  mp['d']='f';
  mp['e']='T';
  mp['f']='Y';
  mp['g']='a';
  mp['h']='W';
  mp['i']='G';
  mp['j']='H';
  mp['k']='j';
  mp['l']='D';
  mp['m']='A';
  mp['n']='m';
  mp['o']='x';
  mp['p']='Q';
  mp['q']='q';
  mp['r']='F';
  mp['s']='L';
  mp['t']='R';
  mp['u']='p';
  mp['v']='C';
  mp['w']='J';
  mp['x']='B';
  mp['y']='o';
  mp['z']='w';
  mp[' ']=' ';
  string ans="";
  for(auto x:given){
      ans+=mp[x];
  }
  cout<<ans;
}







int main(int argc, char const *argv[]) {
    ios::sync_with_stdio(0);cin.tie(0);

    int t = 1;

    while (t--) solve();

    return 0;
}