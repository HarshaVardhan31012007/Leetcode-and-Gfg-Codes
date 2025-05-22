class Solution {
  public:
    // Function to find the maximum number ofmeetings that can
    // be performed in a meeting room.
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        vector<pair<int,int>>v;
        for(int i=0;i<start.size();i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        int count=1;
        int prevS=v[0].first;
        int prevE=v[0].second;
        for(int i=1;i<v.size();i++){
            int curS=v[i].first;
            int curE=v[i].second;
            if(prevE<curS){
            count++;
            prevS=curS;
            prevE=curE;
            }
        }
        return count;
    }
};