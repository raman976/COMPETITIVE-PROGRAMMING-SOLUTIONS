// B. Longest Divisors Interval
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// Given a positive integer n
// , find the maximum size of an interval [l,r] of positive integers such that, for every i in the interval (i.e., l≤i≤r), n is a multiple of i

// .

// Given two integers l≤r
// , the size of the interval [l,r] is r−l+1

// (i.e., it coincides with the number of integers belonging to the interval).
// Input

// The first line contains a single integer t
// (1≤t≤104

// ) — the number of test cases.

// The only line of the description of each test case contains one integer n
// (1≤n≤1018

// ).
// Output

// For each test case, print a single integer: the maximum size of a valid interval.
// Example
// Input
// Copy

// 10
// 1
// 40
// 990990
// 4204474560
// 169958913706572972
// 365988220345828080
// 387701719537826430
// 620196883578129853
// 864802341280805662
// 1000000000000000000

// Output
// Copy

// 1
// 2
// 3
// 6
// 4
// 22
// 3
// 1
// 2
// 2

// Note

// In the first test case, a valid interval with maximum size is [1,1]
// (it's valid because n=1 is a multiple of 1) and its size is 1

// .

// In the second test case, a valid interval with maximum size is [4,5]
// (it's valid because n=40 is a multiple of 4 and 5) and its size is 2

// .

// In the third test case, a valid interval with maximum size is [9,11]

// .

// In the fourth test case, a valid interval with maximum size is [8,13]

// .

// In the seventh test case, a valid interval with maximum size is [327869,327871]
// .

//    .--.
//   |o_o |   <- it works on my machine
//   |:_/ |
//  //   \ \
// (|     | )
// /'\_   _/`\
// \___)=(___/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
typedef vector<int> vi;
typedef pair<int, int> pii;

// DEBUGGING TEMPLATE
#ifndef DEBUG_TEMPLATE_CPP
#define DEBUG_TEMPLATE_CPP
#include <bits/stdc++.h>
using namespace std;

namespace __DEBUG_UTIL__
{
    template <typename T>
    concept is_iterable = requires(T &&x) { begin(x); } &&
                          !is_same_v<remove_cvref_t<T>, string>;
    void print(const char *x) { cerr << x; }
    void print(char x) { cerr << "'" << x << "'"; }
    void print(bool x) { cerr << (x ? "T" : "F"); }
    void print(string x) { cerr << '"' << x << '"'; }
    void print(vector<bool> &v)
    {
        int f = 0;
        cerr << '{';
        for (auto &&i : v)
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        cerr << "}";
    }
    template <typename T>
    void print(T &&x)
    {
        if constexpr (is_iterable<T>)
            if (size(x) && is_iterable<decltype(*(begin(x)))>)
            {
                int f = 0;
                cerr << "\n~~~~~\n";
                int w = max(0LL, (long long)log10(size(x) - 1)) + 2;
                for (auto &&i : x)
                {
                    cerr << setw(w) << left << f++, print(i), cerr << "\n";
                }
                cerr << "~~~~~\n";
            }
            else
            {
                int f = 0;
                cerr << "{";
                for (auto &&i : x)
                    cerr << (f++ ? "," : ""), print(i);
                cerr << "}";
            }
        else if constexpr (requires { x.pop(); })
        {
            auto temp = x;
            int f = 0;
            cerr << "{";
            if constexpr (requires { x.top(); })
                while (!temp.empty())
                    cerr << (f++ ? "," : ""), print(temp.top()), temp.pop();
            else
                while (!temp.empty())
                    cerr << (f++ ? "," : ""), print(temp.front()), temp.pop();
            cerr << "}";
        }
        else if constexpr (requires { x.first; x.second; })
        {
            cerr << '(', print(x.first), cerr << ',', print(x.second), cerr << ')';
        }
        else if constexpr (requires { get<0>(x); })
        {
            int f = 0;
            cerr << '(', apply([&f](auto... args)
                               { ((cerr << (f++ ? "," : ""), print(args)), ...); },
                               x);
            cerr << ')';
        }
        else
            cerr << x;
    }
    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        int i = 0;
        for (int bracket = 0; names[i] != '\0' and (names[i] != ',' or bracket > 0); i++)
            if (names[i] == '(' or names[i] == '<' or names[i] == '{')
                bracket++;
            else if (names[i] == ')' or names[i] == '>' or names[i] == '}')
                bracket--;
        cerr.write(names, i) << " = ";
        print(head);
        if constexpr (sizeof...(tail))
            cerr << " ||", printer(names + i + 1, tail...);
        else
            cerr << "]\n";
    }
    template <typename T, typename... V>
    void printerArr(const char *names, T arr[], size_t N, V... tail)
    {
        size_t i = 0;
        for (; names[i] and names[i] != ','; i++)
            cerr << names[i];
        for (i++; names[i] and names[i] != ','; i++)
            ;
        cerr << " = {";
        for (size_t ind = 0; ind < N; ind++)
            cerr << (ind ? "," : ""), print(arr[ind]);
        cerr << "}";
        if constexpr (sizeof...(tail))
            cerr << " ||", printerArr(names + i + 1, tail...);
        else
            cerr << "]\n";
    }
}
#ifndef ONLINE_JUDGE
#define debug(...) cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
#define debugArr(...) cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#define debugArr(...)
#endif
#endif

void solve() {
    int n;
    cin>>n;
    for (int i=1;i<=n+1;i++){
        if(n%i!=0){
            cout<<i-1<<"\n";
            break;
        }
    }
}

#undef int
int main(int argc, char const *argv[]) {
    #define int long long
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
     cin >> t;
    while (t--) solve();

    return 0;
}