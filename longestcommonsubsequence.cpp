class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int current_max=1;
        int temp=1;
        if(nums.empty())
            return 0;
        if(nums.size()==1)
            return 1;
        int counter=nums[0];
            for(int i=1;i<nums.size();i++)
            {   
                if(nums[i]==nums[i-1])
                    continue;
                else if(nums[i]==counter+1)
                {
                   temp++;
                    counter++;
                }
                else
                {   temp=1;
                    counter = nums[i];
                }
                if(temp>current_max)
                current_max=temp;
            }
            
       return current_max; 
    }
};