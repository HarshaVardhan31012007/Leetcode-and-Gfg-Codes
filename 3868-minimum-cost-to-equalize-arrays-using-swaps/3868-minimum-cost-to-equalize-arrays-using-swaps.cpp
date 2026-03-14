class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq1;
        unordered_map<int,int>freq2;
        unordered_set<int>st;
        for(int i=0;i<nums1.size();i++){
           freq1[nums1[i]]++;freq2[nums2[i]]++;
           st.insert(nums1[i]);st.insert(nums2[i]);
        }
        int a=0;int b=0;
        for(auto &el:st){
           if(freq1[el]>freq2[el]){
                int diff=freq1[el]-freq2[el];
                if(diff&1) return -1;
                a+=(freq1[el]-freq2[el])/2;
           }
           else if(freq2[el]>freq1[el]){
                int diff=freq2[el]-freq1[el];
                if(diff&1) return -1;
                b+=(freq2[el]-freq1[el])/2;
           }
        }
        return max(a,b);
    }
};