class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		int n=nums.size();
		vector<int> tem=nums;
		for(int i=0;i<nums.size();i++){
			tem.push_back(nums[i]);
		}
		vector<int> stack;
		vector<int> res(n,-1);
		for(int i=0;i<tem.size();i++){
			while(stack.size()>0 && tem[i]>tem[stack.back()]){
				res[stack.back()]=tem[i];
				stack.pop_back();
			}
			if(i<n){
				stack.push_back(i);
			}
		}
		return res;

	}
};