
class Solution {
public:
    class Info{
       public:
       int data;
       int r;
       int c;
       Info(int val,int x,int y){
        this->data=val;
        this->r=x;
        this->c=y;
       }
    };
    class compare{
        public:
        bool operator()(Info *a,Info *b){
            return a->data>b->data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Info*,vector<Info*>,compare>pq;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i][0]);
            mini=min(mini,nums[i][0]);
            pq.push(new Info(nums[i][0],i,0));
        }
        int ans_start=mini;
        int ans_end=maxi;
        while(!pq.empty()){
            Info *top=pq.top();
            pq.pop();
            mini=top->data;
            if(maxi-mini<ans_end-ans_start){
                ans_end=maxi;
                ans_start=mini;
            }
            if(top->c+1<nums[top->r].size()){
                maxi=max(maxi,nums[top->r][top->c+1]);
                pq.push(new Info(nums[top->r][top->c+1],top->r,top->c+1));
            }
            else
            break;
        }
        vector<int>ans;
        ans.push_back(ans_start);
        ans.push_back(ans_end);
        return ans;
    }
};