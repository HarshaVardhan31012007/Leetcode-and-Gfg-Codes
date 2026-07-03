class MyCalendarTwo {
public:
    vector<vector<int>>intervals;
    vector<vector<int>>overlappedIntervals;
    MyCalendarTwo() {
        
    }
    bool isoverlapping(int s1,int e1,int s2,int e2){
        return max(s1,s2)<min(e1,e2);
    }
    vector<int>getoverlappingInterval(int s1,int e1,int s2,int e2){
        return {max(s1,s2),min(e1,e2)};
    }
    bool book(int startTime, int endTime) {
        for(int i=0;i<overlappedIntervals.size();i++){
            if(isoverlapping(overlappedIntervals[i][0],overlappedIntervals[i][1],startTime,endTime)){
                return false;
            }
        }
        for(int i=0;i<intervals.size();i++){
            if(isoverlapping(intervals[i][0],intervals[i][1],startTime,endTime)){
                overlappedIntervals.push_back(getoverlappingInterval(intervals[i][0],intervals[i][1],startTime,endTime));
            }
        }
        intervals.push_back({startTime,endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */