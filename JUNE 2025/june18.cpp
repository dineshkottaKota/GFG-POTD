class Solution {
  public:
    bool palindrome(string s, int l, int r){
        while(l<=r){
            if(s[l]!=s[r])return false;
            l++;r--;
        }
        return true;
    }
    vector<vector<string>>ans;
    void solve(string &s, int ind, vector<string>v){
        if(ind==s.size()){
            ans.push_back(v);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(palindrome(s,ind, i)){
                v.push_back(s.substr(ind,i-ind+1));
                solve(s,i+1,v);
                v.pop_back();
            }
        }
        
    }
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<string>v;
        solve(s,0,v);
        return ans;
    }
};
