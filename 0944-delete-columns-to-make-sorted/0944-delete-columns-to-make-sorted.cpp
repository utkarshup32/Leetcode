class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        const int n=strs.size(), m=strs[0].size();
        bitset<1000> remove=0;
        for(int i=0; i<n-1; i++){
            string& cur=strs[i];
            string& nxt=strs[i+1];
            for(int j=0; j<m; j++){
                if(remove[j]==0 & cur[j]>nxt[j])
                    remove[j]=1;
            } 
        }
        return remove.count();
    }
};