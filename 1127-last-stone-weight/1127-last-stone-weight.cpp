class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(auto &stone:stones)
        pq.push(stone);
        while(pq.size()>1){
            auto top=pq.top();
            pq.pop();
            auto top1=pq.top();
            pq.pop();
            if(top!=top1)
            pq.push(top-top1);
        }
        return (pq.size()==1)?pq.top():0;
    }
};