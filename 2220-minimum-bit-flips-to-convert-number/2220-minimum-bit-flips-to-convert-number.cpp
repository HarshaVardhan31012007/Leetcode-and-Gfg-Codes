class Solution {
public:
    int find(int x){
        int c=0;
        while(x>0){
            c++;
            x=(x&(x-1));
        }
        return c;
    }
    int minBitFlips(int start, int goal) {
        // int ans=0;
        // while(start>0||goal>0){
        //     int a=(start>0?start%2:0);
        //     int b=(goal>0?goal%2:0);
        //     if(a!=b) ans++;
        //     if(start>0)
        //     start=start/2;
        //     if(goal>0)
        //     goal=goal/2;
        // }
        // return ans;



        int x=start^goal;
        //int count=__builtin_popcount(x);
        int count=find(x);
        return count;
    }
};