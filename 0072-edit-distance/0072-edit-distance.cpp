class Solution {
public:
    //Time: O(m*n), Space: O(m*n);
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<int> p(n+1, 0),c(n+1,0);
        for(int i=0;i<=n;i++){
            p[i]=i;
            
        }for(int i=1;i<=m;i++){
            c[0]=i;
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])  c[j]=p[j-1];
                else c[j]=1+min(p[j],min(c[j-1],p[j-1]));
            }p=c;
        }return p[n];
    }
    
    
};