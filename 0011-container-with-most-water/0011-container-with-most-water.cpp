class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int maxi=INT_MIN;
        while(l<r){
            if(height[l]<height[r]){
                maxi=max(maxi,height[l]*(r-l));
                l++;
            }
            else{
                maxi=max(maxi,height[r]*(r-l));
                r--;
            }
        }
        return maxi;
    }
};