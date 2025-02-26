class Twitter {
public:
    class tweet{
        public:
        int tweetId;
        int time;
        tweet(int id,int t):tweetId(id),time(t){}
    };
    class comp{
        public:
        bool operator()(tweet a,tweet b){
            return a.time>b.time;
        }
    };
    int time;
    Twitter() {
        time=0;
    }
    unordered_map<int,vector<tweet>>mpp;
    unordered_map<int,unordered_set<int>>mp;
    void postTweet(int userId, int tweetId) {
        mpp[userId].push_back(tweet(tweetId,time++));
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int>ans;
        priority_queue<tweet,vector<tweet>,comp>pq;
        for(auto each:mpp[userId]){
            pq.push(each);
            if(pq.size()>10)
            pq.pop();
        }
        for(auto each:mp[userId]){
            for(auto e:mpp[each]){
            pq.push(e);
            if(pq.size()>10)
            pq.pop();
            }
        }
        while(!pq.empty()){
           ans.push_back(pq.top().tweetId);
           pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mp[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mp[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */