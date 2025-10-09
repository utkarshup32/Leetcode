class Solution {
public:
    int findways(int n,int tar,vector<int>& nums){
        vector<int>prev(tar+1,0),curr(tar+1,0);
        if(nums[0]==0) prev[0]=2;
        else prev[0]=1;
        
        if(nums[0]!=0 && nums[0]<=tar) prev[nums[0]]=1;
        for(int ind=1;ind<n;ind++){
            for(int sum=0;sum<=tar;sum++){
                int nottake=prev[sum];
                int take=0;
                if(nums[ind]<=sum ) take=prev[sum-nums[ind]];

                curr[sum]=nottake+take;
            }prev=curr;
        }return prev[tar];

    }
    int count(int n,int target,vector<int>& arr){
        int totsum=0;
        for(int i=0;i<n;i++) totsum+=arr[i];
        if((totsum-target<0)||(totsum-target)%2) return false;
        return findways(n,(totsum-target)/2,arr);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return count(nums.size(),target,nums);
    }
};