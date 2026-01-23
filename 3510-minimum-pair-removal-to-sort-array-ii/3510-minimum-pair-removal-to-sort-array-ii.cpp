class Solution {
public:
    #define ll long long
    int minimumPairRemoval(vector<int>& nums) {
       int n=nums.size();
       vector<ll>arr(n,0);
       for(int i=0;i<n;i++)
       arr[i]=nums[i];
       vector<int>next(n,-1);
       vector<int>prev(n,-1);
       set<pair<ll,int>>st;
       int badpairs=0;
       for(int i=0;i<n;i++){
          next[i]=i+1;
          prev[i]=i-1;
          if(i<n-1){
            st.insert({arr[i]+arr[i+1],i});
            if(arr[i]>arr[i+1])
            badpairs++;
          } 
       }
       int ans=0;
       while(badpairs>0){
           auto it=st.begin();

           long long asum=it->first;
           int first=it->second;
           int second=next[first];

           int first_left=prev[first];
           int second_right=next[second];
           st.erase(it);

           if(arr[first]>arr[second])
           badpairs--;
           if(first_left!=-1&&arr[first_left]>arr[first]&&arr[first_left]<=asum){
              badpairs--;
           }
           else if(first_left!=-1&&arr[first_left]<=arr[first]&&arr[first_left]>asum){
            badpairs++;
           }
           if(second_right!=n&&arr[second]<=arr[second_right]&&asum>arr[second_right]){
              badpairs++;
           }
           else if(second_right!=n&&arr[second]>arr[second_right]&&asum<=arr[second_right]){
             badpairs--;
           }
           next[first]=second_right;
           if(second_right!=n)
           prev[second_right]=first;
           if(first_left!=-1)
           st.erase({arr[first_left]+arr[first],first_left});
           if(second_right!=n)
           st.erase({arr[second]+arr[second_right],second});
           if(first_left!=-1)
           st.insert({arr[first_left]+asum,first_left});
           if(second_right!=n)
           st.insert({arr[second_right]+asum,first});
           arr[first]+=arr[second];
           ans++;
       }
       return ans;
    }
};