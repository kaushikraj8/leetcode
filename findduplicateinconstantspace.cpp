class Solution {
public:
    int findDuplicate(vector <int>& nums) {
        int temp;
        bool ch=0;
        for(int i=0;i<nums.size();i++)
        {if(ch==0)
        {
            temp=nums[i];
            for(int j=i+1;j<nums.size();j++)
            {   
                if(temp==nums[j])
                {   ch=1;
                    break;
                }
            }
        }
        else
        break;
        }
        return temp;
    }
};