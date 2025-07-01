// A. Medium Number
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes

// Given three distinct integers a
// , b, and c

// , find the medium number between all of them.

// The medium number is the number that is neither the minimum nor the maximum of the given three numbers.

// For example, the median of 5,2,6
// is 5, since the minimum is 2 and the maximum is 6

// .
// Input

// The first line contains a single integer t
// (1≤t≤6840

// ) — the number of test cases.

// The description of each test case consists of three distinct integers a
// , b, c (1≤a,b,c≤20

// ).
// Output

// For each test case, output a single integer — the medium number of the three numbers.
// Example
// Input
// Copy

// 9
// 5 2 6
// 14 3 4
// 20 2 1
// 1 2 3
// 11 19 12
// 10 8 20
// 6 20 3
// 4 1 3
// 19 8 4

// Output
// Copy

// 5
// 4
// 2
// 2
// 12
// 10
// 6
// 3
// 8


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

    void print(vector<bool> &v) {
        int f = 0;
        cerr << '{';
        for (auto &&i : v)
            cerr << (f++ ? "," : "") << (i ? "T" : "F");
        cerr << "}";
    }

    template <typename T>
    void print(T &&x) {
        if constexpr (is_iterable<T>) {
            if (size(x) && is_iterable<decltype(*(begin(x)))>) {
                int f = 0;
                cerr << "\n~~~~~\n";
                int w = max(0LL, (long long)log10(size(x) - 1)) + 2;
                for (auto &&i : x) {
                    cerr << setw(w) << left << f++, print(i), cerr << "\n";
                }
                cerr << "~~~~~\n";
            } else {
                int f = 0;
                cerr << "{";
                for (auto &&i : x)
                    cerr << (f++ ? "," : ""), print(i);
                cerr << "}";
            }
        } else if constexpr (requires { x.pop(); }) {
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
        } else if constexpr (requires { x.first; x.second; }) {
            cerr << '(', print(x.first), cerr << ',', print(x.second), cerr << ')';
        } else if constexpr (requires { get<0>(x); }) {
            int f = 0;
            cerr << '(', apply([&f](auto... args) { ((cerr << (f++ ? "," : ""), print(args)), ...); }, x);
            cerr << ')';
        } else
            cerr << x;
    }

    template <typename T, typename... V>
    void printer(const char *names, T &&head, V &&...tail) {
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
    void printerArr(const char *names, T arr[], size_t N, V... tail) {
        size_t i = 0;
        for (; names[i] && names[i] != ','; i++)
            cerr << names[i];
        for (i++; names[i] && names[i] != ','; i++);
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
    int a, b, c;
    cin >> a >> b >> c;
    
    int arr[3] = {a, b, c};
    sort(arr, arr + 3);
        cout << arr[1] << '\n'; 
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