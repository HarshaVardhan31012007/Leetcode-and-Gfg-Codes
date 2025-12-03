// class Solution {
// public:
//     double find1(vector<int>&a,vector<int>&b){
//            if(b[0]==a[0]) return b[0];
//            return (((b[0]-a[0])*b[1])-((b[1]-a[1])*b[0]))/(1.0*(b[0]-a[0]));
//            //dont use b[1]-slope*b[0] as it causes some precision loss
//     }
//     double find(vector<int>&a,vector<int>&b){
//           if(b[0]==a[0]) return INFINITY;
//           return (b[1]-a[1])/(1.0*(b[0]-a[0]));
//     }
//     int countTrapezoids(vector<vector<int>>& points) {
//         unordered_map<double,unordered_map<double,int>>mpp;
//         unordered_map<long long,unordered_map<double,int>>mpp1;
//         for(int i=0;i<points.size();i++){
//             for(int j=i+1;j<points.size();j++){
//                   double slope=find(points[i],points[j]);
//                   double intercept=find1(points[i],points[j]);
//                   mpp[slope][intercept]++;
//                   long long mid=(points[i][0]+points[j][0])*10000LL+(points[i][1]+points[j][1]);//10000 is used to unique repersent it from others whose mid x,y different but x+y same//it is like encoding of mid//otherwise you can use pair ofx,y//max sum x1+x2 is 1000+1000 it is 2000 so use more than that
//                 //for example
//                 //(x1+x2 = 1,  y1+y2 = 1001)  
//                 //mid = 1*1000 + 1001 = 2001
//                 //(x1+x2 = 2,  y1+y2 = 1)
//                 //mid = 2*1000 + 1 = 2001

//                   mpp1[mid][slope]++;
//             }
//         }
//         long long ans=0;
//         for(auto it=mpp.begin();it!=mpp.end();it++){
//             auto it1=it->second;
//             long long sum=0;
//             for(auto it2=it1.begin();it2!=it1.end();it2++){
//                 long long count=1LL*(it2->second);
//                 ans+=sum*count;
//                 sum+=count;
//             }
//         }
//          for(auto it=mpp1.begin();it!=mpp1.end();it++){
//             auto it1=it->second;
//             long long sum=0;
//             for(auto it2=it1.begin();it2!=it1.end();it2++){
//                 long long count=1LL*(it2->second);
//                 ans-=sum*count;
//                 sum+=count;
//             }
//         }
//         return ans;
//     }
// };




class Solution {
public:
    double find1(double slope, vector<int>& b, int x1, int y1, int dx, int dy) {
        // Instead of using slope*y - x, use stable formula
        if (dx == 0) return b[0];   // vertical line: intercept = x
        return (double)(y1 * dx - x1 * dy) / dx;
    }

    double find(vector<int>& a, vector<int>& b) {
        int dx = b[0] - a[0];
        int dy = b[1] - a[1];
        if (dx == 0) return std::numeric_limits<double>::infinity();
        return (double)dy / dx;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<double, unordered_map<double,int>> mpp;
        unordered_map<long long, unordered_map<double,int>> mpp1;

        int n = points.size();

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){

                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x2 - x1, dy = y2 - y1;

                double slope = find(points[i], points[j]);
                double intercept = find1(slope, points[j], x1, y1, dx, dy);

                mpp[slope][intercept]++;

                long long mid = (long long)(x1 + x2) * 10000LL + (y1 + y2);
                mpp1[mid][slope]++;
            }
        }

        long long ans = 0;

        for (auto& it : mpp) {
            long long sum = 0;
            for (auto& it2 : it.second) {
                long long count = it2.second;
                ans += sum * count;
                sum += count;
            }
        }

        for (auto& it : mpp1) {
            long long sum = 0;
            for (auto& it2 : it.second) {
                long long count = it2.second;
                ans -= sum * count;
                sum += count;
            }
        }

        return ans;
    }
};
