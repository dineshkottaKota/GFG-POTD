class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int,int>mpp;
        int ans=0,i=0;
        for(int j=0;j<n;j++){
            mpp[arr[j]]++;
            while(mpp.size()>k){
                mpp[arr[i]]--;
                if(mpp[arr[i]]==0)mpp.erase(arr[i]);
                i++;
            }
            ans+=(j-i+1);
        }
        return ans;
    }
};
