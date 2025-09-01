class Solution {
private:
    void solve(int index,string s,vector<string>&a,vector<vector<string>>&ans){
        if(index==s.size()){
            ans.push_back(a);
            return;

        }for(int i=index;i<s.size();i++){
            if(ispal(s,index,i)){
                a.push_back(s.substr(index,i-index+1));
                solve(i+1,s,a,ans);
                a.pop_back();
            }
        }
    }
    bool ispal(string s,int start,int end){
        while(start<=end){
            if(s[start]!=s[end]) return false;
            start++;
            end--;
        }return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>a;
        solve(0,s,a,ans);
        return ans;
    }
};