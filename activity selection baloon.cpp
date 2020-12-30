class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()<=1) {
			return points.size();
        }
        int count=1;
        sort(points.begin(),points.end());
        int high=points[0][1];
        for(int i=1;i<points.size();i++) {
            if(points[i][0]<=high) {
                high=high>points[i][1]?points[i][1]:high;
            }
            else {
                count++;
                high=points[i][1];
            }
        }
        return count;
    }
};