// A. Add or XOR
// time limit per test
// 1 second
// memory limit per test
// 256 megabytes
// r-906 & IA AI - Psychologic Disco

// You are given two non-negative integers a,b
// . You can apply two types of operations on a

// any number of times and in any order:

//     a←a+1

// . The cost of this operation is x
// ;
// a←a⊕1
// , where ⊕ denotes the bitwise XOR operation. The cost of this operation is y

//     . 

// Now you are asked to make a=b

// . If it's possible, output the minimum cost; otherwise, report it.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The only line of each test case contains four integers a,b,x,y
// (1≤a,b≤100,1≤x,y≤107

// ) — the two integers given to you and the respective costs of two types of operations.
// Output

// For each test case, output an integer — the minimum cost to make a=b
// , or −1

// if it is impossible.
// Example
// Input
// Copy

// 7
// 1 4 1 2
// 1 5 2 1
// 3 2 2 1
// 1 3 2 1
// 2 1 1 2
// 3 1 1 2
// 1 100 10000000 10000000

// Output
// Copy

// 3
// 6
// 1
// 3
// -1
// -1
// 990000000

// Note

// In the first test case, the optimal strategy is to apply a←a+1
// three times. The total cost is 1+1+1=3

// .

// In the second test case, the optimal strategy is to apply a←a+1
// , a←a⊕1, a←a+1, a←a⊕1 in order. The total cost is 2+1+2+1=6

// .

// In the fifth test case, it can be proved that there isn't a way to make a=b

// .




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
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    if(a>b+1){
        cout<<-1<<"\n";
        return;
    }
    else if(a==b){
        cout<<0<<'\n';
        return;
    }
    else if(a==b+1){
        if(a%2!=0){
            cout<<y<<"\n"; 
        }else{
            cout<<-1<<"\n";
        }
        return;
    }
    else if(x<=y){
        int ans=(b-a)*x;
        cout<<ans<<"\n";
    }
    else{
        int ans=0;
        while(a!=b){
            if(a%2!=0){
                a+=1;
                ans+=x;
            }else{
                a+=1;
                ans+=y;
            }
        }
        cout<<ans<<"\n";
        return;
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