class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
       sort(a.begin(),a.end());
    //   int mini=INT_MAX;
    //   for(int i=0;i<a.size();i++){
    //           if(i+m-1<a.size())
    //           mini=min(mini,a[i+m-1]-a[i]);
    //   }
    //   return mini;
    int i=0;
    int j=m-1;
    int mini=INT_MAX;
    while(j<a.size()){
        mini=min(mini,a[j]-a[i]);
        i++;
        j++;
    }
    return mini;
    }
};