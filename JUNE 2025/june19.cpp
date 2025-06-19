class Solution {
  public:
    string caseSort(string& s) {
        // code here
        string uc,lc;
        for(auto it:s){
            if(it>='a' and it<='z')lc+=it;
            else uc+=it;
        }
        sort(uc.begin(),uc.end());
        sort(lc.begin(),lc.end());
        int i=0,j=0;
        string ans;
        for(auto it:s){
            if(it>='a' and it<='z')
            ans+=lc[i++];
            else
            ans+=uc[j++];
        }
        return ans;
    }
};
