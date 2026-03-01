class Solution {
public:
    int minPartitions(string n) {
        int ans=INT_MIN;
        for(int i=0;i<n.length();i++){
            ans=max(ans,n[i]-'0');
            if(ans==9) return ans;
        }
        return ans;
    }
};