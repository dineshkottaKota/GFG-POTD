class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int n=arr.size();
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int>mpp;
        while(i<=j){
            while(mpp.size()<=2 and j<n){
                if(mpp.find(arr[j])==mpp.end() and mpp.size()==2)break;
                mpp[arr[j++]]++;
            }
            ans=max(ans,j-i);
            mpp[arr[i]]--;
            if(mpp[arr[i]]==0)mpp.erase(arr[i]);
            i++;
        }
        return ans;
    }
};
