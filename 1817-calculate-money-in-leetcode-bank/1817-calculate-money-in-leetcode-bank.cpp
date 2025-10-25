class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int k=1,x=0,i=0;
        while(k<=n){
            if(k%7==1){
                x++;
                i=x;

            }ans+=i;
            i++;
            k++;
            

            
        }return  ans;
        
    }
};