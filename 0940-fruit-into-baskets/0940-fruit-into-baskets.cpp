class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int num1 = -1, frq1 = 0;  
        int num2 = -1, frq2 = 0;

        int l=0,r=0;
        int n = fruits.size();
        int ans = 0;

        while(r<n){
            int cur = fruits[r];

            if(num1==-1){ num1 = cur; frq1=1; }
            else if(num1==cur){frq1++;}
            else if(num2==-1){ num2 = cur; frq2=1; }
            else if(num2==cur){frq2++;}


            if(cur != num1 and cur != num2){
                ans = max({frq1+frq2 , ans});

                int last = fruits[r-1];

                // empty bucket untill we have a free bucket
                while(frq1 > 0 and frq2 > 0){
                    int prev = fruits[l];

                    if(prev == num1){frq1--;}
                    else if(prev == num2){frq2--;}
                    l++;
                }

                // put new unique fruit in available empty bucket
                if(frq1 == 0){
                    num1 = cur;
                    frq1 = 1;
                }
                else if(frq2 == 0){
                    num2 = cur;
                    frq2 = 1;
                }
            }

            r++;
        }

        ans = max({frq1+frq2 , ans});

        return ans;
    }
};