class Solution {
public:
    int longestArithmetic(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MIN;
        int i=1;
        vector<pair<int,int>>end(n);
        vector<pair<int,int>>start(n);
        while(i<n){
            int star=i-1;
            int diff=nums[i]-nums[i-1];
            i++;
            while(i<n&&((nums[i]-nums[i-1])==diff)){
                i++;
            }
            int en=i-1;
            start[star]={en-star+1,diff};
            end[en]={en-star+1,diff};
            if(en-star+1<n)
            ans=max(ans,en-star+2);
            else
            return n;
        }
        i=1;
        while(i<n-1){
            int prev=nums[i-1];
            int next=nums[i+1];
            if((prev+next)%2!=0){ i++;continue;}
            if((prev+next)/2==nums[i]){ i++;continue;}
            int x=(prev+next)/2;
            int currdiff=x-nums[i-1];
            if(currdiff==end[i-1].second&&currdiff==start[i+1].second)
            ans=max(ans,end[i-1].first+start[i+1].first+1);
            if(currdiff!=end[i-1].second&&currdiff==start[i+1].second)
            ans=max(ans,1+start[i+1].first+1);
            if(currdiff==end[i-1].second&&currdiff!=start[i+1].second)
            ans=max(ans,end[i-1].first+2);
            if(i+1==n-1&&currdiff==end[i-1].second){
            ans=max(ans,end[i-1].first+2);
            }
            if(i-1==0&&currdiff==start[i+1].second){
            ans=max(ans,start[i+1].first+2);
            }
            i++;
        }
        return ans;
    }
};