class Solution {
public:
    static int maximumEnergy(vector<int>& energy, int k) {
        const int n=energy.size();
        int ans=*max_element(energy.rbegin(), energy.rbegin()+k);
        for(int i=n-k-1; i>=0; i--){
            int curr=energy[i]+=energy[i+k];
            ans=max(ans, curr);
        }
        return ans;
    }
};