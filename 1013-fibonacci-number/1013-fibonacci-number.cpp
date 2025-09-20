class Solution {
public:
    int fib(int n) {
        if (n == 0) return n;
        int prev= 1;
        int prev1=0;
        for(int i=2;i<=n;i++){
            int curr=prev+prev1;
            prev1=prev;
            prev=curr;
        }
        return prev;
    }
};