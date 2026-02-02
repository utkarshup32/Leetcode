class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        long long ans=nums[0];
        multiset<int> small,large;
        long long sum=0;
        int m=k-2;
        auto balance=[&](){
            while(small.size()<m && !large.empty()){
                auto it=large.begin();
                sum+=*it;
                small.insert(*it);
                large.erase(it);
            }
            while(small.size()>m){
                auto it=prev(small.end());
                sum-=*it;
                small.erase(it);
                large.insert(*it);
            }
        };
        auto add=[&](int x){
            if(small.size()<m){
                small.insert(x);
                sum+=x;
            }else{
                auto it=prev(small.end());
                if(*it > x){
                    large.insert(*it);
                    sum+=(x-*it);
                    small.erase(it);
                    small.insert(x);
                }else{
                    large.insert(x);
                }
            }
            balance();
        };
        auto remove=[&](int x){
            if(large.count(x)){
                large.erase(large.find(x));
            }else{
                sum-=x;
                small.erase(small.find(x));
            }
            balance();
        };

        int j=1,i=1;
        while (i < j + dist) add(nums[i++]);
        long long mn=1e18;
        while(i<nums.size()){
            mn=min(mn,sum+nums[i]);
            if(!large.empty())
            mn=min(mn,sum+*large.begin());
            remove(nums[j]);
            add(nums[i]);
            j++;
            i++;
        }
        return ans+mn;
    }
};