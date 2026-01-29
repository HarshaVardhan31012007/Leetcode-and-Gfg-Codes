class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n=original.size();
        vector<vector<int>>cost1(26,vector<int>(26,INT_MAX));
        for(int i=0;i<n;i++){
           cost1[original[i]-'a'][changed[i]-'a']=min(cost1[original[i]-'a'][changed[i]-'a'],cost[i]);
        }
        for(int h=0;h<26;h++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(cost1[i][h]!=INT_MAX&&cost1[h][j]!=INT_MAX)
                    cost1[i][j]=min(cost1[i][j],cost1[i][h]+cost1[h][j]);
                }
            }
        }
        long long int ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]) continue;
            if(cost1[source[i]-'a'][target[i]-'a']==INT_MAX) return -1;
            ans+=cost1[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};