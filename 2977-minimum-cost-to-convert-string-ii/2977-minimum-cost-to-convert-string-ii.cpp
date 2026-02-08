class Solution {
public:
    typedef long long ll;
    set<ll>validLengths;
    unordered_map<string,list<pair<string,ll>>>adjList;
    vector<string>original1;
    vector<string>changed1;
    unordered_map<string,unordered_map<string,ll>>dpsp;//dp for shortest path
    vector<ll>dp;
    ll dijkstra(string &curr,string &next){
        if(dpsp[curr].count(next)) return dpsp[curr][next];
        priority_queue<pair<ll,string>,vector<pair<ll,string>>,greater<>>pq;
        unordered_map<string,ll>dist;
        dist[curr]=0;
        pq.push({0,curr});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(top.second==next) return dpsp[curr][next]=top.first;
            if(dist.count(top.second)&&top.first>dist[top.second]) continue;
            for(auto &adj:adjList[top.second]){
                if(!dist.count(adj.first)||top.first+adj.second<dist[adj.first]){
                     dist[adj.first]=top.first+adj.second;
                     pq.push({dist[adj.first],adj.first});
                }
            }
        }
        if(dist.count(next))
        return dpsp[curr][next]=dist[next];
        else
        return dpsp[curr][next]=LLONG_MAX;
    }
    ll solve(string &source,string &target,int i){
        if(i>=source.length()) return 0;
        if(dp[i]!=-1) return dp[i];
        ll curr=LLONG_MAX;
        if(source[i]==target[i]){
            curr=min(curr,solve(source,target,i+1));
        }
        for(auto &len:validLengths){
            if(i+len>source.length()) continue;
            string cur=source.substr(i,len);
            string next=target.substr(i,len);
            if(!adjList.count(cur)) continue;
            ll dist=dijkstra(cur,next);
            if(dist==LLONG_MAX) continue;
            ll reccall=solve(source,target,i+len);
            if(reccall!=LLONG_MAX){
                ll temp=dist+reccall;
                curr=min(curr,temp);
            }
        }
        return dp[i]=curr;
    }
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        dp.assign(source.length(),-1);
        for(auto &each:original){
            validLengths.insert(each.length());
        }
        for(int i=0;i<original.size();i++){
            adjList[original[i]].push_back({changed[i],cost[i]});
        }
        original1=original;
        changed1=changed;
        long long ans=solve(source,target,0);
        return ans==LLONG_MAX?-1:ans;
    }
};