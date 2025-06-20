class Solution {
  public:
    bool validgroup(vector<int> &arr, int k) {
        // icode here
        int n=arr.size();
        if(n%k)return false;
        map<int,int>mp;
        for(int it:arr)mp[it]++;
        for(auto it:mp){
            int num=it.first;
            int cnt=it.second;
            if(cnt>0){
                for(int i=0;i<k;i++){
                    if(mp[num+i]<cnt)return false;
                    mp[num+i]-=cnt;
                }
            }
        }
        return true;
    }
};
