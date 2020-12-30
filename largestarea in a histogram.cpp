class Solution{
public:
	int largestRectangleArea(std::vector<int>& heights){
		if(heights.size()==0)
		{
			return 0;
		}
		if(heights.size()==1)
		{
			return heights[0];
		}
		stack<int> st;
		int maxresult=0;
		st.push(0);
		for(int i=1;i<heights.size();i++)
		{
			int curr=heights[i];
			if(curr>=heights[st.top()])
			{
				st.push(i);
			}
			else {
				while(!st.empty() && curr<heights[st.top()])
				{
                    
					int temp=heights[st.top()];
                    st.pop();
					if(st.empty())
					{
						maxresult=max(maxresult,temp*i);
					}
					else{
						maxresult=max(maxresult,temp*(i-st.top()-1));
					}
				}
				st.push(i);
			}
		}
	if(!st.empty())
	{
		int i=heights.size();
		while(!st.empty())
				{
					int temp=heights[st.top()];
            st.pop();
					if(st.empty())
					{
						maxresult=max(maxresult,temp*i);
					}
					else
					{
						maxresult=max(maxresult,temp*(i-st.top()-1));
					}
				}
	}
        return maxresult;
}
};