class Solution {
public:
   
    int rob(vector<int>& nums) {

        int n=nums.size();
        
        int prev=nums[0];
        int prev1=0;
        for(int i=1;i<n;i++){
            int pick=nums[i];
            if(i>1) pick+=prev1;
            int notpick=prev;
            int curr=max(pick,notpick);
            prev1=prev;
            prev=curr;
        }return prev;
    }
};