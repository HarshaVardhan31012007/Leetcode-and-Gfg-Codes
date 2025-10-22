class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>v(n,0);
        for(auto &query:queries){
            int s=query[0];int e=query[1];
            v[s]-=1;
            if(e+1<n)
            v[e+1]+=1;
        }
        for(int i=0;i<n;i++){
            v[i]+=i>0?v[i-1]:0;
            nums[i]+=v[i];
            if(nums[i]>0)// if it is negative,As each query can contribute only 1
            //so you can exclude queries right//so for that query we take subset not including current i
            return false;
        }
        return true;
    }
};