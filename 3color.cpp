class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        if(n>1)
        {
        for(int i=0;i<n;)
	    {
		    if(nums[i]==0)
		    {   
               
                  nums.insert(nums.begin(),0);
                  nums.erase(nums.begin()+i+1);
                i++;
            }
		    else if(nums[i]==2)
		    {
			    nums.push_back(nums[i]);
			    nums.erase(nums.begin()+i);
                n--;
                
            }
            else if(nums[i]==1)
            {
                i++;
            }
	}
        }
    }
};