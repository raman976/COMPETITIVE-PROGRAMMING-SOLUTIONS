// A. Design Tutorial: Learn from Math
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes

// One way to create a task is to learn from math. You can generate some random math statement or modify some theorems to get something new and build a new task from that.

// For example, there is a statement called the "Goldbach's conjecture". It says: "each even number no less than four can be expressed as the sum of two primes". Let's modify it. How about a statement like that: "each integer no less than 12 can be expressed as the sum of two composite numbers." Not like the Goldbach's conjecture, I can prove this theorem.

// You are given an integer n no less than 12, express it as a sum of two composite numbers.
// Input

// The only line contains an integer n (12 ≤ n ≤ 106).
// Output

// Output two composite integers x and y (1 < x, y < n) such that x + y = n. If there are multiple solutions, you can output any of them.
// Examples
// Input
// Copy

// 12

// Output
// Copy

// 4 8

// Input
// Copy

// 15

// Output
// Copy

// 6 9

// Input
// Copy

// 23

// Output
// Copy

// 8 15

// Input
// Copy

// 1000000

// Output
// Copy

// 500000 500000

// Note

// In the first example, 12 = 4 + 8 and both 4, 8 are composite numbers. You can output "6 6" or "8 4" as well.

// In the second example, 15 = 6 + 9. Note that you can't output "1 14" because 1 is not a composite number.

//        ／＞　 フ
//        | 　_　_|    ← This lil guy runs it fine
//      ／` ミ＿xノ
//     /　　　　 |
//    /　 ヽ　　 ﾉ
//    │　　|　|　|
//  ／￣|　　 |　|　|
// (￣ヽ＿_ヽ_)__)
//  ＼二)

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
        {
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
                               { ((cerr << (f++ ? "," : ""), print(args)), ...); }, x);
            cerr << ')';
        }
        else
            cerr << x;
    }

    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail)
    {
        int i = 0;
        for (int bracket = 0; names[i] != '\0' && (names[i] != ',' || bracket > 0); i++)
            if (names[i] == '(' || names[i] == '<' || names[i] == '{')
                bracket++;
            else if (names[i] == ')' || names[i] == '>' || names[i] == '}')
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
        for (; names[i] && names[i] != ','; i++)
            cerr << names[i];
        for (i++; names[i] && names[i] != ','; i++)
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

bool isComp(int n)
{
    if (n <= 3)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return true;
    }
    return false;
}

void solve()
{
    int n;
    cin >> n;
    for (int x = 4; x <= n / 2; x++)
    {
        int y = n - x;
        if (isComp(x) && isComp(y))
        {
            cout << x << " " << y << endl;
            break;
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