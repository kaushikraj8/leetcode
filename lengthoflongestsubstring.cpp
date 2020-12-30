class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>hash;
        int start=0;
        int result=0;
        for(int i=0;i<=s.size();i++)
        {
            if(i==s.size())
                result=max(result,i-start);
            if(hash.find(s[i])==hash.end())
                {hash[s[i]]=i;continue;}
            else{
                result=max(result,i-start);
                start=max(start,hash[s[i]]+1);
                hash[s[i]]=i;
            }
        }
        return result;
    }
};