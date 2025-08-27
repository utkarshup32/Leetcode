class Solution {
private:
    void combination(int ind,int target,vector<int>& candidates,vector<vector<int>> &ans,vector<int >ds){
        if(ind==candidates.size()){
            if(target==0) ans.push_back(ds);
            return;
        }if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            combination(ind,target-candidates[ind],candidates,ans,ds);
            ds.pop_back();
        }combination(ind+1,target,candidates,ans,ds);

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int >ds;
        combination(0,target,candidates,ans,ds);
        return ans;
    }
};