class Solution {
  public:
    int vowelCount(string& s) {
        // code here
        int n=s.length(),ans=1;
        unordered_map<char,int> m;
        for(char x:s){ 
            if(x=='a' || x=='e' || x=='i' || x=='u' || x=='o')
            m[x]++;
        }
        if(m.size()==0) return 0;
        for(int i=1;i<=m.size();++i) 
        ans *= i;
        for(auto x:m)
        ans *= x.second;
        return ans;
    }
};
