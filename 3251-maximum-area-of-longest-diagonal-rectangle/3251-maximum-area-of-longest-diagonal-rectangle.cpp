class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ans=0;
        long long root=0.0;
        for(int i=0;i<dimensions.size();i++){
            int a=dimensions[i][0];
            int b=dimensions[i][1];
            if(a*a +b*b>root){
                root =a*a +b*b;
                ans=a*b;
            }if(a*a +b*b==root){
                
                ans=max(a*b,ans);
            }    

        }
        return ans;
    }
};