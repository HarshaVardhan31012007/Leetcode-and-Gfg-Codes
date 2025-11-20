class Solution {
public:
    typedef vector<int>vec;
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // typedef vector<int>vec;
       auto lambda=[](vec &a,vec &b){
          if(a[1]!=b[1])
            return a[1]<b[1];
            return a[0]>b[0];
       };
       sort(intervals.begin(),intervals.end(),lambda);
       int n=intervals.size();
       int result=0;
       int first=-1;
       int second=-1;
       for(int i=0;i<n;i++){
          int l=intervals[i][0];
          int r=intervals[i][1];
          if(l<=first) continue;
          if(l>second){
            result+=2;
            first=r-1;
            second=r;
          }
          else{//l<=second
            result+=1;
            first=second;
            second=r;
          }
       }
       return result;
    }
};