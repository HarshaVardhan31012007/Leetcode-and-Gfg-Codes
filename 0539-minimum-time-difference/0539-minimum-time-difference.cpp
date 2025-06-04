class Solution {
public:
    int convert(string &k){
        int hrs=stoi(k.substr(0,2));
        int min=stoi(k.substr(3,2));
        return 60*hrs+min;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int>time;
        for(int i=0;i<timePoints.size();i++){
            time.push_back(convert(timePoints[i]));
        }
        sort(time.begin(),time.end());
        int mini=INT_MAX;
        for(int i=0;i<time.size()-1;i++){
            mini=min(mini,time[i+1]-time[i]);
        }
        mini=min(mini,1440+time[0]-time[time.size()-1]);
        return mini;
    }
};