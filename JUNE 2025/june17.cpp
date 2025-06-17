class Solution {
  public:
    int minimumCoins(vector<int>& arr, int k) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        vector<int>pre(n+1,0);
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+arr[i];
        }
        for(int i=0;i<n;i++){
            int target=arr[i];
            int l=i,r=n;
            while(l<r){
                int mid=(l+r)/2;
                if(arr[mid]<=target+k)
                l=mid+1;
                else
                r=mid;
            }
            int j=l;
            int cnt=pre[i];
            if(j<n)
            cnt+=pre[n]-pre[j]-(n-j)*(target+k);
            mini=min(mini,cnt);
        }
        return mini;     
    }
};
