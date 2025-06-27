class Solution {
  public:
    int getCount(int n) {
        // code here
        if(n==1)return 10;
        vector<vector<int>>moves={
            {0, 8},       
            {1, 2, 4},    
            {2, 1, 3, 5}, 
            {3, 2, 6},    
            {4, 1, 5, 7}, 
            {5, 2, 4, 6, 8}, 
            {6, 3, 5, 9}, 
            {7, 4, 8},    
            {8, 5, 7, 9, 0}, 
            {9, 6, 8}    
        };
        vector<long long>prev(10,1),curr(10);
        for(int i=2;i<=n;i++){
            fill(curr.begin(),curr.end(),0);
            for(int j=0;j<=9;j++){
                for(int k: moves[j]){
                    curr[j]+=prev[k];
                }
            }
            prev=curr;
        }
        long long total=0;
        for(int i=0;i<=9;i++)total+=prev[i];
        return (int)total;
    }
};
