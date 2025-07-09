class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=arr.size();
        stack<pair<int,int>>st;
        vector<int>l(n),r(n);
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st.empty() and st.top().first>=arr[i]){
                cnt+=st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            l[i]=cnt;
        }
        while (!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            int cnt=1;
            while(!st.empty() and st.top().first>arr[i]){
                cnt+=st.top().second;
                st.pop();
            }
            st.push({arr[i],cnt});
            r[i]=cnt;
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i]*l[i]*r[i];
        }
        return sum;
    }
};
