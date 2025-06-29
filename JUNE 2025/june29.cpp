class Solution {
  public:
    bool valid(vector<int>&arr,int k, int mid){
        int count=1,sum=0;
        for(int it:arr){
            if(sum+it>mid){
                count++;
                sum=it;
            }
            else{
                sum+=it;
            }
        }
        return count<=k;
    }
    int splitArray(vector<int>& arr, int k) {
        // code here
        int l=*max_element(arr.begin(),arr.end()),r=accumulate(arr.begin(),arr.end(),0);
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            if(valid(arr,k,mid)){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
