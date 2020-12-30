class Solution {
public:
    int maxProfit(vector<int>& prices) {
            if(is_sorted(prices.begin(),prices.end()))
            {
                int si=prices.size();
                return prices[si-1]-prices[0];
            }
            int result=0;
            for(int i=0;i<prices.size();i++)
            {
                for(int j=i+1;j<prices.size()-1;j++)
                {   
                    if(prices[j]-prices[i]>result)
                        result=prices[j]-prices[i];
                    
                }
            }
        
        
    return result;

        
    }
};