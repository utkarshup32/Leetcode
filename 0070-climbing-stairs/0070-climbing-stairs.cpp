/*class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        return climbStairs(n-1)+climbStairs(n-2);
    }// runtime error
};*/
class Solution {
public:
    int climbStairs(int n){
        int prev=1;
        int prev1=1;
        if(n==0 || n==1) return 1;
        for(int i=2;i<=n;i++){
            int curr=prev+prev1;
            prev1=prev;
            prev=curr;

        }return prev;

    }
};