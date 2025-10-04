class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        // double ans=INT_MIN;
        // for(int i=0;i<points.size();i++){
        //     for(int j=i+1;j<points.size();j++){
        //         for(int k=j+1;k<points.size();k++){
        //             ans=max(ans,0.5*abs(points[i][0]*(points[j][1]-points[k][1])+points[j][0]*(points[k][1]-points[i][1])+points[k][0]*(points[i][1]-points[j][1])));
        //         }
        //     }
        // }
        // return ans;


          double ans=INT_MIN;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                for(int k=j+1;k<points.size();k++){
                    double a=hypot(points[i][0]-points[j][0],points[i][1]-points[j][1]);
                    double b=hypot(points[j][0]-points[k][0],points[j][1]-points[k][1]);
                    double c=hypot(points[k][0]-points[i][0],points[k][1]-points[i][1]);
                    double s=(a+b+c)/2;
                    ans=max(ans,sqrt(s*(s-a)*(s-b)*(s-c)));
                }
            }
        }
        return ans;
    }
};