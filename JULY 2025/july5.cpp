class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int maxi=0;
        for (int i=0;i<arr.size()-1;i++) {
            int score=arr[i]+arr[i+1];
            maxi=max(maxi,score);
        }
        return maxi;
    }
};
