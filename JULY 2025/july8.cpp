class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        stack<int>st;
        int n=arr.size();
        if(n==0)return {};
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++)
        mpp[arr[i]]++;
        vector<int>ans(n,-1);
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() and mpp[arr[i]]>=mpp[st.top()]){
                st.pop();
            }
            if(!st.empty())ans[i]=st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};
