class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        // code here
        unordered_map<int,int>mpp;
        vector<int>temp=a;
        sort(temp.begin(),temp.end());
        sort(b.begin(),b.end());
        for(auto it:temp){
            mpp[it]=upper_bound(b.begin(),b.end(),it)-b.begin();
        }
        for(int i=0;i<a.size();i++){
            a[i]=mpp[a[i]];
        }
        return a;
    }
};
