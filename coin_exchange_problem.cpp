class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
    std::vector<int> dp(amount+1,amount+1);
    dp[0]=0;
    for (int i = 0; i < dp.size(); ++i)
    {
    	for(int coin : coins)
    	{
    		if(coin<=i)
    		{
    			if(dp[i-coin]<amount+1)
    			{
    				dp[i]=min(dp[i],dp[i-coin]+1)
    			}
    		}
    	}
    }
    return dp[amount]==amount+1?-1:dp[amount];
    }
};