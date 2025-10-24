class Solution {
public:
  
    long long generate(long long n, long long current, long long remaining, vector<long long>& count) {
        
        if (remaining == 0) {
            if (current > n) {
                
                for (int d = 1; d <= 9; ++d) {
                    if (count[d] > 0 && count[d] != d) return 0;
                }
                return current;
            }
            return 0;
        }

        long long result = 0;

       
        for (int d = 1; d <= 9 && result == 0; ++d) {

         
            if (count[d] < d && d - count[d] <= remaining) {
                count[d]++;
                result = generate(n, current * 10 + d, remaining - 1, count);
                count[d]--;
            }
        }

        return result;
    }

    int nextBeautifulNumber(int n) {
        string num = to_string(n);
        long long length = num.size();
        vector<long long> count(10, 0);

      
        long long result = generate(n, 0, length, count);

       
        count.assign(10, 0);
        long long nextLenResult = generate(0, 0, length + 1, count);
        if (result == 0) result = nextLenResult;

        return static_cast<int>(result);
    }
};