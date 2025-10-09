class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        // int n=skill.size();
        // int m=mana.size();
        // vector<long long int>time(n,0);
        // long long int start=0;
        // for(int j=0;j<m;j++){
        //      long long int sum=0;
        //     for(int i=0;i<n;i++){
        //         time[i]=skill[i]*mana[j]+(i>0?time[i-1]:start);
        //         if(j<m-1)
        //         start=max(start,time[i]-sum*mana[j+1]);
        //         sum+=skill[i];
        //     }
        //     if(j==m-1)
        //     start+=sum*mana[m-1];
        // }
        // return start;

         
        // int n=skill.size();
        // int m=mana.size();
        // vector<long long int>prefix(n,0);
        // prefix[0]=skill[0];
        // for(int i=1;i<n;i++){
        //     prefix[i]=(long long)skill[i]+prefix[i-1];
        // }
        // long long int start=0;
        // for(int j=0;j<m-1;j++){
        //     long long int currstart=start;
        //     for(int i=0;i<n;i++){
        //         long long int time=currstart+(prefix[i]*(long long)mana[j]);
        //         start=max(start,time-((i>0?prefix[i-1]:0)*(long long)mana[j+1]));
        //     }
        // }
        // return (long long)start+(prefix[n-1]*(long long)mana[m-1]);

        int n=skill.size();
        int m=mana.size();
        vector<long long int>prefix(n,0);
        prefix[0]=skill[0];
        for(int i=1;i<n;i++){
            prefix[i]=(long long)skill[i]+prefix[i-1];
        }
        long long int start=0;
        for(int j=0;j<m-1;j++){
            long long int currstart=start;
            start=currstart+prefix[0]*mana[j];
            for(int i=1;i<n;i++){
                long long int time=currstart+(prefix[i]*(long long)mana[j]);
                start=max(start,time-(prefix[i-1]*(long long)mana[j+1]));
            }
        }
        return (long long)start+(prefix[n-1]*(long long)mana[m-1]);
    }
};