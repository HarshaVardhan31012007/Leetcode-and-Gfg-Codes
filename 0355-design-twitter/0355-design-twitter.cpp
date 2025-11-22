class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>>tweets;
    unordered_map<int,unordered_set<int>>followers;
    Twitter() {
        
    }
    int time=1;
    void postTweet(int userId, int tweetId) {
       tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
         vector<pair<int,int>>v=tweets[userId];
         for(auto &each:v){
            pq.push(each);
            if(pq.size()>10)
            pq.pop();
         }
         unordered_set<int>&st=followers[userId];
         for(auto &each:st){
                vector<pair<int,int>>v1=tweets[each];
                for(auto &each:v1){
                    pq.push(each);
                    if(pq.size()>10)
                    pq.pop();
                }
         }
         vector<int>ans;
         int count=10;
         while(!pq.empty()&&count>0){
            auto &[time,id]=pq.top();
            ans.push_back(id);
            pq.pop();
            count--;
         }
         reverse(ans.begin(),ans.end());
         return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        unordered_set<int>&st=followers[followerId];
        if(st.find(followeeId)!=st.end()){
            st.erase(followeeId);
        }
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