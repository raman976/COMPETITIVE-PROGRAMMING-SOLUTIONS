// B. Above the Clouds
// time limit per test
// 2 seconds
// memory limit per test
// 256 megabytes

// You are given a string s
// of length n, consisting of lowercase letters of the Latin alphabet. Determine whether there exist three non-empty strings a, b, and c

// such that:

//     a+b+c=s

// , meaning the concatenation∗ of strings a, b, and c equals s
// .
// The string b
// is a substring† of the string a+c, which is the concatenation of strings a and c

//     . 

// ∗
// Concatenation of strings a and b is defined as the string a+b=a1a2…apb1b2…bq, where p and q are the lengths of strings a and b

// , respectively. For example, the concatenation of the strings "code" and "forces" is "codeforces".

// †
// A string a is a substring of a string b if a can be obtained from b

// by the deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.
// Input

// Each test consists of multiple test cases. The first line contains a single integer t
// (1≤t≤104

// ) — the number of test cases. The description of the test cases follows.

// The first line of each test case contains a single integer n
// (3≤n≤105) — the length of the string s

// .

// The second line of each test case contains the string s
// of length n

// , consisting of lowercase letters of the Latin alphabet.

// It is guaranteed that the sum of n
// across all test cases does not exceed 2⋅105

// .
// Output

// For each test case, output "Yes" if there exist three non-empty strings a
// , b, and c

// that satisfy the conditions, and "No" otherwise.

// You may output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.
// Example
// Input
// Copy

// 12
// 3
// aaa
// 3
// aba
// 3
// aab
// 4
// abca
// 4
// abba
// 4
// aabb
// 5
// abaca
// 5
// abcda
// 5
// abcba
// 6
// abcbbf
// 6
// abcdaa
// 3
// abb

// Output
// Copy

// Yes
// No
// Yes
// No
// Yes
// Yes
// Yes
// No
// Yes
// Yes
// Yes
// Yes

// Note

// In the first test case, there exist unique non-empty strings a
// , b, and c such that a+b+c=s. These are the strings a= "a", b= "a", and c= "a". The concatenation of strings a and c equals a+c= "aa". The string b

// is a substring of this string.

// In the sixth test case, one can choose a=
// "a", b= "ab", and c= "b". The concatenation of strings a and c equals a+c= "ab". The string b

// is a substring of this string.

// In the seventh test case, one can choose a=
// "ab", b= "a", and c= "ca". The concatenation of strings a and c equals a+c= "abca". The string b is a substring of this string.


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
    string s;
    cin>>s;
    bool flag=false;
    for(int i=1;i<n-1;i++){
        char to_check=s[i];
        string temp=s;
        temp[i]='1';
        unordered_set<char> charSet(temp.begin(), temp.end());
        if(charSet.find(to_check)!=charSet.end()) {flag=true;
        break;
        }
    }
    if(flag){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
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