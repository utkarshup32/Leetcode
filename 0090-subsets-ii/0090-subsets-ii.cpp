class Solution {
public:
    void backtrack(int ind, vector<int>& nums, vector<int>& subset,vector<vector<int>> &ans){
        ans.push_back(subset);
        for(int i=ind; i<nums.size(); i++){
            if(i > ind && nums[i] == nums[i-1])continue;
            subset.push_back(nums[i]);
            backtrack(i+1,nums,subset,ans);
            subset.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(0, nums, subset, ans);
        return ans;
    }
};