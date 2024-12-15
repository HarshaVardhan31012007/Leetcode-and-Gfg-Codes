class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        //   int maxi=INT_MIN;
        // for(int i=0;i<n;i++){
        //    for(int j=i+1;j<n;j++){
        //     int h=min(height[i],height[j]);
        //     int curr=(j-i)*h;
        //     maxi=max(maxi,curr);
        //    }
        // }
        // return maxi;

        //method 2
        int i=0;
        int j=n-1;
        int ans=INT_MIN;
        while(i<j){
            int w=j-i;
            int h=min(height[i],height[j]);
            int v=w*h;
            ans=max(ans,v);
            (height[i]<height[j])?i++:j--;
        }
        return ans;
    }
};