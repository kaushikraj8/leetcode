class Solution {
public:
    int maxSubArray(vector<int>& nums) {
       int max_current=nums[0],max_global=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            max_current=max(nums[i],nums[i]+max_current);
            if(max_current>max_global)
            {
                max_global=max_current;
            }
        }
        return max_global;
        
    }
};