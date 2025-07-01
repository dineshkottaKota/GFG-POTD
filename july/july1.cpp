class Solution {
  public:
    int substrCount(string &s, int k) {
        // code here
        unordered_map<char,int>mpp;
        int n=s.size();
        if(n<k)return 0;
        int cnt=0;
        int i=0,j=0;
        while(j<n){
            while(j!=i+k and j<n){
                mpp[s[j++]]++;
            }
            if(mpp.size()==k-1){
                cnt++;
            }
            mpp[s[i]]--;
            if(mpp[s[i]]==0)mpp.erase(s[i]);
            i++;
        }
        return cnt;
    }
};
