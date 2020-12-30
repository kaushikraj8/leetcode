class Solution {
public:
	bool palindrome(string s) 
	{ 
	    bool flag = 1; 
	    string s2 ;
	    s2=s; 
	    reverse(s.begin(),s.end()); 
	    for (int i = 0; i < s.size(); i++) 
	        if (s[i] != s2[i]) { 
	            flag = 0; 
	            break; 
	        } 
        return flag;
	} 
    string longestPalindrome(string s) {
        if(s.size()<2)
            return s;
    	string largest;
    	int maxi=0;
        for(int i=0;i<s.size();i++)
        {
        	for(int j=s.size()-1;j>=i;j--)
        	{
        		if(s[i]==s[j] )
        			if(palindrome(s.substr(i,j)))
        				if(j-i+1>maxi)
        				{
        					maxi=j-i+1;
        					largest=s.substr(i,j);
        				}
        	}
        }
        return largest;
    }
};