class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size();
        int m=mana.size();
        vector<long long int>time(n,0);
        long long int start=0;
        for(int j=0;j<m;j++){
             long long int sum=0;
            for(int i=0;i<n;i++){
                time[i]=skill[i]*mana[j]+(i>0?time[i-1]:start);
                if(j<m-1)
                start=max(start,time[i]-sum*mana[j+1]);
                sum+=skill[i];
            }
            if(j==m-1)
            start+=sum*mana[m-1];
        }
        return start;
    }
};