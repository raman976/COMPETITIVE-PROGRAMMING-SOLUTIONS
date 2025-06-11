#include <iostream>
using namespace std;
#include <vector>
#include <set>
#include <map>
#include<iomanip>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <cctype>
int main() {
    int n;
    cin>>n;
    for(int p=0;p<n;p++){
        int a;
    cin>>a;
    bitset<32> b(a);
    // cout<<b<<"\n";
    string res=b.to_string();
    int ones=0;
    for(int i=0;i<res.size();i++){
        if(res[i]=='1'){
            ones+=1;
        }
    }
    // cout<<ones<<"\n";
    int sum=0;
    for(int i=0;i<ones;i++){
        sum+=pow(2,i);
    }
    cout<<sum<<"\n";
    }
    
}