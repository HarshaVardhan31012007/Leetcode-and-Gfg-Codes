class Solution {
public:
    int maxProduct(vector<int>& nums) {
    //    int p=1;
    //    int ans=INT_MIN;
    //    int maxi1=INT_MIN;
    //    for(int i=0;i<nums.size();i++){
    //       p=p*nums[i];
    //       ans=max(ans,p);
    //       if(p<0){
    //         if(maxi1!=INT_MIN)
    //         ans=max(ans,p/maxi1);
    //         maxi1=max(maxi1,p);
    //       }
    //       if(p==0){
    //         p=1;
    //         maxi1=INT_MIN;
    //       }
    //    }
    //    return ans;



        int n=nums.size();
        int p=1;int p1=1;
        int i=0;int j=n-1;
        int maxi=INT_MIN;
        while(i<n&&j>=0){
            p=p*nums[i];
            p1=p1*nums[j];
            maxi=max(maxi,p);
            maxi=max(maxi,p1);
            if(p==0) p=1;
            if(p1==0) p1=1;
            i++;
            j--;
        }
        return maxi;
    }
};