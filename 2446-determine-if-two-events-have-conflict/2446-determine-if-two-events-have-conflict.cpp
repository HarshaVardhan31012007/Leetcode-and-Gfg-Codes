class Solution {
public:
   // pair<int,int>get(vector<string>&e){
    //     int hr1=stoi(e[0].substr(0,2));
    //     int min1=stoi(e[0].substr(3,2));
    //     int time1=hr1*60+min1;

    // }
    bool haveConflict(vector<string>& e1, vector<string>& e2) {
        // pair<int,int>minEvent1=get(event1);
        // pair<int,int>minEvent2=get(event2);
        if(e1[1]>e2[1]) swap(e1,e2);
        return e1[1]>=e2[0];
    }
};