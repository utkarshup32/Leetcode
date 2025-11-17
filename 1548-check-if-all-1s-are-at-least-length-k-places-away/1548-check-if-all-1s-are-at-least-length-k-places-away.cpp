class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                for(int j=i+1;j<=i+k;j++){
                    if(j<nums.size() && nums[j]==1) return false;
                }i+=k;
            }
        }return true;
    }
};