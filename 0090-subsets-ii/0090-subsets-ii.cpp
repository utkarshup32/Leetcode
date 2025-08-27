/*class Solution {
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
};*/
class Solution {
public:
    void subsetsWithDupUtil(vector<int>& nums, int idx, vector<int>& v, vector<vector<int>>& res, set<vector<int>>& us) {
        if (idx >= nums.size()) {
            return;
        } 

        v.push_back(nums[idx]);

        auto it = us.find(v);

        if (it == us.end()) {
            res.push_back(v);
            us.insert(v);
        }
        
        subsetsWithDupUtil(nums, idx+1, v, res, us);
        v.pop_back();
        subsetsWithDupUtil(nums, idx+1, v, res, us);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<vector<int>> us;
        vector<int> v;
        res.push_back(v);
        subsetsWithDupUtil(nums, 0, v, res, us);
        return res;
    }
};