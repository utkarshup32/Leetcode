class Solution {
public:
    string addBinary(string a, string b) {
        
        int i=a.size()-1;
        int j=b.size()-1;
         
         string ans="";
         int Carry=0;

         while( i>=0 || j>=0 || Carry){
            int Sum=Carry;
            
             if(i>=0) Sum+=(a[i--]-'0');
             if(j>=0) Sum+=(b[j--]-'0');
              
            ans=char((Sum%2)+'0') + ans;
            Carry=Sum/2;
         }

         return ans;
    }
};