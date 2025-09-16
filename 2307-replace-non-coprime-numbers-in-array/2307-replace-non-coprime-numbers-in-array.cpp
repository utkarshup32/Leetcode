class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stack;
        for (int num : nums) {
            while (!stack.empty()) {
                int top = stack.back();
                int g = __gcd(top, num);
                if (g == 1) {
                    break;
                }
                stack.pop_back();
                // compute LCM
                long long merged = (long long)top / g * num;
                num = (int)merged;
            }
            stack.push_back(num);
        }
        return stack;
    }
 
};