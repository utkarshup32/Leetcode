class Solution {
private:
    void solve(int ind,vector<int>& nums,int n,vector<vector<int>>& per){
        if(ind==n){
            per.push_back(nums);
            return;
        }for(int i=ind;i<n;i++){
            
            swap(nums[i],nums[ind]) ;  
            solve(ind+1,nums,n,per);
            swap(nums[i],nums[ind]) ;     
            


            
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> per;
        
        int n=nums.size();
        
        solve(0,nums,n,per);
        return per;
    }
};