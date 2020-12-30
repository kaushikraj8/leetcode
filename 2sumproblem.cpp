class Solution
{
public:
	std::vector<int> sum(std::vector<int> nums,int target)
	{
		std::unordered_map<int,int> hash;
		std::vector<int> result;
		for(int i=0;i<nums.size();i++)
		{	
			int numbertofind=target-nums[i];
			if(hash.find(numbertofind)!=nums.end())
			{
				result.push_back(hash[numbertofind]);
				result.push_back(i);
				return result;
			}
			hash[nums[i]]=i;
		}
		return result;
	}
	
};