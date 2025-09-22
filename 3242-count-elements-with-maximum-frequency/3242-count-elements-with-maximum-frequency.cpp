class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int freq[101] = {0};
        int max = 0, res = 0;
        for (int n : nums) {
            int f = ++freq[n];
            if (f > max) {
                max = f;
                res = f;
            } else if (f == max)
                res += f;
        }
        return res;
    }
};
