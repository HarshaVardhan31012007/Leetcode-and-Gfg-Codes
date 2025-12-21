class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        // unordered_map<int,int>tfreq;
        // unordered_map<int,int>bfreq;
        // int bad=0;
        // int maxi=INT_MIN;
        // for(int i=0;i<nums.size();i++){
        //     if(nums[i]==forbidden[i]){
        //         bfreq[nums[i]]++;
        //         maxi=max(maxi,bfreq[nums[i]]);
        //         bad++;
        //     }
        //     tfreq[nums[i]]++;
        //     tfreq[forbidden[i]]++;
        //     if(tfreq[nums[i]]>nums.size()||tfreq[forbidden[i]]>nums.size()) return -1;//that means swap of nums[i] all is possiblke somehow with some element
        // }
        // return max(maxi,(bad+1)/2);


        unordered_map<int,int>tfreq;
        unordered_map<int,int>bfreq;
        int bad=0;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==forbidden[i]){
                bfreq[nums[i]]++;
                bad++;
            }
            tfreq[nums[i]]++;
            tfreq[forbidden[i]]++;
        }
        priority_queue<int>pq;
        for(auto it=bfreq.begin();it!=bfreq.end();it++){
            pq.push(it->second);
            if(tfreq[it->first]>nums.size())
            return -1;
        }
        int ans=0;
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            a=a-b;
            ans+=b;
            if(a>0)
            pq.push(a);
        }
        if(!pq.empty())
        ans+=pq.top();
        return ans;
    }
};