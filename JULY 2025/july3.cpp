class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int>mpp;
        int ans=-1,i=0;
        for(int j=0;j<s.size();j++){
            mpp[s[j]]++;
            while(mpp.size()>k){
                mpp[s[i]]--;
                if(mpp[s[i]]==0)mpp.erase(s[i]);
                i++;
            }
            if(mpp.size()==k)
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};
