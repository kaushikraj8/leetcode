class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==i)
                continue;
            else
            {
                temp=i;
                break;
            }
        }
        return temp;
        
    }
};