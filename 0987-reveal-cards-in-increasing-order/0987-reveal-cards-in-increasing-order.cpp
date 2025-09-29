class Solution {
public:
    
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        vector<int>ans(deck.size());
        int j=0;
        queue<int>q;
        for(int i=0;i<deck.size();i++){
            q.push(i);
        }
        while(!q.empty()){
           int front=q.front();
           q.pop();
           int nextfront=-1;
           if(!q.empty()){
                q.push(q.front());
                q.pop();
           }
           ans[front]=deck[j++];
        }
        return ans;
    }
};