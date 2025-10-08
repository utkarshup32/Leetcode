class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> success1; 
        sort(potions.begin(),potions.end());
        for(int s:spells){
            
            long long minint=(success+s-1)/s;
            auto low=lower_bound(potions.begin(),potions.end(),minint);
            int k=distance(low,potions.end());
               
            success1.push_back(k);
        }return success1; 
    }
};