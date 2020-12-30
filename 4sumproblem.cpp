class Solution
{
	public:
	void findFourElements(vector<int>& nums, int target) 
	{ 
	    unordered_map<int, pair<int, int> > hash; 
	    std::vector<std::vector<int> > result;
	    for (int i = 0; i < n - 1; i++) 
	        for (int j = i + 1; j < n; j++) 
	            hash[nums[i] + nums[j]] = { i, j }; 
	    for (int i = 0; i < n - 1; i++)
	    { 
	        for (int j = i + 1; j < n; j++) 
	        { 
	            int sum = nums[i] + nums[j]; 
	            if (hash.find(X - sum) != hash.end()) 
	            { 
	                pair<int, int> p = hash[X - sum]; 
	                if (p.first != i && p.first != j && p.second != i && p.second != j) { 
	                	result.push_back({nums[i],nums[j],nums[p.first],p.second}); 
	                } 
	            } 
	        } 
	    } 
	    return result;
	} 
};