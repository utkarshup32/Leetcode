class Solution {
private:
    void solve(vector<int>& nums,int n,vector<vector<int>>& per,vector<int>&ds, vector<int> freq){
        if(ds.size()==n){
            per.push_back(ds);
            return;
        }for(int i=0;i<n;i++){
            if(!freq[i]){
                freq[i]=1;
                ds.push_back(nums[i]);
                solve(nums,n,per,ds,freq);
                ds.pop_back();
                freq[i]=0;


            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> per;
        vector<int>ds;
        int n=nums.size();
        vector<int> freq(n,0);
        solve(nums,n,per,ds,freq);
        return per;
    }
};