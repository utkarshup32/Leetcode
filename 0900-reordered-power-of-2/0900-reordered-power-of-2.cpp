class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<int>target=digitfreq(n);
        for(int i=0;i<=30;++i){
            int powerof2=(int)pow(2,i);
            if(equalfreq(target,digitfreq(powerof2))) return true;
        }return false;
    } vector<int> digitfreq(int n) {
        vector<int> freq(10, 0);
        while (n > 0) {
            freq[n % 10]++;
            n /= 10;
        }
        return freq;
    } bool equalfreq(const vector<int>& a, const vector<int>& b) {
        for (int i = 0; i < 10; ++i)
            if (a[i] != b[i]) return false;
        return true;
    }
};