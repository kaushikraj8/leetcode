class Solution {
public:
    set<vector>k;
    vector<vector> combinationSum(vector& a, int t) {
        vectorkk;
        int i,j,n=a.size();
        for(i=0;i<n;i++)
        {
            kk.push_back(a[i]);
            find(a,t-a[i],i,kk,a.size());
            kk.pop_back();
        }
        vector<vector>ans;
        for(auto kk:k)
        {
            ans.push_back(kk);
        }
        return ans;
        }
        void find(vector&a,int t,int i,vector&kk,int n){
            if(t==0)
            {
                k.insert(kk);
                return;
            }
            if(t<0 || i==n)
            {
                return ;
            }
            for(;i<n;i++)
            {
                kk.push_back(a[i]);
                find(a,t-a[i],i,kk,n);
                kk.pop_back();
            }
        return;
    }
};