bool cmp(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(), cmp);
        int n=points.size();
        int begin=0;
        int count=0;
        for(int i=0; i<n; i++){
            if(count==0 || points[i][0]> begin){
                count++;
                begin=points[i][1];
            }
        }
        return count;
    }
};
