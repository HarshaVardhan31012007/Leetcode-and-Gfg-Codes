class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);pq.push(b);pq.push(c);
        int ans=0;
        // while(true){
        //     int top1=pq.top();pq.pop();
        //     int top2=pq.top();pq.pop();
        //     if(top2==0) break;
        //     top1--;top2--;
        //     ans++;
        //     pq.push(top1);pq.push(top2);
        // }
        while(pq.size()>1){
            int top1=pq.top();pq.pop();
            int top2=pq.top();pq.pop();
            top1--;top2--;ans++;
            if(top1>0)pq.push(top1);
            if(top2>0)pq.push(top2);
        }
        return ans;
    }
};