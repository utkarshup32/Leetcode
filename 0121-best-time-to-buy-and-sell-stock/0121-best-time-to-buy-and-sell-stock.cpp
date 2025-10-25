class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxpr=0;
        int n=prices.size();
        for(int i=0;i<n;i++){
            int cost=prices[i]-mini;
            maxpr=max(maxpr,cost);
            mini=min(mini,prices[i]);
        }return maxpr;
    }
};