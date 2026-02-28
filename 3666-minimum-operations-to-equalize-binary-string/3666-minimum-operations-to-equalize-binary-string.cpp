class Solution {
public:
    int minOperations(string s, int k) {
        int n=s.length();
        int start=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') start++;
        }
        if(start==0) return 0;
        queue<int>q;
        vector<int>operations(n+1,-1);
        q.push(start);
        operations[start]=0;
        set<int>odd;
        set<int>even;
        for(int i=0;i<=n;i++){
            if(i==start) continue;
            if(i&1) odd.insert(i);
            else even.insert(i);
        }
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int minc=front+k-2*min(front,k);
            int maxc=front+k-2*max(0,k-n+front);
            set<int>&currSet=((minc&1)?odd:even);
            auto it=currSet.lower_bound(minc);
            while(it!=currSet.end()&&(*it)<=maxc){
                operations[(*it)]=operations[front]+1;
                if((*it)==0) return operations[*it];
                q.push(*it);
                it=currSet.erase(it);
            }
        }
        return -1;
    }
};