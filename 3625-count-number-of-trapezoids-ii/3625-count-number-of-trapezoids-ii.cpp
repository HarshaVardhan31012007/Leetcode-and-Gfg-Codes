class Solution {
public:
    // double find1(vector<int>&a,vector<int>&b){
    //        if(b[0]==a[0]) return b[0];
    //        return (((b[0]-a[0])*b[1])-((b[1]-a[1])*b[0]))/(1.0*(b[0]-a[0]));
    //        //dont use b[1]-slope*b[0] as it causes some precision loss
    // }
    // double find(vector<int>&a,vector<int>&b){
    //       if(b[0]==a[0]) return INFINITY;
    //       return (b[1]-a[1])/(1.0*(b[0]-a[0]));
    // }
    // int countTrapezoids(vector<vector<int>>& points) {
    //     unordered_map<double,unordered_map<double,int>>mpp;
    //     unordered_map<long long,unordered_map<double,int>>mpp1;//mid to slope to count map no need for intercept as mid can uniquely determine line 
    //     for(int i=0;i<points.size();i++){
    //         for(int j=i+1;j<points.size();j++){
    //               double slope=find(points[i],points[j]);
    //               double intercept=find1(points[i],points[j]);
    //               mpp[slope][intercept]++;
    //               long long mid=(points[i][0]+points[j][0])*10000LL+(points[i][1]+points[j][1]);//10000 is used to unique repersent it from others whose mid x,y different but x+y same//it is like encoding of mid//otherwise you can use pair ofx,y//max sum x1+x2 is 1000+1000 it is 2000 so use more than that
    //             //for example
    //             //(x1+x2 = 1,  y1+y2 = 1001)  
    //             //mid = 1*1000 + 1001 = 2001
    //             //(x1+x2 = 2,  y1+y2 = 1)
    //             //mid = 2*1000 + 1 = 2001

    //               mpp1[mid][slope]++;
    //         }
    //     }
    //     long long ans=0;
    //     for(auto it=mpp.begin();it!=mpp.end();it++){
    //         auto &it1=it->second;//ampersand important it copies all map it increases time complexity
    //         long long sum=0;
    //         for(auto it2=it1.begin();it2!=it1.end();it2++){
    //             long long count=1LL*(it2->second);
    //             ans+=sum*count;
    //             sum+=count;
    //         }
    //     }
    //      for(auto it=mpp1.begin();it!=mpp1.end();it++){
    //         auto &it1=it->second;//ampersand important it copies all map it increases time complexity
    //         long long sum=0;
    //         for(auto it2=it1.begin();it2!=it1.end();it2++){
    //             long long count=1LL*(it2->second);
    //             ans-=sum*count;
    //             sum+=count;
    //         }
    //     }
    //     return ans;
    // }



//nested hashing may take time so use single hashing
     double find1(vector<int>&a,vector<int>&b){
           if(b[0]==a[0]) return b[0];
           return (((b[0]-a[0])*b[1])-((b[1]-a[1])*b[0]))/(1.0*(b[0]-a[0]));
           //dont use b[1]-slope*b[0] as it causes some precision loss//like for 
           //1/3=0.33333333333.........
    }
    const int inf=1e9+7;
    double find(vector<int>&a,vector<int>&b){
          if(b[0]==a[0]) return inf;
          return (b[1]-a[1])/(1.0*(b[0]-a[0]));
    }
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<double,vector<double>>mpp;
        unordered_map<long long,vector<double>>mpp1;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                  double slope=find(points[i],points[j]);
                  double intercept=find1(points[i],points[j]);
                  mpp[slope].push_back(intercept);
                  long long mid=(points[i][0]+points[j][0])*10000LL+(points[i][1]+points[j][1]);//10000 is used to unique repersent it from others whose mid x,y different but x+y same//it is like encoding of mid//otherwise you can use pair ofx,y//max sum x1+x2 is 1000+1000 it is 2000 so use more than that
                //for example
                //(x1+x2 = 1,  y1+y2 = 1001)  
                //mid = 1*1000 + 1001 = 2001
                //(x1+x2 = 2,  y1+y2 = 1)
                //mid = 2*1000 + 1 = 2001
                mpp1[mid].push_back(slope);
            }
        }
        long long ans=0;
        for(auto &[_,str]:mpp){//convention _ means we dont nedd it inside loop
              if(str.size()==1) continue;
              unordered_map<double,int>freq;
              for(auto &each:str){
                freq[each]++;
              }
              int sum=0;
              for(auto &each:freq){
                ans+=sum*each.second;
                sum+=each.second;
              }
        }
        for(auto &[_,str]:mpp1){
              if(str.size()==1) continue;
              unordered_map<double,int>freq;
              for(auto &each:str){
                freq[each]++;
              }
              int sum=0;
              for(auto &each:freq){
                ans-=sum*each.second;
                sum+=each.second;
              }
        }
        return ans;
    }
};