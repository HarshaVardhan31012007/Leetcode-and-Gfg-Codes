class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        while(start>0||goal>0){
            int a=(start>0?start%2:0);
            int b=(goal>0?goal%2:0);
            if(a!=b) ans++;
            if(start>0)
            start=start/2;
            if(goal>0)
            goal=goal/2;
        }
        return ans;
    }
};