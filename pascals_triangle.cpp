#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        res.resize(numRows);
        if(numRows==0) return res;
        for(int i=0; i<numRows; i++){
            res[i].resize(i+1);  
            res[i][0]=res[i][i]=1;             
            for(int j=1; j<i; j++) 
                res[i][j]=res[i-1][j]+res[i-1][j-1];
        }
        return res;
    }
};
int main()
{
	Solution a;
	vector<vector<int> > result;
	result=a.generate(4);
	for(int i=0;i<result.size();i++)
	{
		for(int j=0;j<result[i].size();j++)
		cout<<result[i][j];
		cout<<endl;
	}
	return 0;
}
