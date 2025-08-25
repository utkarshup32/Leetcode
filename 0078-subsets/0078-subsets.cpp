class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        int no=1 << n; 
        vector<vector<int>> sub(no);
        for(int i=0;i<no;i++){
            
            for(int j=0;j<n;j++){

                if(i & (1<<j)) sub[i].push_back(nums[j]);
            }
        }return sub;
    }
};