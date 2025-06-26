class Solution {
  public:
    int minValue(string &s, int k) {
        // code here
        unordered_map<char,int>mpp;
        for(char c:s) mpp[c]++;
        priority_queue<int,vector<int>>pq;
        for(auto it:mpp)pq.push(it.second);
        while(k-- and !pq.empty()){
            int top=pq.top();
            pq.pop();
            top-=1;
            if(top>0)pq.push(top);
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top()*pq.top();
            pq.pop();
        }
        return ans;
    }
};
