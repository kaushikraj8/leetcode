class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxcount=0;
        int local=0;
        for(auto num:nums){
            local=num==1?local+1:0;
            maxcount=max(local,maxcount);
                
        }
        return maxcount;
    }
};