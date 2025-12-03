// E. Sink
// time limit per test
// 3 seconds
// memory limit per test
// 256 megabytes

// You are given a grid containing n
// rows and m columns. Every cell (i,j), located in the i-th row and j-th column, has a positive integer value associated with it ai,j

// . Two cells are adjacent if and only if they share a common side in the grid.

// You are allowed to construct holes at cells of your choice. A cell (x,y)
// is a sink if and only if it has a hole, or is adjacent to a sink (i,j) with ax,y≥ai,j

// .

// The beauty of a grid is defined as the minimum number of holes you need to construct so that every cell becomes a sink.

// You have to determine the beauty of this grid.

// You are also given q

// queries.

// In a query, you are given three positive integers r
// , c, and x. The current value of cell (r,c) is decreased by x

// . After each query, determine the beauty of the grid considering no holes have been constructed yet.

// Note that queries are cumulative, so the effects of each query carry on to future queries.

// It is guaranteed that after every query the value of each cell will remain positive.
// Input

// Each test contains multiple test cases. The first line contains the number of test cases t
// (1≤t≤104

// ). The description of the test cases follows.

// The first line of each test case contains two integers n
// and m (1≤n,m≤2⋅105, 1≤n⋅m≤2⋅105

// ) — the number of rows and columns, respectively.

// The following n
// lines contain m integers each; the j-th element in the i-th line ai,j is the number written in the j-th cell of the i-th row (1≤ai,j≤109

// ).

// The next line contains a single integer q
// (0≤q≤2⋅105

// ) — the number of queries.

// The following q
// lines contain 3 integers each — r,c, and x (1≤r≤n,1≤c≤m,1≤x<109

// ).

// It is guaranteed that the sum of n⋅m
// and the sum of q over all test cases does not exceed 2⋅105

// .

// It is guaranteed that after every query the value of each cell will remain positive.
// Output

// For each test case, print q+1

// lines.

// On the first line print the beauty of the initial grid.

// Also, after each query, print the beauty of the current grid.
// Example
// Input
// Copy

// 3
// 1 4
// 1 2 3 5
// 2
// 1 4 1
// 1 3 2
// 3 3
// 5 1 6
// 2 9 3
// 7 4 8
// 3
// 2 2 1
// 2 2 7
// 3 3 7
// 3 4
// 10 10 10 10
// 10 10 10 10
// 10 10 11 10
// 5
// 3 3 5
// 2 2 5
// 2 4 5
// 2 3 5
// 1 1 9

// Output
// Copy

// 1
// 1
// 2
// 4
// 4
// 1
// 2
// 1
// 1
// 2
// 3
// 1
// 2

// Note

// For the first test case:

//     Initially, we can create a hole at cell (1,1

// ).
// After the first query, we can create a hole at cell (1,1
// ).
// After the second query, we can create holes at cells (1,1
// ) and (1,3

//     ). 

// For the second test case:

//     Initially, we can create holes at cells (1,2

// ), (2,1), (2,3), and (3,2
// ).
// After the first query, we can create holes at cells (1,2
// ), (2,1), (2,3), and (3,2
// ).
// After the second query, we can create a hole at cell (2,2
// ).
// After the third query, we can create holes at cells (2,2
// ) and (3,3). 




#include<bits/stdc++.h>
using namespace std;
 
const int N = 400005;
int parent[N],siz[N],important[N],val[N];
 
void make_set(int v,int x) {
    parent[v] = v;siz[v] = 1;important[v] = 1;val[v] = x;
}
 
int find_set(int v) {
    if (v == parent[v])return v;
    return parent[v] = find_set(parent[v]);
}
 
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (siz[a] < siz[b])swap(a, b);
        parent[b] = a;
        siz[a] += siz[b];
        important[a] = min(important[a],important[b]);
    }
}
 
int n,m;
 
vector<array<int,2>> neighbours(int r,int c){
    vector<array<int,2>> v;
    if(r)v.push_back({r-1,c});
    if(r+1 < n)v.push_back({r+1,c});
    if(c)v.push_back({r,c-1});
    if(c+1 < m)v.push_back({r,c+1});
    return v;
}
 
void solve()
{
    cin >> n >> m;
    vector<vector<int>> a(n,vector<int>(m));  // latest value of a given cell
    vector<vector<int>> ls(n,vector<int>(m)); // latest node created for a given cell
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            cin >> a[i][j];
            ls[i][j] = m*i+j;
        }
    }
 
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            make_set(m*i+j,a[i][j]);
            for(auto &[p,q] : neighbours(i,j)){
                if(a[p][q] < a[i][j])important[m*i+j] = 0;
            }      
        }
    }
 
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            for(auto &[p,q] : neighbours(i,j)){
                if(a[p][q] == a[i][j])union_sets(m*i+j,m*p+q);
            }
        }
    }
 
    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            if(parent[m*i+j] == m*i+j)ans+=important[m*i+j];
        }
    }
    
    cout << ans << "\n";
 
    int q;
    cin >> q;
    int nd = n*m;
 
    for(int i = 0;i < q;i++){
        int r,c,x;
        cin >> r >> c >> x;
        r--;c--;
        x = a[r][c] - x;
        set<int> s;
 
        int mn = INT_MAX;
        for(auto &[p,q] : neighbours(r,c)){
            s.insert(find_set(ls[p][q]));
            mn = min(mn,a[p][q]);
        }
        s.insert(find_set(ls[r][c]));
 
        for(auto &y : s){
            ans -= important[y];
        }
 
        for(auto &y : s){
            if(val[y] > x)important[y] = 0;
        }
 
        make_set(nd,x);
        if(mn < x)important[nd] = 0;
        else important[nd] = 1;
 
 
        for(auto &y : s){
            if(val[y] == x){
                union_sets(y,nd);
            }
        }
 
        a[r][c] = x;
        ls[r][c] = nd++;
 
        s.clear();
        for(auto &[p,q] : neighbours(r,c)){
            s.insert(find_set(ls[p][q]));
        }
        s.insert(find_set(ls[r][c]));
 
        for(auto &y : s){
            ans += important[y];
        }
 
        cout << ans << "\n";
    }
 
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}