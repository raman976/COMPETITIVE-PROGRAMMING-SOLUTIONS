class Solution {
public:
    int helper(string & s,int index,vector<int>& v){
        if(index==s.size()) return 1;
        if(s[index]=='0') return 0;
        if(v[index]!=-1) return v[index];
        int ways=helper(s,index+1,v);
        if(index+1<s.size()){
            string p=s.substr(index,2);
            if(p[0]!='0' && p>="10" && p<="26"){
                ways+=helper(s,index+2,v);
            }
        }
        v[index]=ways;
        return ways;
    }
    int numDecodings(string s) {
    vector<int> v(s.size(),-1);
        return helper(s,0,v);
    }
};