class Solution {
public:
    int minPartitions(string n) {
        int size=n.length();
        int ans=INT_MIN;
        for(int i=0;i<size;i++){
            ans=max(ans,n[i]-'0');
        }
        return ans;
    }
};