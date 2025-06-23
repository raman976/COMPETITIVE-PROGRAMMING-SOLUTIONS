// A. Race
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// Alice and Bob participate in a game TV show. When the game starts, the prize will be dropped to a certain point, and whoever gets to it first will get the prize.

// Alice decided that she would start running from point a

// . Bob, however, has not yet chosen his starting position.

// Bob knows that the prize could drop either at point x
// or at point y. He also knows that he can reach the prize faster than Alice if the distance from his starting position to the prize is strictly less than the distance from Alice's starting position to the prize. The distance between any two points c and d is calculated as |c−d|

// .

// Your task is to determine whether Bob can choose an integer point that is guarantee to get to the prize faster, regardless of where it appears (at point x
// or y). Bob can choose any integer point, except for a (in particular, he can choose to start in point x, point y, or any other point, but not a

// ).
// Input

// The first line contains a single integer t
// (1≤t≤1000

// ) — the number of test cases.

// The only line of each test case contains three integers a
// , x, y (1≤a,x,y≤100). Points a, x, and y

// are pairwise distinct.
// Output

// For each test case, print "YES" (case insensitive) if Bob can choose an integer point that is guarantee to get to the prize faster, regardless of where it appears. Otherwise, print "NO" (case insensitive).
// Example
// Input
// Copy

// 3
// 1 3 4
// 5 3 1
// 3 1 5

// Output
// Copy

// YES
// YES
// NO

// Note

// In the first example, Bob can choose point 4
// . If the prize will be at point x, then Bob's distance is |4−3|=1 and Alice's distance is |1−3|=2. If the prize will be at point y, then Bob's distance is |4−4|=0 and Alice's distance is |1−4|=3

// .

// In the second example, Bob can choose point 2
// . If the prize will be at point x, then Bob's distance is |2−3|=1 and Alice's distance is |5−3|=2. If the prize will be at point y, then Bob's distance is |2−1|=1 and Alice's distance is |5−1|=4

// .

// In the third example, Bob cannot choose a point to guarantee his victory.

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
    int a,x,y;
    cin>>a>>x>>y;
    for(int i=1;i<=100;i++){
        if(a==i) continue;
        else{
            if(abs(x-i)<abs(x-a) && abs(y-i)<abs(y-a)){
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";
    // if((x>a && y>a && abs(a-x)>1 && abs(a-y)>1) || (x<a && y<a && abs(a-x)>1 && abs(a-y)>1)){
    //     cout<<"YES\n";
    // }else{
    //     cout<<"NO\n";
    // }
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